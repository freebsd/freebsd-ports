PORTNAME=	wifi-firmware-${FWDRV}-kmod
PORTVERSION=	${FWDRV_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for the ${FWDRV} (${FLAVOR}) WiFi NIC driver
WWW?=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/${FWSUBDIR}

FWDRV_VERSION?=	0
FWDRV?=		base

LICENSE_NAME?=	firmware license (${FWDRV})
LICENSE_FILE?=	${WRKSRC}/${FLAVOR}/${LICENSE}
LICENSE_PERMS?=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

EXTRACT_SUFX=
DISTURL_SUFFIX?=	?h=${PORTVERSION}

# Sanity checks
.if !defined(FWDRV) || !defined(FWSUBDIR) || !defined(FWSUBS) || \
	!defined(FWDRV_VERSION) || !defined(LICENSE) || \
	!defined(DISTFILES_${FWDRV}) || !defined(DISTFILES_${FWDRV}_lic) || \
	!defined(BASEDIR) || !defined(WHENCE_REGEX)
IGNORE=	is a metaport or misconfigured child port; there is nothing to build
.endif

FILESDIR=	${BASEDIR}/files

# Split things into the full package (driver name) and more specific flavors.
FLAVORS=	${FWDRV} \
		${FWSUBS}

# What a kludge.... thanks https://docs.freebsd.org/en/books/porters-handbook/flavors/ !
FLAVOR?=	${FLAVORS:[1]}

# Generate the conflicts list.
.for f in ${FWSUBS}
${FWDRV}_CONFLICTS_INSTALL+=	${PORTNAME}-${f}
${f}_PKGNAMESUFFIX=		-${f}
${f}_CONFLICTS_INSTALL=		${PORTNAME}
.endfor

DISTFILES_FLAVOR:=	${DISTFILES_${FLAVOR}}
DISTFILES_FLAVOR_lic:=	${DISTFILES_${FLAVOR}_lic}

DISTFILES=	\
	${DISTFILES_FLAVOR} \
	${DISTFILES_FLAVOR_lic} \
	${LICENSE}${DISTURL_SUFFIX} \
	WHENCE${DISTURL_SUFFIX}

DIST_SUBDIR=	linux-firmware/${FWDRV}fw
EXTRACT_ONLY=

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	LinuxKPI driver only available for these architectures

USES=		kmod uidfix

post-extract:
	@${MKDIR} ${WRKSRC}/${FLAVOR}/fw
	# Deal with supplementary licenses files.
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${LICENSE}${DISTURL_SUFFIX} ${WRKSRC}/${FLAVOR}/${LICENSE}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/WHENCE${DISTURL_SUFFIX} ${WRKSRC}/${FLAVOR}/WHENCE.in
	@${SED} -e "s@%%XXX%%@${WHENCE_REGEX:Q}@g" ${FILESDIR}/WHENCE.awk.in > ${WRKSRC}/${FLAVOR}/WHENCE.awk
	@${AWK} -f ${WRKSRC}/${FLAVOR}/WHENCE.awk ${WRKSRC}/${FLAVOR}/WHENCE.in > ${WRKSRC}/${FLAVOR}/WHENCE
	# Prepare toplevel Makefile and Makefile.inc.
	@${ECHO_CMD} "SUBDIR=" > ${WRKSRC}/${FLAVOR}/Makefile
	@${SED} -e "s@%%FWDRV%%@${FWDRV}@g" \
	    -e "s@%%FWSUBDIR%%@${FWSUBDIR}@g" \
	    ${FILESDIR}/Makefile.inc.in > ${WRKSRC}/${FLAVOR}/Makefile.inc
.for _f in ${DISTFILES_FLAVOR}
	# We remove '.' and '-' as well as '/' as they don't work well in loader.conf.
	@${MKDIR} ${WRKSRC}/${FLAVOR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}
	# Create subdir (firmware file) Makefile.
	@${ECHO_CMD} "FWNAME=${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:T}" > ${WRKSRC}/${FLAVOR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
.if (${_f:H:C,^[^/]*,,1:C,^/,,} != "")
	@${ECHO_CMD} "FWSUBSUBDIR=${_f:H:C,^[^/]*,,1:C,^/,,}" >> ${WRKSRC}/${FLAVOR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
.endif
	# XXX-BZ recover firmware versions later again from somewhere?  Pain to keep track though, else use 0 or ${FWDRV_VERSION}?
	@${ECHO_CMD} "VERSION=0" >> ${WRKSRC}/${FLAVOR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
	@${ECHO_CMD} '.include <bsd.kmod.mk>' >> ${WRKSRC}/${FLAVOR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
	# Add subdir to top-level Makefile.
	@${ECHO_CMD} "SUBDIR+=${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}" >> ${WRKSRC}/${FLAVOR}/Makefile
	# Create firmware source directory and copy in distfile.
	@${MKDIR} ${WRKSRC}/${FLAVOR}/fw/${_f:H}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/${FLAVOR}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@}
.endfor
	@${ECHO_CMD} '.include <bsd.subdir.mk>' >> ${WRKSRC}/${FLAVOR}/Makefile
	# Copy in additional licenses files.
.for _f in ${DISTFILES_FLAVOR_lic}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/${FLAVOR}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

# Internal hack we should probably upstream.
# Add WHENCE file next to license where it makes sense despite not being a license.
_USES_stage+=	881:post-install-license
post-install-license:
	${INSTALL_DATA} ${WRKSRC}/${FLAVOR}/WHENCE ${STAGEDIR}${_LICENSE_DIR}/
.for _f in ${DISTFILES_FLAVOR_lic}
	${INSTALL_DATA} ${WRKSRC}/${FLAVOR}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g} \
		${STAGEDIR}${_LICENSE_DIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

.include <bsd.port.pre.mk>

MAKE_ENV+=	FWSRCDIR=${WRKSRC}/${FLAVOR}/fw
MAKE_FLAGS+=	-C ${WRKSRC}/${FLAVOR}

# Add firmware files to plist.
.for _f in ${DISTFILES_FLAVOR}
PLIST_FILES+=	${KMODDIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}.ko
.endfor
# Record extra licenses files in plist.
PLIST_FILES+=	${_LICENSE_DIR}/WHENCE
.for _f in ${DISTFILES_FLAVOR_lic}
PLIST_FILES+=	${_LICENSE_DIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

.include <bsd.port.post.mk>

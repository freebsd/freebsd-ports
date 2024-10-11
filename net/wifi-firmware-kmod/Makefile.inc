PORTNAME=	wifi-firmware-${FWDRV}-kmod
PORTVERSION=	${FWDRV_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://ams.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://dfw.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://nyc.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://sin.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for the ${FWDRV} (${FLAVOR}) WiFi NIC driver
WWW?=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/${FWSUBDIR}

FWDRV_VERSION?=	0
FWDRV?=		base

LICENSE_NAME?=	firmware license (${FWDRV})
LICENSE_PERMS?=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

EXTRACT_SUFX=
DISTURL_SUFFIX?=	?h=${PORTVERSION}

# Sanity checks
.if !defined(FWDRV) || !defined(FWSUBDIR) || !defined(FWSUBS) || \
	!defined(FWDRV_VERSION) || \
	!defined(LICENSE_NAME) || !defined(LICENSE_FILE) || \
	!defined(DISTFILES_${FWDRV}) || !defined(DISTFILES_${FWDRV}_lic) || \
	!defined(BASEDIR) || !defined(WHENCE_REGEX)
IGNORE=	is a metaport or misconfigured child port; there is nothing to build
.endif

FILESDIR=	${BASEDIR}/files

LICENSE_COMB=	multi
LICENSE=	primary whence

# Port primary license.
LICENSE_FILE_primary=	${WRKSRC}/${LICENSE_FILE}
LICENSE_NAME_primary=	${LICENSE_NAME}
LICENSE_PERMS_primary=	${LICENSE_PERMS}

# Add WHENCE file next to license where it makes sense despite not being a license.
LICENSE_NAME_whence=	Origin and licensing information for linux-firmware files
LICENSE_FILE_whence=	${WRKSRC}/WHENCE
LICENSE_PERMS_whence=	${LICENSE_PERMS}
#PLIST_FILES+=	${_LICENSE_DIR}/WHENCE

# Add extra license files.
.if "${DISTFILES_${FLAVOR}_lic}"
.for _n in ${DISTFILES_${FLAVOR}_lic:range}
LICENSE+=			extra${_n}
LICENSE_FILE_extra${_n}=	${WRKSRC}/lic/${DISTFILES_${FLAVOR}_lic:[${_n}]:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
LICENSE_NAME_extra${_n}=	${LICENSE_NAME} (extra fw license)
LICENSE_PERMS_extra${_n}=	${LICENSE_PERMS}
.endfor
.endif

PLIST=		${WRKDIR}/PLIST

# Split things into the full package (driver name) and more specific flavors.
FLAVORS=	${FWDRV} \
		${FWSUBS}

# Generate the conflicts list.
.for f in ${FWSUBS}
${FWDRV}_CONFLICTS_INSTALL+=	${PORTNAME}-${f}
${f}_PKGNAMESUFFIX=		-${f}
${f}_CONFLICTS_INSTALL=		${PORTNAME}
.endfor

DISTFILES=	${DISTFILES_${FLAVOR}} \
		${DISTFILES_${FLAVOR}_lic} \
		${LICENSE_FILE}${DISTURL_SUFFIX} \
		WHENCE${DISTURL_SUFFIX}

DIST_SUBDIR=	linux-firmware/${FWDRV}fw
EXTRACT_ONLY=

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	LinuxKPI driver only available for these architectures

USES=		uidfix
# We do not need that anymore for the modern build but making it conditional on
# OSVERSION seems to not add the _USES_install bits from kmod.mk.
USES+=		kmod

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 1500014) || (${OSVERSION} < 1500000 && ${OSVERSION} >= 1402000)
# src.git main 479905a1ed26c54ef29cdff65cf25f7feade654b (stable/14 2ca7b03d6275)
# allows direct loading of firmware files.  For anything before that we still need
# to create kernel modules.  We need to write a PLIST file so we can then simply use
# COPYTREE_SHARE with adjusted permissions to copy the files over.
BOOTFWDIR?=	/boot/firmware
_SHAREMODE=	0444
NO_BUILD=	yes
.else
MAKE_ENV+=	FWSRCDIR=${WRKSRC}/fw
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/fw
	@${MKDIR} ${WRKSRC}/lic
	# Deal with supplementary licenses files.
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${LICENSE_FILE}${DISTURL_SUFFIX} ${WRKSRC}/${LICENSE_FILE}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/WHENCE${DISTURL_SUFFIX} ${WRKSRC}/WHENCE.in
	@${SED} -e "s@%%XXX%%@${WHENCE_REGEX:Q}@g" ${FILESDIR}/WHENCE.awk.in > ${WRKSRC}/WHENCE.awk
	@${AWK} -f ${WRKSRC}/WHENCE.awk ${WRKSRC}/WHENCE.in > ${WRKSRC}/WHENCE
################################################################################
.if (${OSVERSION} >= 1500014) || (${OSVERSION} < 1500000 && ${OSVERSION} >= 1402000)
.for _f in ${DISTFILES_${FLAVOR}}
	# Create firmware source directory and copy in distfile.
	@${MKDIR} ${WRKSRC}/fw/${_f:H}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@}
	@${ECHO_CMD} ${BOOTFWDIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@} >> ${PLIST}.tmp
.endfor
	(cd ${WRKSRC}/fw/ && ${FIND} . -type d -mindepth 1 | \
	    ${AWK} -vB="${BOOTFWDIR}/" '{ sub("^./", "@dir "B); print; }') >> ${PLIST}.tmp
	# Remove possibly duplicate @dir entries
	@${SORT} -u ${PLIST}.tmp > ${PLIST}
.else
################################################################################
# Build kernel modules.
	# Prepare toplevel Makefile and Makefile.inc.
	@${ECHO_CMD} "SUBDIR=" > ${WRKSRC}/Makefile
	@${SED} -e "s@%%FWDRV%%@${FWDRV}@g" \
	    -e "s@%%FWSUBDIR%%@${FWSUBDIR}@g" \
	    ${FILESDIR}/Makefile.inc.in > ${WRKSRC}/Makefile.inc
.for _f in ${DISTFILES_${FLAVOR}}
	# We remove '.' and '-' as well as '/' as they don't work well in loader.conf.
	@${MKDIR} ${WRKSRC}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}
	# Create subdir (firmware file) Makefile.
	@${ECHO_CMD} "FWNAME=${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:T}" > ${WRKSRC}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
.if (${_f:H:C,^[^/]*,,1:C,^/,,} != "")
	@${ECHO_CMD} "FWSUBSUBDIR=${_f:H:C,^[^/]*,,1:C,^/,,}" >> ${WRKSRC}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
.endif
	# XXX-BZ recover firmware versions later again from somewhere?  Pain to keep track though, else use 0 or ${FWDRV_VERSION}?
	@${ECHO_CMD} "VERSION=0" >> ${WRKSRC}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
	@${ECHO_CMD} '.include <bsd.kmod.mk>' >> ${WRKSRC}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}/Makefile
	# Add subdir to top-level Makefile.
	@${ECHO_CMD} "SUBDIR+=${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}" >> ${WRKSRC}/Makefile
	# Create firmware source directory and copy in distfile.
	@${MKDIR} ${WRKSRC}/fw/${_f:H}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@}
	@${ECHO_CMD} ${KMODDIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}.ko >> ${PLIST}
.endfor
	@${ECHO_CMD} '.include <bsd.subdir.mk>' >> ${WRKSRC}/Makefile
################################################################################
.endif
	# Copy in additional licenses files.
.for _f in ${DISTFILES_${FLAVOR}_lic}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/lic/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

.if (${OSVERSION} >= 1500014) || (${OSVERSION} < 1500000 && ${OSVERSION} >= 1402000)
do-install:
	(cd ${WRKSRC}/fw/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${BOOTFWDIR})
.endif

.include <bsd.port.post.mk>

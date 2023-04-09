PORTNAME=	wifi-firmware-${FWDRV}-kmod
PORTVERSION=	${FWDRV_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/
MASTER_SITES+=	LOCAL/bz:mkbuild

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for ${FWDRV} ${FLAVOR} WiFi NIC
WWW?=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/${FWSUBDIR}

LICENSE_NAME?=	firmware license (${FWDRV})
LICENSE_FILE?=	${WRKSRC}/${LICENSE}
LICENSE_PERMS?=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

EXTRACT_SUFX=
DISTURL_SUFFIX=	?h=${PORTVERSION}

# Sanity checks
.if !defined(FWDRV) || !defined(FWSUBDIR) || !defined(FWSUBS) || \
	!defined(FWDRV_VERSION) || !defined(LICENSE) || \
	!defined(DISTFILES_fw) || !defined(DISTFILES_lic)
IGNORE=	is a metaport or misconfigured child port; there is nothing to build
.endif

# Split things up in case we decide to make this flavors once we add support for more drivers.
DISTFILES=	\
	${DISTFILES_fw} \
	${DISTFILES_lic} \
	${LICENSE}${DISTURL_SUFFIX} \
	WHENCE${DISTURL_SUFFIX} \
	modules_${FWDRV}fw_${PORTVERSION}.tar.gz:mkbuild

DIST_SUBDIR=	linux-firmware/${FWDRV}fw
EXTRACT_ONLY=	modules_${FWDRV}fw_${PORTVERSION}.tar.gz

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	LinuxKPI driver only available for these architectures

USES=		kmod uidfix

post-extract:
	@${MV} ${WRKDIR}/${FWDRV}fw ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${LICENSE}${DISTURL_SUFFIX} ${WRKSRC}/${LICENSE}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/WHENCE${DISTURL_SUFFIX} ${WRKSRC}/WHENCE.in
	@${AWK} -f ${WRKSRC}/WHENCE.awk ${WRKSRC}/WHENCE.in > ${WRKSRC}/WHENCE
	@${MKDIR} ${WRKSRC}/fw
.for _f in ${DISTFILES_fw}
	@${MKDIR} ${WRKSRC}/fw/${_f:H}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@}
.endfor
.for _f in ${DISTFILES_lic}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

# Internal hack we should probably upstream.
# Add WHENCE file next to license where it makes sense despite not being a license.
_USES_stage+=	881:post-install-license
post-install-license:
	${INSTALL_DATA} ${WRKSRC}/WHENCE ${STAGEDIR}${_LICENSE_DIR}/
.for _f in ${DISTFILES_lic}
	${INSTALL_DATA} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g} \
		${STAGEDIR}${_LICENSE_DIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

.include <bsd.port.pre.mk>

MAKE_ENV+=	FWSRCDIR=${WRKSRC}/fw/${FWSUBDIR}
MAKE_FLAGS+=	-C ${WRKSRC}/${FLAVOR}

# Add firmware files.
.for _f in ${DISTFILES_fw}
PLIST_FILES+=	${KMODDIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,.,_,g:S,-,_,g:S,/,_,g}.ko
.endfor
# Record extra license files.
PLIST_FILES+=	${_LICENSE_DIR}/WHENCE
.for _f in ${DISTFILES_lic}
PLIST_FILES+=	${_LICENSE_DIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

.include <bsd.port.post.mk>

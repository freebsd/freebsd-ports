PORTNAME=	vieb
DISTVERSION=	12.4.0
PORTREVISION=	0
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/Jelmerro/Vieb/releases/download/${DISTVERSION}/ \
		LOCAL/nivit/${PORTNAME}/:images
PKGNAMEPREFIX=	linux-
DISTFILES=	vieb-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-images-${DISTVERSION}${EXTRACT_SUFX}:images

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Vim Inspired Electron Browser (Linux version)
WWW=		https://vieb.dev/

LICENSE=	AGPLv3 BSD3CLAUSE CC-BY-2.5 CC-BY-3.0 GPLv3+ LGPL21 MIT MPL11
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	pulseaudio:audio/pulseaudio

USES=		desktop-file-utils linux:rl9
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk ca-certificates cups-libs dbuslibs devtools gtk3 imageformats-libs \
		libdrm nss opus

DATADIR=	${PREFIX}/share/${PKGBASE}

NO_BUILD=	yes
SUB_FILES=	${PKGBASE}
SUB_LIST=	LINUXBASE=${LINUXBASE}

STRIP_CMD=	${LINUXBASE}/usr/bin/strip
STRIP_FILES=	chrome-sandbox libvulkan.so.1

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
			"-not ( -regex \./LICENSE.* )")
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGBASE} \
		${STAGEDIR}${LOCALBASE}/bin/${PKGBASE}
	${INSTALL_DATA} ${FILESDIR}/${PKGBASE}.desktop \
		${STAGEDIR}${DESKTOPDIR}/
	(cd ${STAGEDIR}${DATADIR} && \
		${STRIP_CMD} ${STRIP_FILES})
.for size in 16 32 48 64 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	cd ${WRKDIR}/${PORTNAME}-images-${DISTVERSION} && \
	${INSTALL_DATA} icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKDIR}/${PORTNAME}-images-${DISTVERSION} && \
	${INSTALL_DATA} ${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>

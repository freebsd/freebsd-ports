PORTNAME=	freetube
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.8-beta
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	https://github.com/FreeTubeApp/FreeTube/releases/download/${DISTVERSIONFULL}/ \
		LOCAL/nivit/${PKGNAMEPREFIX}${PORTNAME}/:icons
PKGNAMEPREFIX=	linux-
DISTFILES=	freetube-${DISTVERSION}-linux-x64-portable.zip \
		${PKGNAMEPREFIX}${PORTNAME}-icons-0.1.3.zip:icons

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	The Private YouTube Client (Linux version)
WWW=		https://freetubeapp.io/

LICENSE=	AGPLv3 BSD3CLAUSE LGPL21 MIT MPL11
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	pulseaudio:audio/pulseaudio

USES=		linux:rl9 zip
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk cups-libs dbuslibs devtools gtk3 imageformats-libs libdrm nss opus

DATADIR=	${PREFIX}/share/${PKGBASE}

BUNDLE_LIBS=	yes
NO_BUILD=	yes

SUB_FILES=	${PKGBASE} ${PKGBASE}.desktop
SUB_LIST=	LINUXBASE=${LINUXBASE}

NO_WRKSUBDIR=	yes

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
			"-not ( -regex \./LICENSE.* -or -regex \./icons.* )")
	(cd ${WRKSRC}/icons && \
		${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share/icons)
	${INSTALL_DATA} ${WRKDIR}/${PKGBASE}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGBASE} ${STAGEDIR}${LOCALBASE}/bin/${PKGBASE}
	(cd ${STAGEDIR}${DATADIR} && \
		${STRIP_CMD} chrome-sandbox libvulkan.so.1)

.include <bsd.port.mk>

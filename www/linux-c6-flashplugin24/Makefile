# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	flashplugin
PORTVERSION=	24.0.0.170
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://fpdownload.macromedia.com/pub/labs/flashruntimes/flashplayer/linux32/ \
		LOCAL/tijl/${DIST_SUBDIR}
PKGNAMEPREFIX?=	linux-c6-
PKGNAMESUFFIX=	24
DISTFILES=	flash_player_npapi_linux.i386.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin (beta)

ONLY_FOR_ARCHS=	amd64 i386
USES?=		linux:c6
USE_LINUX=	alsalib alsa-plugins-oss curl dri gtk2 nspr nss

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=
USES+=		cpe webplugin:linux
CPE_VENDOR=	adobe
CPE_PRODUCT=	flash_player
WEBPLUGIN_FILES=libflashplayer.so

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^NotShowIn=KDE/d' \
		${WRKSRC}/usr/share/applications/flash-player-properties.desktop

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/libflashplayer.so ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/flash-player-properties ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/flash-player-properties.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>

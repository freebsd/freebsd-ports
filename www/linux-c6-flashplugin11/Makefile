# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	flashplugin
PORTVERSION=	11.2r202.644
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/pdc/${PORTVERSION:S/r/./}/:plugin \
		LOCAL/nox:suplib
PKGNAMEPREFIX?=	linux-c6-
DISTFILES=	install_flash_player_11_linux.i386.tar.gz:plugin
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USES?=		linux:c6
USE_LINUX=	curl cyrus-sasl2 gdkpixbuf2 gtk2 nspr nss

RESTRICTED=	Redistribution not allowed
RESTRICTED_FILES=	${DISTFILES:Nlinux-f10-flashsupport*:C/:[^:]+$//}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=
USES+=		cpe webplugin:linux
WEBPLUGIN_FILES=	libflashplayer.so

OPTIONS_DEFINE=	ALSA
OPTIONS_SUB=	yes

ALSA_DESC=	ALSA audio output (broken, needs lemul)
ALSA_USE=	LINUX=alsalib,alsa-plugins-oss
ALSA_USE_OFF?=	LINUX=openssl-compat
ALSA_DISTFILES_OFF=	linux-f10-flashsupport-9.0.1.i386.tar.gz:suplib
ALSA_PLIST_SUB_OFF=	LINUXBASE="${LINUXBASE}"

CPE_VENDOR=	adobe
CPE_PRODUCT=	flash_player

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^NotShowIn=KDE/d' \
		${WRKSRC}/usr/share/applications/flash-player-properties.desktop

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/libflashplayer.so ${STAGEDIR}${WEBPLUGIN_DIR}
.if ! ${PORT_OPTIONS:MALSA}
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/lib
	${INSTALL_LIB} ${WRKSRC}/libflashsupport.so ${STAGEDIR}${LINUXBASE}/usr/lib
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/flash-player-properties ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/flash-player-properties.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>

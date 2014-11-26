# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	flashplugin
PORTVERSION=	11.2r202.418
PORTREVISION=	2
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/pdc/${PORTVERSION:S/r/./}/
PKGNAMEPREFIX=	linux-${USE_LINUX}-
DISTFILES=	install_flash_player_11_linux.i386.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

RUN_DEPENDS+=	linux-${USE_LINUX}-alsa-lib>=1.0.22_2:${PORTSDIR}/audio/linux-c6-alsa-lib

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	c6
USE_LINUX_APPS=	alsalib alsa-plugins-oss curl cyrus-sasl2 \
		gtk2 nspr nss # libssh2 openldap
WANT_GNOME=	yes

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		webplugin:linux desktop-file-utils cpe
WEBPLUGIN_FILES=	libflashplayer.so

OPTIONS_DEFINE=	GNOME
GNOME_DESC=	include gnome support for .desktop file

CPE_VENDOR=	adobe
CPE_PRODUCT=	flash_player

OPTIONS_SUB=	yes
PLIST_SUB=	LINUXBASE="${LINUXBASE}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USES+=		desktop-file-utils
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e '/^NotShowIn=KDE/d' ${WRKDIR}/usr/share/applications/flash-player-properties.desktop

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR} ${STAGEDIR}${LINUXBASE}/usr/lib
	${INSTALL_LIB} ${WRKDIR}/libflashplayer.so ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/flash-player-properties ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/usr/share/applications/flash-player-properties.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKDIR}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>

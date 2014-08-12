# Created by: Naoki Tsurutani
# $FreeBSD: head/www/linux-f10-flashplugin11/Makefile 342741 2014-02-05 15:56:41Z eadler $

PORTNAME=	flashplugin
PORTVERSION=	11.2r202.346
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/pdc/${PORTVERSION:C/r/\./}/
DISTFILES=	install_flash_player_11_linux.i386.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_LINUX_APPS= alsalib alsa-plugins-oss openssl curl cyrus-sasl2 \
		libssh2 nspr nss openldap gtk2
WANT_GNOME=	yes

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		webplugin:linux
WEBPLUGIN_FILES=	libflashplayer.so

OPTIONS_DEFINE=	GNOME
GNOME_DESC=	include gnome support for .desktop file

OPTIONS_SUB=	yes
PLIST_SUB+=RESETPREFIX=${PREFIX}

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

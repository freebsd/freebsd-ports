# New ports collection makefile for:	www/linux-f10-flashplugin10
# Date created:				2009-06-26
# Whom:					bsam
# Based on:				www/linux-f8-flashplugin10 by nox@
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	10.3r183.10
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/current/:plugin \
		ftp://ftp.ipt.ru/pub/download/:suplib \
		LOCAL/nox:suplib
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	install_flash_player_10_linux.tar.gz:plugin \
		linux-f10-flashsupport-9.0.1.i386.tar.gz:suplib
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_LINUX_APPS=	openssl curl cyrus-sasl2 libssh2 nspr nss openldap gtk2
WANT_GNOME=	yes

RESTRICTED=	Redistribution not allowed
RESTRICTED_FILES=	${DISTFILES:Nlinux-f10-flashsupport*:C/:[^:]+$//}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so

CONFLICTS=	linux-flashplugin-7* linux-flashplugin-9* linux-f8-flashplugin10-*

OPTIONS=	GNOME "include gnome support for .desktop file" Off

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_GNOME)
INSTALLS_ICONS=	yes
USE_GNOME=	desktopfileutils
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e '/^NotShowIn=KDE/d' ${WRKDIR}/usr/share/applications/flash-player-properties.desktop

post-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/libflashsupport.so ${LINUXBASE}/usr/lib
	@${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/flash-player-properties ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKDIR}/usr/share/applications/flash-player-properties.desktop ${DESKTOPDIR}
	@(cd ${WRKDIR}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${PREFIX}/share/icons)
	-@update-desktop-database

.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.post.mk>

# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mplayerplug-in
PORTVERSION=	3.55
PORTREVISION=	4
DISTVERSIONSUFFIX=	-1.rh9.rf
CATEGORIES=	www multimedia
MASTER_SITES=	CENKES http://apt.sw.be/packages/mplayerplug-in/ \
		ftp://fr2.rpmfind.net/linux/dag/redhat/9/en/i386/dag/RPMS/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embed MPlayer into browser

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USES=		webplugin:linux
NO_BUILD=	yes
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	atk gtk2 pango xorglibs
PREFIX?=	${LOCALBASE}
SRC_DISTFILES=
DIST_SUBDIR=   rpm
WEBPLUGIN_NAME=	#
WEBPLUGIN_FILES=	${PLUGINS_EXT:S/^/${PORTNAME}/}
PLUGINS_EXT=	.so .xpt -dvx.so -dvx.xpt -qt.so -qt.xpt -rm.so -rm.xpt -wmp.so -wmp.xpt
PLIST_FILES+=		${PLUGINS_EXT:S,^,lib/browser_plugins/${PORTNAME},}
PLIST_DIRSTRY=	lib/browser_plugins

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/usr/lib/mozilla/plugins/* ${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	contractor
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/278375346/ \
	https://launchpad.net/${PORTNAME}/loki/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop-wide extension service

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
	libdbus-glib-1.so:devel/dbus-glib

USES=	cmake gettext-runtime pkgconfig tar:xz
USE_GNOME=	glib20

.include <bsd.port.mk>

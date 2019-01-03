# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	contractor
PORTVERSION=	0.3.4
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Desktop-wide extension service

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libgee-0.8.so:devel/libgee

USES=		gettext-runtime meson pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20

.include <bsd.port.mk>

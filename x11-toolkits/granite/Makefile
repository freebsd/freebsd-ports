# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	granite
DISTVERSION=	5.2.2
CATEGORIES=	x11-toolkits

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Extensions of GTK+3 toolkit

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	contractor:sysutils/contractor \
		gsettings-desktop-schemas>=3.28.1:devel/gsettings-desktop-schemas

USES=		cmake gettext gnome pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20 gtk30 cairo introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-return-type

.include <bsd.port.mk>

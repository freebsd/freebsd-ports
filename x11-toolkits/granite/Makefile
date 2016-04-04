# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	granite
PORTVERSION=	0.3.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://launchpadlibrarian.net/215905441/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Extensions of GTK+3 toolkit

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	contractor:sysutils/contractor

USES=	cmake gettext pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-return-type

.include <bsd.port.mk>

# Created by: Olivier Duchateau

PORTNAME=	calculator
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	pantheon-
DIST_SUBDIR=	pantheon

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple calculator written in Vala

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy

USES=		gettext gnome meson pkgconfig python:3.6+,build
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	elementary

GLIB_SCHEMAS=	io.elementary.calculator.gschema.xml

.include <bsd.port.mk>

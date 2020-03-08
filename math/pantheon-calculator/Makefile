# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	calculator
PORTVERSION=	1.5.4
CATEGORIES=	math
PKGNAMEPREFIX=	pantheon-
DIST_SUBDIR=	pantheon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple calculator written in Vala

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite

USES=		gettext gnome meson pkgconfig python:3.5+,build
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	elementary

GLIB_SCHEMAS=	io.elementary.calculator.gschema.xml

.include <bsd.port.mk>

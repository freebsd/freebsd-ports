# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-calculator
PORTVERSION=	3.18.3
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 calculator tool

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libmpfr.so:math/mpfr

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	gtksourceview3 gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>

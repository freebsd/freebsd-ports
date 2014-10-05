# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/branches/GNOME_3_12/math/gnome-calculator/Makefile 19910 2014-09-25 21:36:39Z kwm $

PORTNAME=	gnome-calculator
PORTVERSION=	3.12.3
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 calculator tool

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtksourceview3 gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>

# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/math/gnome-calculator/Makefile 20026 2014-10-28 13:44:26Z gusi $

PORTNAME=	gnome-calculator
PORTVERSION=	3.14.1
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

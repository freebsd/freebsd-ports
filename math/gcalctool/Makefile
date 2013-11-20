# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/math/gcalctool/Makefile 18897 2013-11-18 16:14:39Z kwm $

PORTNAME=	gcalctool
PORTVERSION=	6.6.2
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 calculator tool based on the old calctool for OpenWindows

BUILD_DEPENDS=	yelp-build:${PORTSDIR}/textproc/yelp-tools \
		itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		bison gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>

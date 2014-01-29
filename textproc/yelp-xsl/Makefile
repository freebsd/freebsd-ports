# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/yelp-xsl/Makefile 18972 2014-01-16 21:18:10Z kwm $

PORTNAME=	yelp-xsl
PORTVERSION=	3.6.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

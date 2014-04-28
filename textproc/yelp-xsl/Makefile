# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/yelp-xsl/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	yelp-xsl
PORTVERSION=	3.12.0
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

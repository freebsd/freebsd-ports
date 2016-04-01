# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yelp-xsl
PORTVERSION=	3.18.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>

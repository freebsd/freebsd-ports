# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/yelp-tools/Makefile 18972 2014-01-16 21:18:10Z kwm $

PORTNAME=	yelp-tools
PORTVERSION=	3.6.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web

BUILD_DEPENDS=	yelp-xsl>=3.1.5:${PORTSDIR}/textproc/yelp-xsl \
		itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

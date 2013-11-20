# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/yelp-xsl/Makefile 18500 2013-05-26 22:35:07Z kwm $

PORTNAME=	yelp-xsl
PORTVERSION=	3.6.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

.include <bsd.port.mk>

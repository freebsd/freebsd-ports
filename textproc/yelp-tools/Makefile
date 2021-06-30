# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	yelp-tools
PORTVERSION=	3.38.0
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	yelp-xsl
DISTVERSION=	42.0
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp
WWW=		https://www.gnome.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		pathfix tar:xz
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rgeo-shapefile
PORTVERSION=	1.0.0
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RGeo module for reading the ESRI shapefile format

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-dbf>=3.0:databases/rubygem-dbf \
		rubygem-rgeo>=1.0:science/rubygem-rgeo

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

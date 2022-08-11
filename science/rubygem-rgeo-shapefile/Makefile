PORTNAME=	rgeo-shapefile
PORTVERSION=	3.0.0
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RGeo module for reading the ESRI shapefile format

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-dbf>=4.0<5:databases/rubygem-dbf \
		rubygem-rgeo>=1.0:science/rubygem-rgeo

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

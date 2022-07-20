PORTNAME=	ruby-netcdf
PORTVERSION=	0.8.0
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the NetCDF scientific IO library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libnetcdf.so:science/netcdf
RUN_DEPENDS=	rubygem-narray>=0:math/rubygem-narray \
		rubygem-narray_miss>=0:math/rubygem-narray_miss

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>

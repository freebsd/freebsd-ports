PORTNAME=	kamis
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maximum independent sets and vertex covers of large sparse graphs
WWW=		https://karlsruhemis.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	KarlsruheMIS
GH_PROJECT=	KaMIS

PLIST_FILES=	bin/graphchecker \
		bin/online_mis \
		bin/redumis \
		bin/sort_adjacencies

.include <bsd.port.mk>

PORTNAME=	kamis
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0-19
DISTVERSIONSUFFIX=	-g254fd16
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maximum independent sets and vertex covers of large sparse graphs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fatal error: 'omp.h' file not found
BROKEN_armv7=	fatal error: 'omp.h' file not found

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KarlsruheMIS
GH_PROJECT=	KaMIS

PLIST_FILES=	bin/graphchecker \
		bin/online_mis \
		bin/redumis \
		bin/sort_adjacencies

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1301000
BROKEN_riscv64=	fatal error: 'omp.h' file not found
.endif

.include <bsd.port.post.mk>

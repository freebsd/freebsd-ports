PORTNAME=	primesum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7-19
DISTVERSIONSUFFIX=	-gac22b96
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sum of the primes below x
WWW=		https://github.com/kimwalisch/primesum

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	compiler does not support int128_t

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kimwalisch

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_STATIC_LIBS

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/primesum --test

.include <bsd.port.mk>

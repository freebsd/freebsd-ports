PORTNAME=	highs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for large scale sparse linear programming (LP) problems
WWW=		https://github.com/ERGO-Code/HiGHS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ERGO-Code
GH_PROJECT=	HiGHS

CMAKE_OFF=	BUILD_TESTING

post-install:
	# see https://github.com/ERGO-Code/HiGHS/issues/502
	${RM} -r ${STAGEDIR}${PREFIX}/external
	# workaround for https://github.com/ERGO-Code/HiGHS/issues/2250
	@${REINPLACE_CMD} \
		-e 's|INTERFACE_INCLUDE_DIRECTORIES "/include;|INTERFACE_INCLUDE_DIRECTORIES "|' \
		${STAGEDIR}${PREFIX}/lib/cmake/highs/highs-targets.cmake

# tests as of 1.11.0: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>

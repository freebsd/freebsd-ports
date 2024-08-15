PORTNAME=	highs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for large scale sparse linear programming (LP) problems
WWW=		https://github.com/ERGO-Code/HiGHS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ERGO-Code
GH_PROJECT=	HiGHS

CMAKE_OFF=	BUILD_TESTING

post-install: # see https://github.com/ERGO-Code/HiGHS/issues/502
	${RM} -r ${STAGEDIR}${PREFIX}/external

# one test fails, see https://github.com/ERGO-Code/HiGHS/issues/1132
# tests fail to build on i386: undefined reference to fmax, see https://github.com/ERGO-Code/HiGHS/issues/505

.include <bsd.port.mk>

PORTNAME=	highs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for large scale sparse linear programming (LP) problems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#LIB_DEPENDS=	libOsi.so:math/osi
CONFLICTS_BUILD=	coin-or-Osi # see https://github.com/ERGO-Code/HiGHS/issues/675

USES=		blaslapack cmake:testing compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ERGO-Code
GH_PROJECT=	HiGHS

CMAKE_OFF=	BUILD_TESTING

post-install: # see https://github.com/ERGO-Code/HiGHS/issues/502
	${RM} -r ${STAGEDIR}${PREFIX}/external

# tests fail to build on i386: undefined reference to fmax, see https://github.com/ERGO-Code/HiGHS/issues/505
# 2 tests fail: https://github.com/ERGO-Code/HiGHS/issues/525

.include <bsd.port.mk>

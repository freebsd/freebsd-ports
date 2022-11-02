PORTNAME=	dd_package
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	science # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MQT decision diagram package tailored to quantum computing
WWW=		https://www.cda.cit.tum.de/research/quantum_dd/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	cda-tum
GH_TUPLE=	google:benchmark:398a8ac:benchmark/extern/benchmark \
		google:googletest:3026483:googletest/extern/googletest

CMAKE_OFF=	BUILD_DD_PACKAGE_TESTS
CMAKE_TESTING_ON=	BUILD_DD_PACKAGE_TESTS # one test fails: DDPackageTest.RequestInvalidPackageSize, see https://github.com/cda-tum/dd_package/issues/117

NO_BUILD=	yes
NO_ARCH=	yes

do-install: # workaround for https://github.com/cda-tum/dd_package/issues/115
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} dd ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>

PORTNAME=	proxsuite
DISTVERSION=	0.7.1
CATEGORIES=	math python
MASTER_SITES=	https://github.com/Simple-Robotics/proxsuite/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quadratic Programming Solver for Robotics and beyond
WWW=		https://github.com/Simple-Robotics/proxsuite

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	simde>0:devel/simde
RUN_DEPENDS=	simde>0:devel/simde

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING
CXXFLAGS+=	-Wno-missing-template-arg-list-after-template-kw # https://github.com/Simple-Robotics/proxsuite/issues/381

NO_ARCH=	yes

# tests as of 0.7.1: 100% tests passed, 0 tests failed out of 166

.include <bsd.port.mk>

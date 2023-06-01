PORTNAME=	cimod
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.55
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for a binary quadratic models
WWW=		https://github.com/OpenJij/cimod

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run

USE_GITHUB=	yes
GH_ACCOUNT=	OpenJij

CMAKE_ON=	CIMOD_INSTALL # doesn't do anything, see https://github.com/OpenJij/cimod/issues/103
CMAKE_OFF=	CIMOD_TEST CIMOD_DOCS
CMAKE_TESTING_ON=	CIMOD_TEST

NO_ARCH=	yes

do-install: # see https://github.com/OpenJij/cimod/issues/103
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>

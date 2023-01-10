PORTNAME=	mmtf-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	science biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ MMTF format API, decoder and encoder, for molecular structures
WWW=		https://mmtf.rcsb.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/include/msgpack.hpp:devel/msgpack-cxx
TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing compiler:c++11-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	rcsb
GH_TUPLE=	rcsb:mmtf:8c88834:x/submodules/mmtf_spec

CMAKE_TESTING_ON=	mmtf_build_local BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

post-patch: # correct paths of test data to be accessible to the test executable
	@${REINPLACE_CMD} -e '\
		s|\.\./submodules/mmtf_spec|${WRKSRC}/submodules/mmtf_spec|g; \
		s|\.\./temporary_test_data|${WRKSRC}/temporary_test_data|g' \
		${WRKSRC}/tests/mmtf_tests.cpp
	@${REINPLACE_CMD} -e '/find_package/s|msgpack|msgpackc-cxx|' \
		${WRKSRC}/CMakeLists.txt

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>

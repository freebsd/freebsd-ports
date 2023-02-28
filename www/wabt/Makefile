PORTNAME=	wabt
DISTVERSION=	1.0.32
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebAssembly Binary Toolkit
WWW=		https://github.com/WebAssembly/wabt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	dabeaz:ply:d776a2e:dabeaz_ply/third_party/ply \
		google:googletest:703bd9c:googletest/third_party/gtest \
		nodejs:uvwasi:55eff19:nodejs_uvwasi/third_party/uvwasi \
		okdshin:PicoSHA2:27fcf69:picosha/third_party/picosha2 \
		simd-everywhere:simde:97315b8:simde/third_party/simde \
		WebAssembly:testsuite:3a04b2c:WebAssembly_testsuite/third_party/testsuite \
		WebAssembly:wasm-c-api:d9a8009:WebAssembly_wasm_c_api/third_party/wasm-c-api

CMAKE_ON=	BUILD_SHARED_LIBS USE_SYSTEM_GTEST
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

OPTIONS_DEFINE=		FUZZ_TOOLS
OPTIONS_SUB=		yes

FUZZ_TOOLS_DESC=	Build tools that can repro fuzz bugs
FUZZ_TOOLS_CMAKE_BOOL=	BUILD_FUZZ_TOOLS
FUZZ_TOOLS_BROKEN=	fail to compile, see https://github.com/WebAssembly/wabt/issues/2153

post-test:
	@cd ${TEST_WRKSRC} && ./wabt-unittests

.include <bsd.port.mk>

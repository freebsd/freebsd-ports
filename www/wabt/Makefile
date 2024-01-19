PORTNAME=	wabt
DISTVERSION=	1.0.34
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebAssembly Binary Toolkit
WWW=		https://github.com/WebAssembly/wabt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase:ldflags python ssl

USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	dabeaz:ply:d776a2e:dabeaz_ply/third_party/ply \
		nodejs:uvwasi:55eff19:nodejs_uvwasi/third_party/uvwasi \
		okdshin:PicoSHA2:27fcf69:picosha/third_party/picosha2 \
		simd-everywhere:simde:54b8c8f:simde/third_party/simde \
		WebAssembly:testsuite:c2a67a5:WebAssembly_testsuite/third_party/testsuite \
		WebAssembly:wasm-c-api:b6dd1fb:WebAssembly_wasm_c_api/third_party/wasm-c-api

CMAKE_ON=	BUILD_SHARED_LIBS USE_SYSTEM_GTEST
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

OPTIONS_DEFINE=		FUZZ_TOOLS
OPTIONS_DEFAULT_amd64=	FUZZ_TOOLS # only enable on architectures where /usr/lib/clang/15.0.7/lib/freebsd/libclang_rt.fuzzer-{arch}.a is installed
OPTIONS_SUB=		yes

FUZZ_TOOLS_DESC=	Build tools that can repro fuzz bugs
FUZZ_TOOLS_CMAKE_BOOL=	BUILD_FUZZ_TOOLS

post-test:
	@cd ${TEST_WRKSRC} && ./wabt-unittests

.include <bsd.port.mk>

PORTNAME=	wabt
DISTVERSION=	1.0.36
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebAssembly Binary Toolkit
WWW=		https://github.com/WebAssembly/wabt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15_amd64=	clang-17 fails to build wabt: undefined symbol: __elf_aux_vector, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=277983

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase:ldflags python ssl

USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	WebAssembly:testsuite:f3f048661dc1686d556a27d522df901cb747ab4a:WebAssembly_testsuite/third_party/testsuite \
		google:googletest:703bd9caab50b139428cea1aaff9974ebee5742e:google_googletest/third_party/gtest \
		dabeaz:ply:d776a2ece6c12bf8f8b6a0e65b48546ac6078765:dabeaz_ply/third_party/ply \
		WebAssembly:wasm-c-api:b6dd1fb658a282c64b029867845bc50ae59e1497:WebAssembly_wasm_c_api/third_party/wasm-c-api \
		nodejs:uvwasi:55eff19f4c7e69ec151424a037f951e0ad006ed6:nodejs_uvwasi/third_party/uvwasi \
		okdshin:PicoSHA2:27fcf6979298949e8a462e16d09a0351c18fcaf2:okdshin_PicoSHA2/third_party/picosha2 \
		simd-everywhere:simde:71fd833d9666141edcd1d3c109a80e228303d8d7:simd_everywhere_simde/third_party/simde \
			nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/third_party/simde/test/munit

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

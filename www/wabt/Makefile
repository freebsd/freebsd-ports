PORTNAME=	wabt
DISTVERSION=	1.0.29
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebAssembly Binary Toolkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	WebAssembly:testsuite:d42da0117f7a93c6a9127e2b9eec64749152c4c1:WebAssembly_testsuite/third_party/testsuite \
		dabeaz:ply:d776a2ece6c12bf8f8b6a0e65b48546ac6078765:dabeaz_ply/third_party/ply \
		WebAssembly:wasm-c-api:d9a80099d496b5cdba6f3fe8fc77586e0e505ddc:WebAssembly_wasm_c_api/third_party/wasm-c-api \
		nodejs:uvwasi:55eff19f4c7e69ec151424a037f951e0ad006ed6:nodejs_uvwasi/third_party/uvwasi

CMAKE_ON=	BUILD_SHARED_LIBS USE_SYSTEM_GTEST
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

OPTIONS_DEFINE=		FUZZ_TOOLS
OPTIONS_SUB=		yes

FUZZ_TOOLS_DESC=	Build tools that can repro fuzz bugs
FUZZ_TOOLS_CMAKE_BOOL=	BUILD_FUZZ_TOOLS

post-test:
	@cd ${TEST_WRKSRC} && ./wabt-unittests

.include <bsd.port.mk>

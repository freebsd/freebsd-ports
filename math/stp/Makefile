PORTNAME=	stp
DISTVERSION=	2.4.1
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Decision Procedure for Bitvectors and Arrays
WWW=		https://stp.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		git:devel/git
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libminisat.so:math/minisat \
		libcryptominisat5.so:math/cryptominisat
TEST_DEPENDS=	lit${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		bison:build cmake:testing python

USE_GITHUB=	yes
GH_TUPLE=	berkeley-abc:abc:95393064368b7c05da4d6f0264fc3419c175c7cb:abc/lib/extlib-abc \
		google:googletest:v1.17.0:googletest/deps/gtest \
		stp:OutputCheck:e0133ed42b091a7ddea6b901055e142447819a9e:outputcheck/deps/OutputCheck

CMAKE_ARGS=		-DUSE_CADICAL=OFF \
			-DSTP_ALLOCATOR=system
CMAKE_TESTING_ARGS=	-DLIT_TOOL=${LOCALBASE}/bin/lit${LLVM_DEFAULT}
CMAKE_TESTING_ON=	ENABLE_TESTING

# Workaround the Python problem
# OSError: /usr/local/lib/libstp.so: No space available for static Thread Local Storage
TEST_ENV=	LD_STATIC_TLS_EXTRA=1024

TESTING_UNSAFE=	llvm-lit based tests fail because our LLVM package does not ship "not"

post-patch:
	${REINPLACE_CMD} 's| make| gmake|g' ${WRKSRC_abc}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_DEFAULT}|g' \
		-e 's|lit\.util|lit${LLVM_DEFAULT}\.util|g' \
		-e 's|lit\.formats|lit${LLVM_DEFAULT}\.formats|g' \
		${WRKSRC}/tests/query-files/lit.cfg

.include <bsd.port.mk>

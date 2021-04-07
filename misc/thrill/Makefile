PORTNAME=	thrill
DISTVERSION=	g20200406
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ framework for algorithmic distributed Big Data batch computations

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 # static_assert failed due to requirement 'sizeof(unsigned int) == 8' "FOXXLL supports only 64-bit builds"

LIB_DEPENDS=	libmpi.so:net/openmpi

USES=		cmake compiler:c++17-lang fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	12c5b59bca66df93b66628b3829027bd0f110dd9

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	THRILL_USE_JEMALLOC
CMAKE_ARGS=	-DINSTALL_INCLUDE_DIR=${PREFIX}/include # workaround for https://github.com/thrill/thrill/issues/196

GH_TUPLE=	USCiLab:cereal:2f9471bc401590cf58b38bbbc33d412dade6d589:USCiLab_cereal/extlib/cereal \
		google:googletest:5490beb0602eab560fa3969a4410e11d94bf12af:google_googletest/extlib/googletest \
		bji:libs3:111dc30029f64bbf82031f3e160f253a0a63c119:bji_libs3/extlib/libs3/libs3 \
		tlx:tlx:89397b7fa1aa5631b4b84e53a92d6c5e06044d43:tlx_tlx/extlib/tlx \
		stxxl:foxxll:a4a8aeee64743f845c5851e8b089965ea1c219d7:stxxl_foxxll/extlib/foxxll

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
LLVM_VERSION=	10 # clang-11 crashes: https://bugs.llvm.org/show_bug.cgi?id=48562
BUILD_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
.endif

.include <bsd.port.post.mk>

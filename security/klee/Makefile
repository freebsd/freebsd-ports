# $FreeBSD$

PORTNAME=	klee
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Symbolic virtual machine built on top of LLVM

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		gmake:devel/gmake
# Should be a LIB_DEPEND, but hard to express in a generic manner
RUN_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang localbase pkgconfig python:3.5+,run \
		shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	tools/klee-stats/klee-stats tools/ktest-tool/ktest-tool
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_POSIX_RUNTIME ENABLE_UNIT_TESTS ENABLE_SYSTEM_TESTS
CMAKE_ARGS=	-DLLVM_CONFIG_BINARY=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} \
		-DMAKE_BINARY=${LOCALBASE}/bin/gmake

OPTIONS_DEFINE=		TCMALLOC
OPTIONS_SINGLE=		SOLVER
OPTIONS_SINGLE_SOLVER=	Z3 STP # TODO METASMT
OPTIONS_DEFAULT=	TCMALLOC Z3
SOLVER_DESC=		Solver: Use the

TCMALLOC_DESC=		Use tcmalloc library for memory management
TCMALLOC_CMAKE_BOOL=	ENABLE_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

Z3_DESC=		Z3 SMT solver
Z3_CMAKE_BOOL=		ENABLE_SOLVER_Z3
Z3_BUILD_DEPENDS=	z3:math/z3
Z3_RUN_DEPENDS=		z3:math/z3

STP_DESC=		STP SMT solver
STP_CMAKE_BOOL=		ENABLE_SOLVER_STP
STP_CMAKE_ON=		-DFREEBSD_STP_STATIC_LIBRARY:STRING=${LOCALBASE}/lib/libstp.a
STP_BUILD_DEPENDS=	stp>0:math/stp

.include <bsd.port.options.mk>

.if ${LLVM_DEFAULT:S,-devel,990,} >= 90
LLVM_DEFAULT=	80
.endif

.include <bsd.port.mk>

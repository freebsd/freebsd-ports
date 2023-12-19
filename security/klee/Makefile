PORTNAME=	klee
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0
CATEGORIES=	security devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Symbolic virtual machine built on top of LLVM
WWW=		https://klee.github.io/

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

NOT_FOR_ARCHS=	i386 powerpc

BUILD_DEPENDS=	gmake:devel/gmake
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang llvm:min=11,max=14,build,run,noexport localbase \
		pkgconfig python:run shebangfix sqlite
USE_GITHUB=	yes
SHEBANG_FILES=	tools/klee-stats/klee-stats tools/ktest-tool/ktest-tool tools/klee-zesti/klee-zesti
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_POSIX_RUNTIME ENABLE_UNIT_TESTS ENABLE_SYSTEM_TESTS
CMAKE_ARGS=	-DLLVM_CONFIG_BINARY=${LOCALBASE}/bin/${LLVM_CONFIG} \
		-DMAKE_BINARY=${LOCALBASE}/bin/gmake

OPTIONS_DEFINE=		TCMALLOC
OPTIONS_DEFAULT=	TCMALLOC Z3 STP
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	Z3 STP

TCMALLOC_DESC=		Use tcmalloc library for memory management
TCMALLOC_CMAKE_BOOL=	ENABLE_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

Z3_DESC=		Enable Z3 SMT solver
Z3_CMAKE_BOOL=		ENABLE_SOLVER_Z3
Z3_BUILD_DEPENDS=	z3:math/z3
Z3_RUN_DEPENDS=		z3:math/z3

STP_DESC=		Enable STP SMT solver
STP_CMAKE_BOOL=		ENABLE_SOLVER_STP
STP_LIB_DEPENDS=	libstp.so:math/stp \
			libcryptominisat5.so:math/cryptominisat

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le || ${ARCH} == aarch64
PLIST_SUB=	32BIT="@comment " \
		64BIT=""
.else
PLIST_SUB=	32BIT="" \
		64BIT=""
.endif

.include <bsd.port.mk>

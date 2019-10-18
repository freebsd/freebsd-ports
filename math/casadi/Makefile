# $FreeBSD$

PORTNAME=	casadi
DISTVERSION=	3.5.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Symbolic framework for numeric optimization

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

CMAKE_OFF=	WITH_DEEPBIND WITH_BUILD_BLASFEO

OPTIONS_DEFINE=		BLASFEO BONMIN CLANG IPOPT LAPACK QPOASES
OPTIONS_DEFAULT=	BLASFEO BONMIN IPOPT LAPACK QPOASES
OPTIONS_SUB=		yes

BLASFEO_DESC=		Build with BLASFEO
BLASFEO_CMAKE_BOOL=	WITH_BLASFEO
BLASFEO_BUILD_DEPENDS=	blasfeo>0:math/blasfeo

BONMIN_DESC=		Build with Bonmin
BONMIN_CMAKE_BOOL=	WITH_BONMIN
BONMIN_USES=		blaslapack:netlib fortran
BONMIN_LIB_DEPENDS=	libbonmin.so:math/bonmin \
			libCbcSolver.so:math/coinmp \
			libipopt.so:math/ipopt

CLANG_DESC=		Build with clang for JIT
CLANG_CMAKE_BOOL=	WITH_CLANG
CLANG_BROKEN=		Fails to find clang

IPOPT_DESC=		Build with IPopt
IPOPT_CMAKE_BOOL=	WITH_IPOPT
IPOPT_USES=		blaslapack:netlib fortran
IPOPT_LIB_DEPENDS=	libipopt.so:math/ipopt

LAPACK_DESC=		Build with LAPACK
LAPACK_CMAKE_BOOL=	WITH_LAPACK
LAPACK_USES=		blaslapack:openblas

QPOASES_DESC=		Build with qpOASES
QPOASES_CMAKE_BOOL=	WITH_QPOASES
QPOASES_LIB_DEPENDS=	libopenblas.so:math/openblas
QPOASES_IMPLIES=	LAPACK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG}
# use clang from ports because cmake can't find base llvm for JIT
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
.endif

.include <bsd.port.mk>

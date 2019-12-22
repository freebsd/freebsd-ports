# $FreeBSD$

PORTNAME=	agrum
DISTVERSION=	0.16.4
PORTREVISION=	1
CATEGORIES=	science math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical modeler for Bayesian networks, influence diagrams, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITLAB=	yes
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes

GL_ACCOUNT=	agrumery
GL_PROJECT=	aGrUM
GL_COMMIT=	676cfe5833f09b013f2612ee299a9025793928d8

CMAKE_OFF=	USE_SWIG

OPTIONS_DEFINE=		ODBC OPENMP PYTHON
OPTIONS_DEFAULT=	OPENMP PYTHON
OPTIONS_SUB=		yes

ODBC_CMAKE_BOOL=	USE_NANODBC
ODBC_USES=		localbase:ldflags
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/llvm${LLVM_DEFAULT}
OPENMP_LDFLAGS=		${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libomp.so # XXX it still links to libomp.so from the openmp package when it is installed
OPENMP_CONFLICTS_BUILD=	openmp

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USES=		python
PYTHON_PLIST_SUB=	PYTHON_VER_MAJ=${PYTHON_VER:R}

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.include <bsd.port.mk>

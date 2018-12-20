# $FreeBSD$

PORTNAME=	agrum
DISTVERSION=	0.13.4
PORTREVISION=	2
CATEGORIES=	science math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical modeler for Bayesian networks, influence diagrams, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITLAB=	yes
GL_ACCOUNT=	agrumery
GL_PROJECT=	aGrUM
GL_COMMIT=	7fb897064bd26e2844164bad191c97173c71262e
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_SWIG

OPTIONS_DEFINE=		ODBC OPENMP PYTHON
OPTIONS_DEFAULT=	OPENMP PYTHON
OPTIONS_SUB=		yes

ODBC_CMAKE_BOOL=	USE_NANODBC
ODBC_USES=		localbase:ldflags
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USES=		python

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Aluminum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-90
DISTVERSIONSUFFIX=	-g60962ae
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic interface to high-performance communication libraries

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libmpi.so:net/openmpi

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	openmp # because OpenMP detection is broken in cmake even with port clang, see bug#234050
LDFLAGS+=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libomp.so # see above

# OpenMP detection is broken with base clang, see bug#223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.include <bsd.port.mk>

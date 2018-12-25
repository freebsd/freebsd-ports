# $FreeBSD$

PORTNAME=	flann
DISTVERSION=	1.9.1-19
DISTVERSIONSUFFIX=	-gf3a17cd
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast nearest neighbor searches in high dimensional spaces

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	mariusmuja
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${DISTVERSION:C/-.*//} SHL2=${DISTVERSION:R}

CFLAGS_powerpc64=	-mminimal-toc

CMAKE_OFF=	BUILD_PYTHON_BINDINGS BUILD_MATLAB_BINDINGS BUILD_EXAMPLES BUILD_TESTS BUILD_DOC \
		USE_OPENMP # OpenMP search is broken in cmake: https://gitlab.kitware.com/cmake/cmake/issues/17474

.include <bsd.port.mk>

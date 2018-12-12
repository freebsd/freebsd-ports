# $FreeBSD$

PORTNAME=	dft_tools
DISTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface to DFT codes in TRIQS

LICENSE=	GPLv3

BROKEN=		wrong LIB_DEPENDS

BUILD_DEPENDS=	boost-libs>=1.53:devel/boost-libs \
		googletest>0:devel/googletest # not needed: https://github.com/TRIQS/dft_tools/issues/95
LIB_DEPENDS=	libcpp2py.so:devel/cpp2py \
		libfftw3.so:math/fftw3 \
		libgmpxx.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmpi.so:net/openmpi \
		libopenblas.so:math/openblas \
		libsz.so:science/szip \
		libtriqs.so:science/triqs

USES=		cmake:outsource,noninja fortran gettext-runtime python:-2.7
USE_GITHUB=	yes
GH_ACCOUNT=	TRIQS

# Use the same compiler as science/triqs
LLVM_VER=	60
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' bin/plovasp bin/vasp_dmft

.include <bsd.port.mk>

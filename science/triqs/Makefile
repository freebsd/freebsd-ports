# $FreeBSD$

PORTNAME=	triqs
DISTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolbox for Research on Interacting Quantum Systems

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN=		wrong LIB_DEPENDS
BROKEN_i386=		error: no matching function for call to 'max': https://github.com/TRIQS/triqs/issues/596

BUILD_DEPENDS=	boost-libs>=1.53:devel/boost-libs \
		${PYNUMPY}
LIB_DEPENDS=	libcpp2py.so:devel/cpp2py \
		libfftw3.so:math/fftw3 \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmpi.so:net/openmpi \
		libopa.so:net/mpich \
		libopenblas.so:math/openblas \
		libsz.so:science/szip
RUN_DEPENDS=	${PYNUMPY}

PORTSCOUT=	limit:^[0-9]+\.[0-9].*$$

USES=		cmake:outsource,noninja fortran gettext-runtime python:2.7 # python:2.7 matches that in devel/cpp2py
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

# It requires c++17, which might be missing in compilers choosable with USES=compiler
LLVM_VER=	60
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} include/gtest.h lib/libgtest.so
	@cd ${STAGEDIR}${PREFIX} && ${RM} share/triqs.modulefile share/triqsvars.sh # https://github.com/TRIQS/triqs/issues/590
	@cd ${STAGEDIR}${PREFIX} && ${RM} share/cmake/run_test.cmake

.include <bsd.port.mk>

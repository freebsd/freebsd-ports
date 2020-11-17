# $FreeBSD$

PORTNAME=	octopus
DISTVERSION=	10.1
CATEGORIES=	science
MASTER_SITES=	https://octopus-code.org/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific program aimed at the ab initio virtual experimentation

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libnlopt.so:math/nlopt \
		libpng.so:graphics/png \
		libsymspg.so:science/spglib \
		libtiff.so:graphics/tiff \
		libvdwxcfort.so:science/libvdwxc \
		libwebp.so:graphics/webp \
		libxc.so:science/libxc \
		libyaml.so:textproc/libyaml

USES=		compiler:c++11-lang fortran gmake jpeg localbase:ldflags perl5 python shebangfix
SHEBANG_FILES=	src/fdep/fortran_dependencies.pl testsuite/performance/create_combinations.py
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${PREFIX}/bin/bash
USE_CXXSTD=	c++11

LDFLAGS+=	-lsymspg
FCFLAGS+=	-I${LOCALBASE}/include -ffree-line-length-none

OPTIONS_DEFINE=			OPENMP
OPTIONS_DEFAULT=		OPENMP
OPENMP_CONFIGURE_ENABLE=	openmp

.include <bsd.port.pre.mk>

# workaround for:
# Error: BOZ literal constant at (1) is neither a data-stmt-constant nor an actual argument to INT, REAL, DBLE, or CMPLX intrinsic function [see '-fno-allow-invalid-boz']
.if ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch -fallow-invalid-boz
.endif

post-stage: # https://gitlab.com/octopus-code/octopus/issues/108
	@${RM} ${STAGEDIR}${PREFIX}/include/yaml.h

.include <bsd.port.post.mk>

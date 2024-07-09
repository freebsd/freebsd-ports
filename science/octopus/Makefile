PORTNAME=	octopus
DISTVERSION=	13.0
PORTREVISION=	3
CATEGORIES=	science # chemistry
MASTER_SITES=	https://octopus-code.org/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific program aimed at the ab initio virtual experimentation
WWW=		https://octopus-code.org/new-site/main/

LICENSE=	GPLv2

BROKEN_aarch64=	undefined reference to `__aarch64_cas8_acq_rel' #'`

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libmpfr.so:math/mpfr \
		libnlopt.so:math/nlopt \
		libpng.so:graphics/png \
		libsymspg.so:science/spglib \
		libtiff.so:graphics/tiff \
		libvdwxcfort.so:science/libvdwxc \
		libwebp.so:graphics/webp \
		libxc.so:science/libxc \
		libyaml.so:textproc/libyaml

USES=		compiler:c++14-lang fortran gmake jpeg libtool localbase:ldflags perl5 python shebangfix
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/fdep/fortran_dependencies.pl testsuite/performance/create_combinations.py

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_SHELL=	${PREFIX}/bin/bash
CONFIGURE_ARGS=	--enable-shared --disable-static

LDFLAGS+=	-lsymspg
FCFLAGS+=	-I${LOCALBASE}/include -ffree-line-length-none
FCFLAGS+=	-fallow-argument-mismatch # fix build on i386: Error: Type mismatch in argument 'dims' at (1); passed INTEGER(8) to INTEGER(4)

INSTALL_TARGET=	install-strip
TEST_TARGET=	check-short # some tests fail, see https://gitlab.com/octopus-code/octopus/-/issues/805

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

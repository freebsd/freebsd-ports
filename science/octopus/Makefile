# $FreeBSD$

PORTNAME=	octopus
DISTVERSION=	9.2
PORTREVISION=	1
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
		libwebp.so:graphics/webp \
		libxc.so:science/libxc

USES=		compiler:c++11-lang fortran gmake jpeg localbase:ldflags perl5 shebangfix
SHEBANG_FILES=	src/fdep/fortran_dependencies.pl
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${PREFIX}/bin/bash
USE_CXXSTD=	c++11

FCFLAGS+=	-I${LOCALBASE}/include -ffree-line-length-none

OPTIONS_DEFINE=			OPENMP
OPTIONS_DEFAULT=		OPENMP
OPENMP_CONFIGURE_ENABLE=	openmp

post-extract: # unbundle spglib, see https://gitlab.com/octopus-code/octopus/issues/124
	@${RM} -r ${WRKSRC}/external_libs/spglib-*
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} 's|$$(top_builddir)/external_libs/spglib-1\.9\.9/src/libsymspg\.a|${LOCALBASE}/lib/libsymspg.so|'

post-stage: # https://gitlab.com/octopus-code/octopus/issues/108
	@${RM} ${STAGEDIR}${PREFIX}/include/yaml.h

.include <bsd.port.mk>

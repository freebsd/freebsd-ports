# $FreeBSD$

PORTNAME=	octopus
DISTVERSION=	8.3
CATEGORIES=	science
MASTER_SITES=	http://www.tddft.org/programs/${PORTNAME}/download/${DISTVERSION}/

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
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libxc.so:science/libxc

USES=		compiler:c++11-lang fortran gmake jpeg localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${PREFIX}/bin/bash
USE_CXXSTD=	c++11

FCFLAGS+=	-I${LOCALBASE}/include -ffree-line-length-none

post-stage: # https://gitlab.com/octopus-code/octopus/issues/108
	@${RM} ${STAGEDIR}${PREFIX}/include/yaml.h

.include <bsd.port.mk>

PORTNAME=	nfft
DISTVERSION=	3.5.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://github.com/NFFT/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nonequispaced fast Fourier transform
WWW=		https://www-user.tu-chemnitz.de/~potts/nfft

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		cunit>0:devel/cunit
LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check
PORTDOCS=	*

CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
CONFIGURE_ARGS=		--disable-static \
			--disable-doxygen-doc \
			--enable-all \
			--with-fftw3

OPTIONS_DEFINE=			DOCS OPENMP
OPTIONS_DEFAULT_aarch64=	OPENMP
OPTIONS_DEFAULT_amd64=		OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_SUB=	yes

OPENMP_CONFIGURE_ENABLE=	openmp

.include <bsd.port.mk>

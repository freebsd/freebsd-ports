# $FreeBSD$

PORTNAME=	nfft
PORTVERSION=	3.4.0
CATEGORIES=	math

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Nonequispaced fast Fourier transform

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3
BUILD_DEPENDS=	bash:shells/bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fftw3=${PREFIX}
USES=		autoreconf libtool
USE_LDCONFIG=	yes
TEST_TARGET=	check

USE_GITHUB=	yes
GH_ACCOUNT=	NFFT

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	DOXYGEN

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc

INSTALL_TARGET=install-strip

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${PATCHDIR}/cpow.c ${WRKSRC}/3rdparty

pre-configure:
	cd ${WRKSRC} && bash ./bootstrap.sh

do-configure:
	cd ${WRKSRC} && bash ${WRKSRC}/configure ${CONFIGURE_ARGS}

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	nfft
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
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

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doc
DOXYGEN_IMPLIES=	DOCS

INSTALL_TARGET=install-strip

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${PATCHDIR}/cpow.c ${WRKSRC}/3rdparty

pre-configure:
	cd ${WRKSRC} && bash ./bootstrap.sh

do-configure:
	cd ${WRKSRC} && bash ${WRKSRC}/configure ${CONFIGURE_ARGS}

.include <bsd.port.post.mk>

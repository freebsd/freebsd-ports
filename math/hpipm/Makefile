PORTNAME=	hpipm
DISTVERSION=	0.1.3-119
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb140f36
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance interior-point-method QP solvers
WWW=		https://github.com/giaf/hpipm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libblasfeo.so:math/blasfeo

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	giaf

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DHPIPM_BLASFEO_LIB=Shared

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DAVX:BOOL=OFF
.endif

.include <bsd.port.post.mk>

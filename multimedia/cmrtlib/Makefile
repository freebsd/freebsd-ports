# $FreeBSD$

PORTNAME=	cmrtlib
DISTVERSIONPREFIX=	intel-media-
DISTVERSION=	18.4.pre4-79
DISTVERSIONSUFFIX=	-g89684719
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	C for Media Runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC:H}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libva.so:multimedia/libva
RUN_DEPENDS=	libva-intel-media-driver>=${PORTVERSION}:multimedia/libva-intel-media-driver

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	media-driver
WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>

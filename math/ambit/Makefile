# $FreeBSD$

PORTNAME=	ambit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	math
PKGNAMESUFFIX=	-tensor # avoid clash with shells/ambit

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for tensor product calculations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libsz.so:science/szip

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jturney
USE_LDCONFIG=	yes

# some declared cmake options do nothing: see https://github.com/jturney/ambit/issues/25 and the patch
CMAKE_ARGS+=	-DSHARED_ONLY:BOOL=ON
CMAKE_ARGS+=	-DENABLE_OPENMP:BOOL=ON
CMAKE_ARGS+=	-DENABLE_TESTS:BOOL=OFF # https://github.com/jturney/ambit/issues/24

.include <bsd.port.mk>

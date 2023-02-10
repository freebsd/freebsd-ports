PORTNAME=	h5utils
DISTVERSION=	1.13.2
CATEGORIES=	science
MASTER_SITES=	https://github.com/NanoComp/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Set of utilities for visualization and conversion of HDF5 format
WWW=		https://github.com/NanoComp/h5utils

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libdf.so:science/hdf \
		libhdf5.so:science/hdf5 \
		libmatheval.so:devel/libmatheval \
		libpng.so:graphics/png

USES=		autoreconf compiler:c++11-lang jpeg localbase
GNU_CONFIGURE=	yes

CFLAGS+=	-pthread
CXXFLAGS+=	-std=c++11

OPTIONS_DEFINE=	OCTAVE
OPTIONS_SUB=	yes

OCTAVE_DESC=		With Octave support
OCTAVE_CONFIGURE_WITH=	octave
OCTAVE_BUILD_DEPENDS=	${LOCALBASE}/include/octave-${OCTAVE_VERSION}/octave/octave.h:math/octave
OCTAVE_USES=		octave:env
OCTAVE_VARS=		PLIST_SUB+="OCTAVE_VERSION=${OCTAVE_VERSION} CONFIGURE_TARGET=${CONFIGURE_TARGET}"

post-install-OCTAVE-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/octave/${OCTAVE_VERSION}/site/oct/${CONFIGURE_TARGET}/h5read.oct

.include <bsd.port.mk>

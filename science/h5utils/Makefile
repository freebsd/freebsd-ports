# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	h5utils
DISTVERSION=	1.13.1
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	aehlig@linta.de
COMMENT=	Set of utilities for visualization and conversion of HDF5 format

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libmatheval.so:devel/libmatheval

USES=		autoreconf compiler:c++11-lang
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	stevengj

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include -lpthread
CXXFLAGS+=	-std=c++11

OPTIONS_DEFINE=		OCTAVE
OPTIONS_SUB=		yes

OCTAVE_DESC=		With Octave support
OCTAVE_CONFIGURE_WITH=	octave
OCTAVE_BUILD_DEPENDS=	${LOCALBASE}/include/octave-${OCTAVE_VERSION}/octave/octave.h:math/octave
OCTAVE_VARS=		PLIST_SUB+="OCTAVE_VERSION=${OCTAVE_VERSION} CONFIGURE_TARGET=${CONFIGURE_TARGET}"

post-install-OCTAVE-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/octave/${OCTAVE_VERSION}/site/oct/${CONFIGURE_TARGET}/h5read.oct

.include "../../math/octave/Makefile.version"
.include <bsd.port.mk>

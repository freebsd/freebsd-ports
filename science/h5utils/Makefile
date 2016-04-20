# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	h5utils
PORTVERSION=	1.12.1
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	aehlig@linta.de
COMMENT=	Set of utilities for visualization and conversion of HDF5 format

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	YES
CFLAGS +=	-L${LOCALBASE}/lib -I${LOCALBASE}/include -lpthread

BUILD_DEPENDS+=	gawk:lang/gawk
LIB_DEPENDS+=	libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libmatheval.so:devel/libmatheval

.include <bsd.port.mk>

# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	h5utils
PORTVERSION=	1.12.1
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	aehlig@linta.de
COMMENT=	Set of utilities for visualization and conversion of HDF5 format

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	YES
CFLAGS +=	-L${LOCALBASE}/lib -I${LOCALBASE}/include -lpthread

BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS+=	libhdf5.so:${PORTSDIR}/science/hdf5 \
		libpng.so:${PORTSDIR}/graphics/png \
		libmatheval.so:${PORTSDIR}/devel/libmatheval

.include <bsd.port.mk>

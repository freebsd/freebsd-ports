# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	h5utils
PORTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/${PORTNAME}/

MAINTAINER=	aehlig@linta.de
COMMENT=	A set of utilities for visualization and conversion of HDF5 format

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

MAN1=		h5totxt.1 h5fromtxt.1 h5tovtk.1 h5topng.1 h5math.1

GNU_CONFIGURE=	YES
CFLAGS +=	-L${LOCALBASE}/lib -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libpng15 ${PTHREAD_LIBS}

BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS +=	hdf5:${PORTSDIR}/science/hdf5 \
		png15:${PORTSDIR}/graphics/png \
		matheval.1:${PORTSDIR}/devel/libmatheval

NO_STAGE=	yes
.include <bsd.port.mk>

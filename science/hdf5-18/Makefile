# New ports collection makefile for:	HDF_lib
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	hdf
PORTVERSION=	4.1r5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF/HDF${PORTVERSION}/tar/
DISTNAME=	HDF${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1
MAN3=		gr_chunk.3
MANCOMPRESSED=	maybe

MAKE_ARGS=	PREFIX="${PREFIX}" -j 2

post-patch:
	${RM} -rf ${WRKSRC}/hdf/jpeg
	${RM} -rf ${WRKSRC}/hdf/zlib

do-configure:
	${CP} -rp ${FILESDIR}/Makefile ${FILESDIR}/hdf \
		${FILESDIR}/mfhdf ${FILESDIR}/man ${WRKSRC}
	${LN} -s config/netcdf-fbsd.h ${WRKSRC}/mfhdf/libsrc/netcdf.h
	${LN} -s netcdf-fbsd.inc ${WRKSRC}/mfhdf/fortran/config/netcdf.inc

test: build
	cd ${WRKSRC}; ${MAKE} test

.include <bsd.port.mk>

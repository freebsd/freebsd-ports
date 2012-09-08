# New ports collection makefile for:	HDF_lib
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	hdf
DISTVERSION=	4.2.7-patch1
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF/HDF_Current/src/	\
		ftp://ftp.hdfgroup.org/HDF/prev-releases/HDF${PORTVERSION:R}/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		sz:${PORTSDIR}/science/szip

CONFLICTS=	netcdf-*

USE_BZIP2=	yes
USE_FORTRAN=	yes
MAKE_JOBS_SAFE=	yes
# XXX Our libtool breaks, when building this:
# XXX can't link libraries with fortran
#USE_AUTOTOOLS=	libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jpeg="${LOCALBASE}" \
		--with-szlib="${LOCALBASE}"\
		--enable-shared

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1
MAN3=		gr_chunk.3
MANCOMPRESSED=	no

USE_LDCONFIG=	yes

check regression-test test: build
	${MAKE} ${_MAKE_JOBS} -C ${WRKSRC}/hdf/test check

post-install:
	# Install man-pages omitted by HDF's own install process
	${INSTALL_MAN} ${WRKSRC}/man/hdfunpac.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/gr_chunk.3 ${MAN1PREFIX}/man/man3/
	# Removing useless .la files from ${PREFIX}/lib
	${RM} -f ${PREFIX}/lib/libdf.la ${PREFIX}/lib/libmfhdf.la

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>

# Created by: mi
# $FreeBSD$

PORTNAME=	hdf
PORTVERSION=	4.2.11
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF/releases/HDF${PORTVERSION}/src/ \
		ftp://ftp.hdfgroup.org/HDF/releases/HDF${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	libsz.so:science/szip

BROKEN_powerpc64=	Does not build: error: expected '=', ',', ';', 'asm' or '__attribute__' before 'you'
NOT_FOR_ARCHS=		aarch64 armv6
NOT_FOR_ARCHS_REASON=	fails to compile: no machine type has been defined

CONFLICTS_INSTALL=	netcdf-4.[0-9]*

USES=		fortran jpeg libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-jpeg=${LOCALBASE} \
		--with-szlib=${LOCALBASE}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/PROD_/ s|=.*|=""|' ${WRKSRC}/config/freebsd
# Allow to build on PowerPC
	@${REINPLACE_CMD} -e '/if defined (__APPLE__)/ \
		s,),) || defined(__powerpc__),' ${WRKSRC}/hdf/src/hdfi.h
	@${REINPLACE_CMD} -e 's/ || (__APPLE__.*//' \
		${WRKSRC}/hdf/test/fortest.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/hdfunpac.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/gr_chunk.3 \
		${STAGEDIR}${MAN3PREFIX}/man/man3

regression-test: build
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} check -C ${WRKSRC}/hdf/test

.include <bsd.port.mk>

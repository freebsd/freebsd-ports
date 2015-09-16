# Created by: mi
# $FreeBSD$

PORTNAME=	hdf
PORTVERSION=	4.2.11
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF/releases/HDF${PORTVERSION}/src/ \
		ftp://ftp.hdfgroup.org/HDF/releases/HDF${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip

CONFLICTS_INSTALL=	netcdf-4.[0-9]*

OPTIONS_DEFINE=	EXAMPLES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-jpeg=${LOCALBASE} --with-szlib=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		fortran jpeg libtool tar:bzip2

PORTDATA=	*
PORTEXAMPLES=	*

BROKEN_powerpc=	Does not compile on powerpc

post-patch:
	@${REINPLACE_CMD} -e '/PROD_/ s|=.*|=""|' ${WRKSRC}/config/freebsd

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/hdfunpac.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/gr_chunk.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/

regression-test test: build
	cd ${WRKSRC}/hdf/test/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>

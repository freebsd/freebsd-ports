# Created by: mi
# $FreeBSD$

PORTNAME=	hdf
DISTVERSION=	4.2.8
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME:U}${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libsz.so:${PORTSDIR}/science/szip

CONFLICTS=	netcdf-*

USES=		fortran
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg="${LOCALBASE}" \
		--with-szlib="${LOCALBASE}" \
		--enable-shared
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not compile on powerpc

post-patch:
	@${REINPLACE_CMD} -e \
		'/PROD_/s|=.*|=""|' ${WRKSRC}/config/freebsd

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/hdfunpac.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/gr_chunk.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

check regression-test test: build
	${MAKE} -C ${WRKSRC}/hdf/test check

.include <bsd.port.mk>

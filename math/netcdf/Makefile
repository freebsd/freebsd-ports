# New ports collection makefile for:	netcdf
# Version required:	3.5-beta2
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	netcdf-3.5-beta2
PKGNAME=	netcdf-3.5b2
CATEGORIES=	math
MASTER_SITES=	ftp://unidata.ucar.edu/pub/netcdf/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/netcdf-3.5/src
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC -DPIC -Df2cFortran"

MAN1=	ncdump.1 ncgen.1
MAN3=	netcdf.3 netcdf.3f

post-build:
	@(cd ${WRKSRC}/libsrc && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)
	@(cd ${WRKSRC}/cxx && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)

post-install:
	${INSTALL_DATA} ${WRKSRC}/libsrc/libnetcdf.so ${PREFIX}/lib/libnetcdf.so.1
	${LN} -sf ${PREFIX}/lib/libnetcdf.so.1 ${PREFIX}/lib/libnetcdf.so
	${INSTALL_DATA} ${WRKSRC}/cxx/libnetcdf_c++.so ${PREFIX}/lib/libnetcdf_c++.so.1
	${LN} -sf ${PREFIX}/lib/libnetcdf_c++.so.1 ${PREFIX}/lib/libnetcdf_c++.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

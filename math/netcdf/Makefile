# New ports collection makefile for:	netcdf
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	3.5.0
CATEGORIES=	math
MASTER_SITES=	ftp://unidata.ucar.edu/pub/netcdf/
#DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for machine-independent, array-oriented data access

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-fPIC -DPIC -Df2cFortran"
INSTALLS_SHLIB=	yes

MAN1=	ncdump.1 ncgen.1
MAN3=	netcdf.3 netcdf.3f

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-build:
	@(cd ${WRKSRC}/libsrc && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)
	@(cd ${WRKSRC}/cxx && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)

post-install:
	${INSTALL_DATA} ${WRKSRC}/libsrc/libnetcdf.so ${PREFIX}/lib/libnetcdf.so.1
	${LN} -sf libnetcdf.so.1 ${PREFIX}/lib/libnetcdf.so
	${INSTALL_DATA} ${WRKSRC}/cxx/libnetcdf_c++.so ${PREFIX}/lib/libnetcdf_c++.so.1
	${LN} -sf libnetcdf_c++.so.1 ${PREFIX}/lib/libnetcdf_c++.so

.include <bsd.port.post.mk>

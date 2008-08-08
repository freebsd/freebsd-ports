# New ports collection makefile for:	netcdf
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/	\
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-4.*

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC -Df2cFortran"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	${MAKE_ENV}
PORTDOCS=	COPYRIGHT README RELEASE_NOTES

MAN1=		ncdump.1 ncgen.1
MAN3=		netcdf.3

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial

.ifdef WITH_FORTRAN
USE_FORTRAN=	yes
MAN3+=	netcdf_f77.3 netcdf_f90.3
PLIST_SUB+=	FORTRAN=""
.else
CONFIGURE_ARGS+=--disable-f77
PLIST_SUB+=	FORTRAN="@comment "
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ncdump ${PREFIX}/bin/ncgen
	${LN} -fs libnetcdf.so.4 ${PREFIX}/lib/libnetcdf.so
	${LN} -fs libnetcdf_c++.so.4 ${PREFIX}/lib/libnetcdf_c++.so
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.else
CONFIGURE_ARGS+=	--disable-docs-install
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

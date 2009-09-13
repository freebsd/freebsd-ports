# New ports collection makefile for:	netcdf
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	3.6.3
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/	\
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT?=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-4.*

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC ${FTNTYPE}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
#CONFIGURE_ENV+=	${MAKE_ENV}

SLAVEDIRS=	science/netcdf-ftn

MAN1=		ncdump.1 ncgen.1
MAN3=		netcdf.3

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial

OPTIONS=	FORTRAN "Build library for Fortran" off

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-docs-install
.else
CONFIGURE_ARGS+=--disable-docs-install
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-man-Makefile.in
.endif

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=--enable-examples
.else
CONFIGURE_ARGS+=--disable-examples
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
USE_FORTRAN=	yes
PKGNAMESUFFIX+=	-ftn
CONFLICTS+=	netcdf-3.*
MAN3+=		netcdf_f77.3 netcdf_f90.3
PLIST_SUB+=	FORTRAN=""
FTNTYPE=	-DpgiFortran
.else
CONFLICTS+=	netcdf-ftn-3.*
CONFIGURE_ARGS+=--disable-f77
PLIST_SUB+=	FORTRAN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'291 s/\(html_docs)\).*/\1/' \
		${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e \
		'271 s/\(info_docs\).*/html_docs\)/' \
		${WRKSRC}/man4/Makefile.in

post-install:
	${LN} -fs libnetcdf.so.4 ${PREFIX}/lib/libnetcdf.so
	${LN} -fs libnetcdf_c++.so.4 ${PREFIX}/lib/libnetcdf_c++.so

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>

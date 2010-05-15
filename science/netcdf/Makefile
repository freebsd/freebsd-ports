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
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT?=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-4.*
PORTSCOUT=	limit:^3\.

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial
MAN1=		ncdump.1 ncgen.1
MAN3=		netcdf.3

OPTIONS=	FORTRAN "Build library for Fortran" off

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-docs-install
.else
CONFIGURE_ARGS+=--disable-docs-install
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -DpgiFortran"
CONFLICTS+=	netcdf-3.*
MAN3+=		netcdf_f77.3 netcdf_f90.3
PKGNAMESUFFIX+=	-ftn
PLIST_SUB+=	FORTRAN=""
USE_FORTRAN=	yes
.else
CONFIGURE_ARGS+=--disable-f77 --disable-f90
CONFLICTS+=	netcdf-ftn-3.*
PLIST_SUB+=	FORTRAN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'291 s/\(html_docs)\).*/\1/' \
		${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e \
		'271 s/\(info_docs\).*/html_docs\)/' \
		${WRKSRC}/man4/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '790 s/install-docDATA //' \
		${WRKSRC}/man/Makefile.in
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>

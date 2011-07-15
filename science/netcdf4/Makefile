# New ports collection makefile for:	netcdf4
# Date created:		2008-11-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	4.1.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT?=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-3.*
LATEST_LINK?=	netcdf4
PORTSCOUT=	limit:^4\.

OPTIONS=	DAP	"Build DAP client and remote testing" off \
		FORTRAN	"Build library for Fortran" off \
		SZIP	"SZIP support (required if HDF5 was built with SZIP)" off

CONFIGURE_ARGS=	--enable-cxx --enable-cxx-4 --enable-netcdf-4 --enable-shared \
		--with-hdf5=${LOCALBASE} --with-zlib=/usr
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include -fPIC -DPIC
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS=	hdf5.7:${PORTSDIR}/science/hdf5-18
MAKE_ENV=	INFODIR="${PREFIX}/${INFO_PATH}" MAKEINFOFLAGS="--no-split"
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial
MAN1=		nccopy.1 ncdump.1 ncgen.1 ncgen3.1
MAN3=		netcdf.3

.include <bsd.port.options.mk>

.if defined(WITH_DAP)
CONFIGURE_ARGS+=--enable-dap --with-curl=${LOCALBASE} \
		--with-curl-config=${LOCALBASE}/bin/curl-config
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=--disable-dap
.endif

.if defined(WITH_FORTRAN)
CPPFLAGS+=	-DpgiFortran
CONFLICTS+=	netcdf-4.*
MAN3+=		netcdf_f77.3 netcdf_f90.3
PKGNAMESUFFIX+=	-ftn
PLIST_SUB+=	FORTRAN=""
USE_FORTRAN=	yes
.else
CONFIGURE_ARGS+=--disable-f77 --disable-f90
CONFLICTS+=	netcdf-ftn-4.*
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_SZIP)
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
LIB_DEPENDS+=	sz.2:${PORTSDIR}/science/szip
.endif

post-configure:
	@cd ${WRKSRC}/man4 && ${SETENV} ${MAKE_ENV} ${MAKE} maintainer-clean-aminfo
.for i in ${INFO}
	@cd ${WRKSRC}/man4 && makeinfo --no-split ${i}.texi
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/man4 && ${INSTALL_DATA} *.html *.pdf *.txt ${DOCSDIR}/
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

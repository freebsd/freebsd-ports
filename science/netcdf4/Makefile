# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf
PORTVERSION=	4.1.3
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT?=	Library for machine-independent, array-oriented data access

CONFLICTS_INSTALL=	hdf-4.[0-9]* netcdf-3.[0-9]* netcdf3-3.[0-9]*
PORTSCOUT=	limit:^4\.

OPTIONS_DEFINE=	DAP FORTRAN SZIP
DAP_DESC=	Build DAP client and remote testing
FORTRAN_DESC=	Build library for Fortran
SZIP_DESC=	SZIP support (required if HDF5 was built with SZIP)

CONFIGURE_ARGS=	--enable-cxx --enable-cxx-4 --enable-netcdf-4 --enable-shared \
		--with-hdf5=${LOCALBASE} --with-zlib=/usr
CPPFLAGS+=	-I${LOCALBASE}/include -fPIC -DPIC
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS=	hdf5.7:${PORTSDIR}/science/hdf5-18
MAKE_ENV=	INFODIR="${PREFIX}/${INFO_PATH}" MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	yes
USES=		pathfix

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial
MAN1=		nccopy.1 ncdump.1 ncgen.1 ncgen3.1
MAN3=		netcdf.3

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDAP}
CONFIGURE_ARGS+=--enable-dap --with-curl=${LOCALBASE} \
		--with-curl-config=${LOCALBASE}/bin/curl-config
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=--disable-dap
.endif

.if ${PORT_OPTIONS:MFORTRAN}
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

.if ${PORT_OPTIONS:MSZIP}
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
LIB_DEPENDS+=	sz.2:${PORTSDIR}/science/szip
.endif

post-configure:
	@cd ${WRKSRC}/man4 && ${SETENV} ${MAKE_ENV} ${MAKE} maintainer-clean-aminfo
.for i in ${INFO}
	@cd ${WRKSRC}/man4 && makeinfo --no-split ${i}.texi
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/man4 && ${INSTALL_DATA} *.html *.pdf *.txt ${DOCSDIR}/
.endif

regression-test test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

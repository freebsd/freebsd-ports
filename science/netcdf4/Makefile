# New ports collection makefile for:	netcdf4
# Date created:		2008-11-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	4.1.1
CATEGORIES=	science
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT?=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-3.*
LATEST_LINK=	netcdf4
PORTSCOUT=	limit:^4\.

CONFIGURE_ARGS=	--enable-cxx --enable-cxx-4 --enable-netcdf-4 --enable-shared \
		--with-hdf5=${LOCALBASE} --with-zlib=/usr
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC"
GNU_CONFIGURE=	yes
LIB_DEPENDS+=	hdf5.6:${PORTSDIR}/science/hdf5-18
MAKE_ENV+=	MAKEINFOFLAGS="--no-split" INFODIR="${PREFIX}/${INFO_PATH}"
USE_LDCONFIG=	yes

INFO=		netcdf netcdf-c netcdf-cxx netcdf-f77 netcdf-f90 \
		netcdf-install netcdf-tutorial
MAN1=		nccopy.1 ncdump.1 ncgen.1 ncgen3.1
MAN3=		netcdf.3

OPTIONS=	FORTRAN	"Build library for Fortran" off \
		SZIP	"SZIP support (required if HDF5 was built with SZIP)" off

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-docs-install
.else
CONFIGURE_ARGS+=--disable-docs-install
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -DpgiFortran"
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

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '297 s/\(info_docs\).*/html_docs\)/' \
		${WRKSRC}/man4/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '839 s/install-docDATA //' \
		${WRKSRC}/man4/Makefile.in
.endif

post-configure:
	@cd ${WRKSRC}/man4 && make maintainer-clean-aminfo
.for i in ${INFO}
	@cd ${WRKSRC}/man4 && makeinfo --no-split ${i}.texi
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>

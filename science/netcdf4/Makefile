# New ports collection makefile for:	netcdf4
# Date created:		2008-11-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.* netcdf-3.*
LATEST_LINK=	netcdf4

CONFIGURE_ARGS=	--disable-f77 --disable-f90 \
		--enable-cxx --enable-cxx-4 --enable-ncgen4 --enable-netcdf-4 \
		--enable-shared --with-hdf5=${LOCALBASE} --with-zlib=/usr
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC -Df2cFortran"
MAKE_ENV+=	MAKEINFOFLAGS="--no-split" INFODIR="${PREFIX}/${INFO_PATH}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LIB_DEPENDS+=	hdf5.6:${PORTSDIR}/science/hdf5-18

INFO=		netcdf netcdf-c netcdf-cxx netcdf-cxx4 netcdf-f77 \
		netcdf-f90 netcdf-install netcdf-tutorial

MAN1=		ncdump.1 ncgen.1 ncgen4.1
MAN3=		netcdf.3

OPTIONS=	HDF5_CONVERT	"Do data conversion through HDF5"	off

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-docs-install
.else
CONFIGURE_ARGS+=--disable-docs-install
.endif

.if defined(WITH_HDF5_CONVERT)
CONFIGURE_ARGS+=--enable-hdf5-convert
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '288 s/\(info_docs\).*/html_docs\)/' \
		${WRKSRC}/man4/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '829 s/install-docDATA //' \
		${WRKSRC}/man4/Makefile.in

.endif

post-configure:
	@cd ${WRKSRC}/man4 && make maintainer-clean-aminfo
.for i in ${INFO}
	@cd ${WRKSRC}/man4 && makeinfo --no-split ${i}.texi
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

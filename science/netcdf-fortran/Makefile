# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netcdf-fortran
PORTVERSION=	4.4.0
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fortran library for machine-independent, array-oriented data access

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf

CONFLICTS=	netcdf-ftn-[0-9]* netcdf3-ftn-[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC -DPIC -DgFortran
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	MAKEINFOFLAGS=--no-split
MAKE_JOBS_UNSAFE=	yes
#USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	yes
USES=		fortran libtool makeinfo pathfix

#INFO=		netcdf-f77 netcdf-f90

#AUTOMAKE_ARGS=	--add-missing
#LIBTOOLIZE_ARGS=--copy --force --install
#PATHFIX_MAKEFILEIN=	Makefile.am

USE_GITHUB=	yes
GH_ACCOUNT=	Unidata
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	ccd65b4

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdff.so.6

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>

# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netcdf-fortran
PORTVERSION=	4.5.2
CATEGORIES=	science
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fortran library for machine-independent, array-oriented data access

LICENSE=	UCAR_UNIDATA
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	University Corporation for Atmospheric Research/Unidata
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	netcdf>=4.6.0:science/netcdf
LIB_DEPENDS=	libnetcdf.so:science/netcdf

USES=		fortran gmake libtool localbase makeinfo pathfix

CPPFLAGS+=	-fPIC -DPIC -DgFortran
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ENV=	MAKEINFOFLAGS=--no-split
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.mk>

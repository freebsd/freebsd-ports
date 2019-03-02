# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf-cxx
PORTVERSION=	4.3.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}4-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for machine-independent, array-oriented data access

LICENSE=	UCAR_UNIDATA
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	University Corporation for Atmospheric Research/Unidata
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libnetcdf.so:science/netcdf

CONFLICTS=	netcdf-3.* netcdf-4.[0-2].*

CPPFLAGS+=	-fPIC -DPIC
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		libtool localbase pathfix

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdf_c++4.so.1

.include <bsd.port.mk>

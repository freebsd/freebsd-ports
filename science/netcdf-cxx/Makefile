# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf-cxx
PORTVERSION=	4.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for machine-independent, array-oriented data access

LIB_DEPENDS=	libnetcdf.so:science/netcdf

CONFLICTS=	netcdf-3.* netcdf-4.[0-2].*

CPPFLAGS+=	-fPIC -DPIC
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		libtool localbase pathfix

GH_ACCOUNT=	Unidata
GH_PROJECT=	${PORTNAME}4
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdf_c++4.so.1

.include <bsd.port.mk>

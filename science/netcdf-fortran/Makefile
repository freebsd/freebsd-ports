# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netcdf-fortran
PORTVERSION=	4.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fortran library for machine-independent, array-oriented data access

LIB_DEPENDS=	libnetcdf.so:science/netcdf

CONFLICTS=	netcdf-ftn-[0-9]* netcdf3-ftn-[0-9]*

CPPFLAGS+=	-fPIC -DPIC -DgFortran
GNU_CONFIGURE=	yes
MAKE_ENV=	MAKEINFOFLAGS=--no-split
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		fortran libtool localbase makeinfo pathfix

GH_ACCOUNT=	Unidata
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdff.so.6.1.1

.include <bsd.port.mk>

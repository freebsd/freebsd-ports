# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf-cxx
PORTVERSION=	4.2.1
CATEGORIES=	science
MASTER_SITES=	https://github.com/Unidata/${PORTNAME}4/archive/v${PORTVERSION}.tar.gz?dummy=/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for machine-independent, array-oriented data access

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf

CONFLICTS=	netcdf-3.* netcdf-4.[0-2].*

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC -DPIC
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		pathfix
WRKSRC=		${WRKDIR}/${PORTNAME}4-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdf_c++4.so.1

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>

# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf-cxx
PORTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for machine-independent, array-oriented data access

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf

CONFLICTS=	netcdf-3.* netcdf-4.[0-2].*

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC -DPIC
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		libtool pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	Unidata
GH_COMMIT=	b477274
GH_PROJECT=	${PORTNAME}4
GH_TAGNAME=	v${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetcdf_c++4.so.1

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>

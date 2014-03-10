# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	pycdf
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	SF/pysclint/${PORTNAME}/${PORTNAME}-${PORTVERSION}b
DISTNAME=	${PORTNAME}-0.6-3b

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Python Interface to the Unidata NetCDF Library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${LOCALBASE}/lib/libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS:=	${BUILD_DEPENDS}

LDFLAGS+=	"-L${LOCALBASE}/lib"

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYTHON_PKGNAMEPREFIX=	yes
PYDISTUTILS_EGGINFO=	pycdf-0.6_3b-py${PYTHON_VER}.egg-info
WRKSRC=		${WRKDIR}/${DISTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>

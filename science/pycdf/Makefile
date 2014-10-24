# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	pycdf
PORTVERSION=	0.6.3
PORTREVISION=	4
CATEGORIES=	science python
MASTER_SITES=	SF/pysclint/${PORTNAME}/${PORTNAME}-${PORTVERSION}b
DISTNAME=	${PORTNAME}-0.6-3b

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the Unidata NetCDF Library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS:=	${BUILD_DEPENDS}

LDFLAGS+=	"-L${LOCALBASE}/lib"

USES=		python
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>

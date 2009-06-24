# Ports collection makefile for:	netCDF4
# Date created:			18 Feb, 2009
# Whom:				wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	netCDF4
PORTVERSION=	0.8.1
CATEGORIES=	science python
MASTER_SITES=	http://netcdf4-python.googlecode.com/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Interface to the NetCDF Library(versions 3 and 4)

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	hdf5.6:${PORTSDIR}/science/hdf5-18 \
		netcdf.5:${PORTSDIR}/science/netcdf4

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>

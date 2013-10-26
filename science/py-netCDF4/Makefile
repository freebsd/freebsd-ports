# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	netCDF4
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	netcdf4-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the NetCDF Library (versions 3 and 4)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	hdf5:${PORTSDIR}/science/hdf5-18 \
		netcdf:${PORTSDIR}/science/netcdf4
RUN_DEPENDS=	${PYNUMPY}

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_DOS2UNIX=	utils/nc3tonc4
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	HDF5_INCDIR=${LOCALBASE}/include \
		HDF5_LIBDIR=${LOCALBASE}/lib \
		NETCDF4_INCDIR=${LOCALBASE}/include \
		NETCDF4_LIBDIR=${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/nc3tonc4 \
		bin/nc4tonc3 \
		%%PYTHON_SITELIBDIR%%/netCDF4.so \
		%%PYTHON_SITELIBDIR%%/netCDF4_utils.py \
		%%PYTHON_SITELIBDIR%%/netCDF4_utils.pyc \
		%%PYTHON_SITELIBDIR%%/netCDF4_utils.pyo \
		%%PYTHON_SITELIBDIR%%/netcdftime.py \
		%%PYTHON_SITELIBDIR%%/netcdftime.pyc \
		%%PYTHON_SITELIBDIR%%/netcdftime.pyo

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		"/dirstosearch/s|=.*|= ['${LOCALBASE}']|" ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>

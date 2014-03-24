# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	netCDF4
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	netcdf4-python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the NetCDF Library (versions 3 and 4)

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5-18 \
		libnetcdf.so:${PORTSDIR}/science/netcdf4
RUN_DEPENDS=	${PYNUMPY}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		dos2unix
DOS2UNIX_FILES=	utils/nc3tonc4
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
MAKE_ENV=	HDF5_INCDIR=${LOCALBASE}/include \
		HDF5_LIBDIR=${LOCALBASE}/lib \
		NETCDF4_INCDIR=${LOCALBASE}/include \
		NETCDF4_LIBDIR=${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		"/dirstosearch/s|=.*|= ['${LOCALBASE}']|" ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

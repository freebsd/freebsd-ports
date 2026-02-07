PORTNAME=	netCDF4
DISTVERSION=	1.7.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the NetCDF Library (versions 3 and 4)
WWW=		https://unidata.github.io/netcdf4-python/

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cftime>=0:devel/py-cftime@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython cython_run distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${ECHO_CMD} -n > ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "[options]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "use_ncconfig=True" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "ncconfig=${LOCALBASE}/bin/nc-config" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "[directories]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HDF5_libdir=${LOCALBASE}/lib" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HDF5_incdir=${LOCALBASE}/include" >> ${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/netCDF4/_netCDF4*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

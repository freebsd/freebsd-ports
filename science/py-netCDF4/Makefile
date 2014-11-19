# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	netCDF4
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Python Interface to the NetCDF Library (versions 3 and 4)

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5 \
		libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS=	${PYNUMPY}

USE_GITHUB=	yes
GH_ACCOUNT=	Unidata
GH_PROJECT=	netcdf4-python
GH_TAGNAME=	v${PORTVERSION}rel
GH_COMMIT=	1344040

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES

post-patch:
	@${ECHO_CMD} -n > ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "[options]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "use_ncconfig=True" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "ncconfig=${LOCALBASE}/bin/nc-config" \
		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "[directories]" >> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HDF5_libdir=${LOCALBASE}/lib" \
		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HDF5_incdir=${LOCALBASE}/include" \
		>> ${WRKSRC}/setup.cfg

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

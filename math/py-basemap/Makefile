# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	basemap
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	SF/matplotlib/matplotlib-toolkits/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Plots data on map projections with boundaries

LICENSE=	GPLv2 LGPL21 MIT
LICENSE_COMB=	multi

DEPRECATED=	Deprecated upstream
EXPIRATION_DATE=	2020-02-14

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
LIB_DEPENDS=	libgeos.so:graphics/geos

USES=		python:2.7
USE_PYTHON=	autoplist distutils

DATADIR=	${PREFIX}/share/py-${PORTNAME}-data
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

MAKE_ENV=	BASEMAP_DATA_PATH=${DATADIR}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-patch:
	@${GREP} -lR "share/basemap" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s,share/basemap,share/py-basemap-data,g"

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_geoslib.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mpl_toolkits/basemap/_proj.so

.include <bsd.port.mk>

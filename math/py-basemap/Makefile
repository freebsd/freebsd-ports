# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	basemap
PORTVERSION=	0.9.2
PORTREVISION=	8
CATEGORIES=	math python
MASTER_SITES=	SF/matplotlib/matplotlib-toolkits/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plots data on map projections with continental and political boundaries

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/matplotlib/:${PORTSDIR}/math/py-matplotlib

USES=		python
USE_PYTHON=	distutils autoplist

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

.include <bsd.port.mk>

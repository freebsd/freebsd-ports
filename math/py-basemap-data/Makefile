# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	basemap-data
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	SF/matplotlib/matplotlib-toolkits/basemap-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Map data for py-basemap

USES=		python
USE_PYTHON=	distutils autoplist

DATADIR=	${PREFIX}/share/py-${PORTNAME}
MAKE_ENV=	BASEMAP_DATA_PATH=${DATADIR}

.include <bsd.port.mk>

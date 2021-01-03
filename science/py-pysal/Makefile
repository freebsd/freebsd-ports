# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysal
PORTVERSION=	2.2.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library of spatial analysis functions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esda>=2.2.1:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giddy>=2.3.0:graphics/py-giddy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inequality>=1.0.0:science/py-inequality@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.2.2:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mapclassify>=2.2.0:graphics/py-mapclassify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mgwr>=2.1.1:graphics/py-mgwr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pointpats>=2.1.0:graphics/py-pointpats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segregation>=1.2.0:science/py-segregation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spaghetti>=1.4.1:science/py-spaghetti@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglm>=1.0.7:math/py-spglm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spint>=1.0.6:math/py-spint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}splot>=1.1.2:math/py-splot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spreg>=1.0.4:math/py-spreg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spvcm>=0.3.0:math/py-spvcm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tobler>=0.2.0:science/py-tobler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0,1:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

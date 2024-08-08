PORTNAME=	towncrier
PORTVERSION=	23.11.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	23

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Building newsfiles for your project
WWW=		https://towncrier.readthedocs.io/en/stable/ \
		https://github.com/twisted/towncrier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.17.1:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=5:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}towncrier

# This is a temporary fix for building documents before py-towncrier is compatible.
# See PR 280570 for details.
PORTSCOUT=	ignore:1

.include <bsd.port.mk>

PORTNAME=	bokeh
PORTVERSION=	3.10.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Interactive Web Plotting for Python
WWW=		https://bokeh.org/ \
		https://github.com/bokeh/bokeh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}narwhals>=1.13:math/py-narwhals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=16.8:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xyzservices>=2021.09.1:www/py-xyzservices@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

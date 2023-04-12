PORTNAME=	hcloud
DISTVERSION=	1.19.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Official Hetzner Cloud python library
WWW=		https://hcloud-python.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.5,<3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20,<3:www/py-requests@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=3.6.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.3.4:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=3.23.1:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>=22.3.0:devel/py-black@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

.include <bsd.port.mk>

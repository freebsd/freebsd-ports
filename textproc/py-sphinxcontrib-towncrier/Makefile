PORTNAME=	sphinxcontrib-towncrier
PORTVERSION=	0.5.0a0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/sphinx-contrib/sphinxcontrib-towncrier/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinxcontrib_towncrier-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RST directive for injecting a Towncrier-generated changelog draft
WWW=		https://sphinxcontrib-towncrier.readthedocs.io/en/latest/ \
		https://github.com/sphinx-contrib/sphinxcontrib-towncrier

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}towncrier>=23:textproc/py-towncrier@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>

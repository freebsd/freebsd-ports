PORTNAME=	yapf
PORTVERSION=	0.43.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Formatter for Python code
WWW=		https://github.com/google/yapf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}platformdirs>=3.5.1:devel/py-platformdirs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest
TEST_ARGS=	discover \
		-p \
		'*_test.py' \
		yapftests/
NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	python-frontmatter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parse and manage posts with YAML (or other) frontmatter
WWW=		https://python-frontmatter.readthedocs.io/en/latest/ \
		https://github.com/eyeseast/python-frontmatter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-toml>0:devel/py-types-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>0:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	eyeseast

NO_ARCH=	yes

# tests as of 1.3.0: 56 passed in 0.30s

.include <bsd.port.mk>

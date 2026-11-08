PORTNAME=	banks
PORTVERSION=	2.5.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prompt programming language # not really a language
WWW=		https://masci.github.io/banks/ \
		https://github.com/masci/banks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.2.0:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}griffe>0:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}litellm>0:misc/py-litellm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_cov

NO_ARCH=	yes

# tests as of 2.5.1: 158 passed, 14 skipped, 1 xfailed in 72.57s (0:01:12)

.include <bsd.port.mk>

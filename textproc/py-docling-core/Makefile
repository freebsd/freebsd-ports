PORTNAME=	docling-core
DISTVERSIONPREFIX=	v
DISTVERSION=	2.95.0
PORTREVISION=	1
CATEGORIES=	textproc python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to define and validate data types in Docling
WWW=		https://github.com/docling-project/docling-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}doclang>=0.7:textproc/py-doclang@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonref>=1.1.0:devel/py-jsonref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.16.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}latex2mathml>=3.77.0:textproc/py-latex2mathml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1.4:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.6.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.14.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>=0:devel/py-gitpython@${PY_FLAVOR}
		#${PYTHON_PKGNAMEPREFIX}universal-pathlib>=0.3.10:filesystems/py-universal-pathlib@${PY_FLAVOR} # missing

# optional dependencies are used during normal use of this library
DCLQ_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}doclang>=0.7:textproc/py-doclang@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.0.2:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.15.1:devel/py-typer@${PY_FLAVOR}
CHUNKING_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}semchunk>=2.2.0:textproc/py-semchunk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.42.0:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-c>=0.23.4:devel/py-tree-sitter-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-javascript>=0.23.1:devel/py-tree-sitter-javascript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-python>=0.23.6:devel/py-tree-sitter-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-typescript>=0.23.2:devel/py-tree-sitter-typescript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.25.0:devel/py-tree-sitter@${PY_FLAVOR}
CHUNKING_OPENAI_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}semchunk>=2.2.0:textproc/py-semchunk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.9.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-c>=0.23.4:devel/py-tree-sitter-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-javascript>=0.23.1:devel/py-tree-sitter-javascript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-python>=0.23.6:devel/py-tree-sitter-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-typescript>=0.23.2:devel/py-tree-sitter-typescript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.25.0:devel/py-tree-sitter@${PY_FLAVOR}
RUN_DEPENDS+=	${DCLQ_DEPENDS} \
		${CHUNKING_DEPENDS} \
		${CHUNKING_OPENAI_DEPENDS}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	docling-project
GH_PROJECT=	docling-core

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload --ignore=packages/dclq \
		--ignore=tests/test_code_chunker.py \
		--ignore=tests/test_code_chunking_strategy.py

NO_ARCH=	yes

# tests as of 2.95.0: 588 passed, 113 skipped, 85 warnings

.include <bsd.port.mk>

PORTNAME=	pymupdf4llm-mcp
DISTVERSION=	0.0.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MCP server for pymupdf4llm: convert PDF to Markdown for LLMs
WWW=		https://github.com/pymupdf/pymupdf4llm-mcp

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mcp>=1.6.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf4llm>=0.0.21:textproc/py-pymupdf4llm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.15.2:devel/py-typer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}inline-snapshot>0:devel/py-inline-snapshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0.25.3:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 0.0.4: 1 passed in 0.22s

.include <bsd.port.mk>

PORTNAME=	pdf-form-filler-mcp
DISTVERSION=	0.1.1
CATEGORIES=	textproc # machine-learning
MASTER_SITES=	PYPI
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MCP server for filling PDF forms (AcroForm and XFA)
WWW=		https://github.com/yurivict/pdf-form-filler-mcp

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mcp>=1.0.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.24.0:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>=3.0.0:print/py-pypdf@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 0.1.0: 8 passed in 4.38s

.include <bsd.port.mk>

PORTNAME=	docling-serve-haystack
DISTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Haystack converter component for DoclingServe via HTTP
WWW=		https://pypi.org/project/docling-serve-haystack/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}haystack_ai>=2.9.0:misc/py-haystack_ai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0:www/py-httpx@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

# shares haystack_integrations/components/converters/py.typed
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}docling-haystack

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p pytest_asyncio.plugin \
		-o asyncio_mode=auto -m 'not integration'

# tests as of 2.0.0: 52 passed, 2 deselected in 0.79s

.include <bsd.port.mk>

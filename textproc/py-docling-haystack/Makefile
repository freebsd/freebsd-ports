PORTNAME=	docling-haystack
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Haystack integration for docling
WWW=		https://pypi.org/project/docling-haystack/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling>=2.32.0:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}haystack_ai>=2.12.0:misc/py-haystack_ai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.0.2:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
TEST_ARGS=	--disable-plugin-autoload

# tests as of 3.0.0: 40 passed, 5 warnings in 6.84s

.include <bsd.port.mk>

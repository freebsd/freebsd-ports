PORTNAME=	cssselect
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cssselect parses CSS3 Selectors and translates them to XPath 1.0
WWW=		https://github.com/scrapy/cssselect

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.28.0:devel/py-hatchling@${PY_FLAVOR}
# tests: 24 passed 10 warnings
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml-stubs>=0.5.1:devel/py-lxml-stubs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.14.10_1:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=1.0.0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

post-build-DOCS-on:
	(cd ${WRKSRC} && \
		PYTHONPATH=${WRKSRC} sphinx-build-${PYTHON_VER} -N -a docs docs.html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs.html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -path *doctrees*")

.include <bsd.port.mk>

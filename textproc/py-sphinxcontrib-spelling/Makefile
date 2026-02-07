PORTNAME=	sphinxcontrib-spelling
DISTVERSION=	8.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinxcontrib_spelling-${PORTVERSION}

MAINTAINER=	matthew@wener.org
COMMENT=	Sphinx spelling extension
WWW=		https://github.com/sphinx-contrib/spelling

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		en-hunspell>=0:textproc/en-hunspell

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}

_DOCS_BUILD_ENV=	PYTHONPATH="${PYTHONPATH}:${INSTALL_WRKSRC}${PYTHON_SITELIBDIR}"

post-build-DOCS-on:
	@(cd ${WRKSRC}; \
		pip-${PYTHON_VER} install --ignore-installed --isolated \
		--no-deps --root=${INSTALL_WRKSRC} ${WRKSRC}/dist/*.whl && \
		${SETENV} ${_DOCS_BUILD_ENV} sphinx-build-${PYTHON_VER} \
		-b html -d _build/doctress docs/source/ build/sphinx/html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv -and ! -name _images")

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>

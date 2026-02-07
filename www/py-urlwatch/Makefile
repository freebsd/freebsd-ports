PORTNAME=	urlwatch
DISTVERSION=	2.29
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Monitors webpages and sends notifications about changes
WWW=		https://github.com/thp/urlwatch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}minidb>=2.0.8:databases/py-minidb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdftotext>0:textproc/py-pdftotext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jq>0:textproc/py-jq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytesseract>0:graphics/py-pytesseract@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest
# These tests yields only positive results if run as regular user.
PYTEST_IGNORED_TESTS=	test_disabled_job \
			test_idxs_one \
			test_idxs_none \
			test_tags_single \
			test_tags_multiple

NO_ARCH=	yes

PORTEXAMPLES=	hooks.py.example urls.yaml.example

OPTIONS_DEFINE=		DOCS EXAMPLES
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_PORTDOCS=		html/* text/*
DOCS_VARS=		BINARY_ALIAS=sphinx-build=sphinx-build-${PYTHON_VER} MAKE_JOBS_UNSAFE=yes USES+=gmake

post-build-DOCS-on:
		cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -j${MAKE_JOBS_NUMBER} html text

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}/html
		${MKDIR} ${STAGEDIR}${DOCSDIR}/text
		(cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} "! -name .buildinfo")
		(cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} text ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/share/urlwatch/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	urlwatch
DISTVERSION=	2.23
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Monitors webpages and sends notifications about changes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}minidb>0:databases/py-minidb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdftotext>0:textproc/py-pdftotext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jq>0:textproc/py-jq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytesseract>0:graphics/py-pytesseract@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}

USES=		python:3.6+
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent distutils

BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}
NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_PORTDOCS=		html/* text/*
DOCS_VARS=		USES+=gmake

post-build-DOCS-on:
		cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -j${MAKE_JOBS_NUMBER} html text

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}/html
		${MKDIR} ${STAGEDIR}${DOCSDIR}/text
		(cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} "! -name .buildinfo")
		(cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} text ${STAGEDIR}${DOCSDIR})

do-test:
		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>

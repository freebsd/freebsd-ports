# XXX: see below (post-patch target) before updating
PORTNAME=	mdformat
DISTVERSION=	0.7.22
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CommonMark compliant Markdown formatter
WWW=		https://github.com/executablebooks/mdformat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.41.3:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-it-py>=1<5:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdurl>=0.1.2:textproc/py-mdurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipp>=0.5:devel/py-zipp@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3.0_1:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.12.0:devel/py-pytest-randomly@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	executablebooks
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.18.1:textproc/py-docutils@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}furo>=2022.6.21:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}myst-parser>=0.18.0:textproc/py-myst-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=5.4.0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_PORTDOCS=		* .buildinfo

# tests: 4282 passed, 5 skipped (require Python 3.13+)
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# XXX: remove this target as soon as devel/py-setuptools is updated to version >= 69
post-patch:
	@${REINPLACE_CMD} \
		-e 's/\(setuptools>=\)69/\163/1' \
		${WRKSRC}/pyproject.toml

post-install-DOCS-on:
			${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
				-d ${WRKDIR} -b html -n ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

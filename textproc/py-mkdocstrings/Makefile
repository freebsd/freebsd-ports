PORTNAME=	mkdocstrings
DISTVERSION=	0.30.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Automatic documentation from sources for MkDocs
WWW=		https://github.com/mkdocstrings/mkdocstrings

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.6:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.6:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-autorefs>=1.4:textproc/py-mkdocs-autorefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-get-deps>=0.2:textproc/py-mkdocs-get-deps@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=6.3:textproc/py-pymdown-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>0:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>0:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings-python>0:textproc/py-mkdocstrings-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
# Skip "test_sphinx_load_mkdocstrings_inventory_file" as it requires
# mkdocs-gen-files (not in Ports tree, yet).
# The same applies to "test_plugin" which requires markdown-exec (not in Ports
# tree yet).
PYTEST_IGNORED_TESTS=	test_sphinx_load_mkdocstrings_inventory_file test_plugin

NO_ARCH=	yes

OPTIONS_DEFINE=		CRYSTAL
OPTIONS_DEFAULT=	CRYSTAL
OPTIONS_RADIO=		PYHANDLER
OPTIONS_RADIO_PYHANDLER=	PYTHON PYTHONLEGACY

CRYSTAL_DESC=		Crystal language handler
PYTHONLEGACY_DESC=	Legacy Python language handler
PYTHON_DESC=		Python language handler

CRYSTAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-crystal>=0.3.4:textproc/py-mkdocstrings-crystal@${PY_FLAVOR}
PYTHONLEGACY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python-legacy>=0.2.1:textproc/py-mkdocstrings-python-legacy@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python>=0.16.2:textproc/py-mkdocstrings-python@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

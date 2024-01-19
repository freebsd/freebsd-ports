PORTNAME=	wtforms
DISTVERSION=	3.1.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Flexible forms validation and rendering library for python
WWW=		http://wtforms.simplecodes.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pallets-Sphinx-Themes>0:textproc/py-pallets-sphinx-themes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-issues>0:textproc/py-sphinx-issues@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-log-cabinet>0:textproc/py-sphinxcontrib-log-cabinet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-flake8>0:devel/py-pyproject-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS EMAIL
OPTIONS_DEFAULT=	EMAIL

EMAIL_DESC=	Form email validation

EMAIL_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR}
EMAIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR}

_DOCS_BUILD_ENV=	PYTHONPATH="${PYTHONPATH}:${INSTALL_WRKSRC}${PYTHON_SITELIBDIR}"

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		pip-${PYTHON_VER} install --ignore-installed --isolated \
		--no-deps --root=${INSTALL_WRKSRC} ${WRKSRC}/dist/*.whl && \
		${SETENV} ${_DOCS_BUILD_ENV} sphinx-build-${PYTHON_VER} \
		-M html . _build/html)

post-build:
	(cd ${WRKSRC}/docs && \
		pip-${PYTHON_VER} install --ignore-installed --isolated \
		--no-deps --root=${INSTALL_WRKSRC} ${WRKSRC}/dist/*.whl && \
		${SETENV} ${_DOCS_BUILD_ENV} sphinx-build-${PYTHON_VER} \
		-M man . _build/man)

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/man/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/ "-not -name .buildinfo -not -regex ^./_sources.*")

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} tox-${PYTHON_VER} -e ${PY_FLAVOR}

.include <bsd.port.mk>

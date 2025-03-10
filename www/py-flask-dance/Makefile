PORTNAME=	flask-dance
PORTVERSION=	7.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_dance-${PORTVERSION}

MAINTAINER=	matthew@wener.org
COMMENT=	Doing the OAuth dance with style using Flask, requests, and oauthlib
WWW=		https://flask-dance.readthedocs.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urlobject>=0:www/py-urlobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}betamax>=0:www/py-betamax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-caching>=0:www/py-flask-caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>=0:www/py-flask-login@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=0:databases/py-sqlalchemy20@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SIGNALS
OPTIONS_RADIO=		SQLA
OPTIONS_RADIO_SQLA=	SQLA14 SQLA20

SIGNALS_DESC=		Signals Support
SQLA14_DESC=		Use SQLAlchemy 1.4.*
SQLA20_DESC=		Use SQLAlchemy 2.0.*

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}betamax>=0:www/py-betamax@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Flask-Sphinx-Themes>=0:www/py-flask-sphinx-themes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-seqdiag>=0:textproc/py-sphinxcontrib-seqdiag@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-spelling>=0:textproc/py-sphinxcontrib-spelling@${PY_FLAVOR} \
			${RUN_DEPENDS}
SIGNALS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR}
SQLA14_BUILD_DEPENDS=	${SQLA14_RUN_DEPENDS}
SQLA14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR}
SQLA20_BUILD_DEPENDS=	${SQLA20_RUN_DEPENDS}
SQLA20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=0:databases/py-sqlalchemy20@${PY_FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MSQLA14}
DOCS_BUILD_DEPENDS+=	${SQLA14_RUN_DEPENDS}
.elif ${PORT_OPTIONS:MDOCS}
DOCS_BUILD_DEPENDS+=	${SQLA20_RUN_DEPENDS}
.endif

pre-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}; \
	${SETENVI} ${WRK_ENV} \
	sphinx-build-${PYTHON_VER} \
		-b html -d _build/doctress docs/ build/sphinx/html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv -and ! -name _images")

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	flask-babelex
PORTVERSION=	0.9.4
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-BabelEx-${DISTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Support i18n/l10n in Flask applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=1.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}speaklater>=1.2:devel/py-speaklater@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.5:devel/py-Jinja2@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} tests.py

.include <bsd.port.mk>

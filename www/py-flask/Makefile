PORTNAME=	flask
DISTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Micro web framework
WWW=		http://flask.pocoo.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=3.1:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=2.2:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.9:devel/py-blinker@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.10+
CPE_VENDOR=	palletsprojects
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC DOTENV
OPTIONS_DEFAULT=ASYNC DOTENV

ASYNC_DESC=	Enable async
ASYNC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.2:www/py-asgiref@${PY_FLAVOR}

DOTENV_DESC=	Enable dotenv
DOTENV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dotenv>=0:www/py-python-dotenv@${PY_FLAVOR}

.include <bsd.port.options.mk>

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>

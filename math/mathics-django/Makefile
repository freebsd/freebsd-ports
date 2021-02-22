# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	mathics-django
PORTVERSION=	2.0.1
CATEGORIES=	math python

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Django front-end to Mathics

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Mathics>0:math/py-mathics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django31>0:www/py-django31@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}Mathics>0:math/py-mathics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django31>0:www/py-django31@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Mathics3

USES=		python:3.6+ readline shebangfix
USE_PYTHON=	distutils
SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON=${PYTHON_CMD}
NO_ARCH=	yes
PLIST_SUB+=	VER=${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

do-test: install
	(cd ${TEST_WRKSRC} && PYTHONPATH=${WRKSRC}/mathics_django DJANGO_SETTINGS_MODULE=settings py.test)

.include <bsd.port.mk>

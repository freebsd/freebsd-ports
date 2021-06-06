# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	Mathics-Django
PORTVERSION=	2.2.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Django front-end to Mathics

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Mathics3>0:math/py-mathics	\
		${PYTHON_PKGNAMEPREFIX}django32>0:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Mathics3>0:math/py-mathics	\
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}django32>0:www/py-django32@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	Mathics3
#GH_PROJECT=	${PORTNAME:tl}

USES=		python:3.6+ readline shebangfix
USE_PYTHON=	distutils noflavors
SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON=${PYTHON_CMD}
NO_ARCH=	yes
PLIST_SUB+=	VER=${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

do-test: install
	(cd ${TEST_WRKSRC} && PYTHONPATH=${WRKSRC}/mathics_django DJANGO_SETTINGS_MODULE=settings py.test)

.include <bsd.port.mk>

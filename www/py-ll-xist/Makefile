PORTNAME=	ll-xist
DISTVERSION=	5.85
CATEGORIES=	www python
MASTER_SITES=	http://python-downloads.livinglogic.de/download/xist/ \
		PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/[-_.]+/_/g}-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	XML-based extensible HTML generator
WWW=		https://python.livinglogic.de/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=2.6.0,1:www/py-cssutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.3.4:devel/py-lxml@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}oracledb>0:databases/py-oracledb@${PY_FLAVOR}
#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}psycopg>0:databases/py-psycopg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython pep517
#USE_PYTHON+=	pytest

#USE_GITHUB=	yes
#GH_ACCOUNT=	LivingLogic
#GH_PROJECT=	LivingLogic.Python.xist
#GH_TAGNAME=	rel-5-85

#post-patch:
#	${REINPLACE_CMD} -e 's/pytest-reporter-html1//' ${WRKSRC}/pytest.ini

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/*.so ${STAGEDIR}${PYTHON_SITELIBDIR}/ll/xist/*.so

.include <bsd.port.mk>

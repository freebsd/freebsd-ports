PORTNAME=	honcho
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Managing Procfile-based applications tool
WWW=		https://github.com/nickstenning/honcho

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	nickstenning

# tests/integration/test_main.py needs to call the python command
# and run_honcho() in tests/contest.py requires running honcho
# from the ${STAGEDIR}
TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes

.include <bsd.port.mk>

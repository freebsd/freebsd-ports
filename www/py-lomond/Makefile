PORTNAME=	lomond
PORTVERSION=	0.3.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Websocket Client Library
WWW=		https://github.com/wildfoundry/dataplicity-lomond

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload -p pytest_mock \
		--ignore=${TEST_WRKSRC}/test_integration.py \
		--ignore=${TEST_WRKSRC}/test_live.py \
		--ignore=${TEST_WRKSRC}/test_proxy.py

post-extract:
	@${REINPLACE_CMD} -e 's|setup_requires=.*pytest-runner.*||' ${WRKSRC}/setup.py

# tests as of 0.3.4: 163 passed in 0.40s

.include <bsd.port.mk>

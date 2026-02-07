PORTNAME=	aiohttp-socks
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SOCKS proxy connector for aiohttp
WWW=		https://pypi.org/project/aiohttp-socks/ \
		https://github.com/romis2012/aiohttp-socks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.10.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socks>=2.4.3:net/py-python-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiny-proxy>0:net/py-tiny-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	romis2012
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

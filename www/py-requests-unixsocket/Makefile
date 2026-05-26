PORTNAME=	requests-unixsocket
PORTVERSION=	0.4.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	requests_unixsocket-${PORTVERSION}

MAINTAINER=	uros@gruber.si
COMMENT=	Use requests to talk HTTP via a UNIX domain socket
WWW=		https://github.com/msabramo/requests-unixsocket

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.1:www/py-requests@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	requests_unixsocket/tests/test_requests_unixsocket.py

.include <bsd.port.mk>

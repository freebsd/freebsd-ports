PORTNAME=	httpx-sse
DISTVERSION=	0.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Consume Server-Sent Event (SSE) messages with HTTPX
WWW=		https://pypi.python.org/pypi/httpx-sse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0.4:devel/py-setuptools-scm \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0_1:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.45.1:devel/py-wheel

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

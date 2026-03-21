PORTNAME=	baize
PORTVERSION=	0.23.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful and exquisite WSGI/ASGI framework/toolkit
WWW=		https://github.com/abersheeran/baize

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>

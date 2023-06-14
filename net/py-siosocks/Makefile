PORTNAME=	siosocks
PORTVERSION=	0.3.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Sans-io socks proxy client/server library/framework
WWW=		https://pypi.python.org/pypi/siosocks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-trio>=0:devel/py-pytest-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>

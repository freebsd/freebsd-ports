PORTNAME=	puremagic
PORTVERSION=	1.11
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	james@french.id.au
COMMENT=	Pure python implementation of magic file detection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7-3.9
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	cdgriffith

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts= test/

.include <bsd.port.mk>

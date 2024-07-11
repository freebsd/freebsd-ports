PORTNAME=	parsec
PORTVERSION=	3.17
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Universal Python parser combinator library
WWW=		https://github.com/sighingnow/parsec.py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

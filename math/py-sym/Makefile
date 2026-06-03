PORTNAME=	sym
DISTVERSION=	0.3.7
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unified wrapper for symbolic manipulation libraries in Python
WWW=		https://github.com/bjodah/sym

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/sym/tests

# tests as of 0.3.7: 117 passed, 3 warnings in 0.91s

.include <bsd.port.mk>

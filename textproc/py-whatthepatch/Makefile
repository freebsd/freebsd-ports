PORTNAME=	whatthepatch
PORTVERSION=	1.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Library for both parsing and applying patch files
WWW=		https://github.com/cscorley/whatthepatch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# make test: 1 failed, 48 passed
USES=		python
USE_PYTHON=	concurrent distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>

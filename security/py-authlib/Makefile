PORTNAME=	authlib
PORTVERSION=	1.0.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Authlib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.2:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

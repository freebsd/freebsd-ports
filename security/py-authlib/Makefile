# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	authlib
PORTVERSION=	0.15.4
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Authlib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CLIENT
OPTIONS_DEFAULT=CLIENT
CLIENT_DESC=	OAuth client support

CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>

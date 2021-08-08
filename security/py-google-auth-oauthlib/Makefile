# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-auth-oauthlib
PORTVERSION=	0.4.5
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=1.0.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

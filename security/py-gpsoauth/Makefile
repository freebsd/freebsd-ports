# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpsoauth
PORTVERSION=	0.1.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Python client library for Google Play Services OAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1

USE_GITHUB=	yes
GH_ACCOUNT=	simon-weber
GH_TAGNAME=	1f1ae3f

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oauth2client
PORTVERSION=	3.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 2.0 client library

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.1:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.7:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.0.5:devel/py-pyasn1-modules \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.4:security/py-rsa \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>

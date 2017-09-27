# $FreeBSD$

PORTNAME=	google-auth
PORTVERSION=	1.1.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Google Authentication Library

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>0:devel/py-pyasn1-modules \
		${PYTHON_PKGNAMEPREFIX}rsa>0:security/py-rsa \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

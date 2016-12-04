# $FreeBSD$

PORTNAME=	magic-wormhole
PORTVERSION=	0.8.0
CATEGORIES=	net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Get things from one computer to another, safely

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm \
		${PYTHON_PKGNAMEPREFIX}hkdf>0:security/py-hkdf \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.14.1:www/py-autobahn \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl \
		${PYTHON_PKGNAMEPREFIX}spake2>=0.7:security/py-spake2 \
		${PYTHON_PKGNAMEPREFIX}txaio>=2.5.1:devel/py-txaio

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

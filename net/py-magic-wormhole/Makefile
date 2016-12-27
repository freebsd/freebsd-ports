# $FreeBSD$

PORTNAME=	magic-wormhole
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Get things from one computer to another, safely

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autobahn>=0.14.1:www/py-autobahn \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}hkdf>0:security/py-hkdf \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize \
		${PYTHON_PKGNAMEPREFIX}idna>=0.6:dns/py-idna \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}spake2>=0.7:security/py-spake2 \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm \


USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

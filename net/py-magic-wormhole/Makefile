# $FreeBSD$

PORTNAME=	magic-wormhole
PORTVERSION=	0.10.5
CATEGORIES=	net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Get things from one computer to another, safely

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autobahn>=0.14.1:www/py-autobahn@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hkdf>0:security/py-hkdf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0.6:dns/py-idna@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spake2>=0.7:security/py-spake2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.13.0:misc/py-tqdm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=0.19.3:security/py-txtorcon@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

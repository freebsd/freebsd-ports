# $FreeBSD$

PORTNAME=	pynsca
PORTVERSION=	1.5
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rtd24@columbia.edu
COMMENT=	Python NSCA (Nagios Service Check Acceptor) library

LICENSE=	MPL11

OPTIONS_DEFINE=	AES 3DES

AES_DESC=	Provide AES encryption
AES_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}mcrypt>=0:security/py-mcrypt@${FLAVOR}

3DES_DESC=	Provide 3DES encryption
3DES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${FLAVOR}

OPTIONS_DEFAULT=AES 3DES

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils concurrent

.include <bsd.port.mk>

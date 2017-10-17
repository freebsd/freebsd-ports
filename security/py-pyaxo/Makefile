# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	pyaxo
PORTVERSION=	0.7.7
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Python implementation of the Axolotl ratchet protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=1.6.1:security/py-passlib \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>

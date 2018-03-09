# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	dkimpy
DISTVERSION=	0.7.1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Python library for DKIM email signing and verification

LICENSE=	ZLIB

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:mail/py-authres@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}milter>=0:mail/py-milter@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

.include <bsd.port.mk>

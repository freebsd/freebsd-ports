# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	nyx
PORTVERSION=	2.0.4
CATEGORIES=	security net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Command-line monitor for Tor

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}stem>1.5.0:security/py-stem \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USES=		python:2.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

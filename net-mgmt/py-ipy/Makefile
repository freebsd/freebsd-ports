# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipy
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python module for handling IPv4 and IPv6 Addresses and Networks

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

test: install
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>

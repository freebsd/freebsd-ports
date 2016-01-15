# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipy
PORTVERSION=	0.83
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for handling IPv4 and IPv6 Addresses and Networks

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>

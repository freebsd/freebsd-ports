# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipy
PORTVERSION=	1.00
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for handling IPv4 and IPv6 Addresses and Networks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>

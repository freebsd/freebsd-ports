# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipy
PORTVERSION=	0.83
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for handling IPv4 and IPv6 Addresses and Networks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

do-test:
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>

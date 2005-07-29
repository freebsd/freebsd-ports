# ex:ts=8
# Ports collection makefile for:	py-ipy
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	ipy
PORTVERSION=	0.42
CATEGORIES=	net-mgmt python
MASTER_SITES=	http://c0re.23.nu/c0de/IPy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	drt@un.bewaff.net
COMMENT=	A Python module for handling IPv4 and IPv6 Addresses and Networks

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

test: install
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>

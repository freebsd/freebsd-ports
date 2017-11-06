# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsdiag
PORTVERSION=	1.6.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	DNS Diagnostics and measurement tools (ping, traceroute)

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.15.0:dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}cymruwhois>=1.6:net/py-cymruwhois

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && !defined(PACKAGE_BUILDING_FLAVORS) && \
    ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>

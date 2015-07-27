# $FreeBSD$

PORTNAME=	nbxmpp
PORTVERSION=	0.5.3
CATEGORIES=	net-im devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Non blocking Jabber/XMPP module

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl

NO_ARCH=	yes
USES=		python:2 twisted:run
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

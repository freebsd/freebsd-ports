# $FreeBSD$

PORTNAME=	gmailfs-fuse
PORTVERSION=	0.8.6
CATEGORIES=	sysutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Use an IMAP server (like gmail) as normal storage

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fusefs>=0.2:devel/py-fusefs@${FLAVOR}

USES=		fuse python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>

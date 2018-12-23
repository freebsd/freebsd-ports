# $FreeBSD$

PORTNAME=	aiosmtpd
PORTVERSION=	1.2
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Asyncio based SMTP server

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atpublic>=0:devel/py-atpublic@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

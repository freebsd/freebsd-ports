# $FreeBSD$

PORTNAME=	user_agent
PORTVERSION=	0.1.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Generates random, valid User-Agent values

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

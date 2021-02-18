# $FreeBSD$

PORTNAME=	gvm-tools
DISTVERSION=	21.1.0
CATEGORIES=	security python
MASTER_SITES=   CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Greenbone Vulnerability Management Tools

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gvm>=0:security/py-python-gvm@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Flask-HTTPAuth
DISTVERSION=	3.3.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Basic and Digest HTTP authentication for Flask routes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

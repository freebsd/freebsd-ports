# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Flask-Script
PORTVERSION=	2.0.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scripting support for Flask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>

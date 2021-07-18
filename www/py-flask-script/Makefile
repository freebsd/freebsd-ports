# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	flask-script
PORTVERSION=	2.0.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-Script-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Scripting support for Flask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

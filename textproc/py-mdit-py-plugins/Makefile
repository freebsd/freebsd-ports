# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	mdit-py-plugins
PORTVERSION=	0.2.8
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of plugins for markdown-it-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-it-py>=1.0<2:textproc/py-markdown-it-py@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

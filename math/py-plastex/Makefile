PORTNAME=	plastex
PORTVERSION=	2.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	plasTeX-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LaTeX Document Processing Framework
WWW=		https://github.com/plastex/plastex

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}

USES=		python:3.5+ tex
USE_PYTHON=	autoplist concurrent distutils
USE_TEX=	base:run

NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	plastex
PORTVERSION=	2.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX Document Processing Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist
USE_TEX=	base:run

.include <bsd.port.mk>

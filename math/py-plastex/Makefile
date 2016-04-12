# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	plastex
PORTVERSION=	1.0.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX Document Processing Framework

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow

USE_GITHUB=	yes
GH_ACCOUNT=	tiarno

USES=		python
USE_PYTHON=	distutils autoplist
USE_TEX=	base:run

.include <bsd.port.mk>

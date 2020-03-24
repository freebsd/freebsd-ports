# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	plastex
PORTVERSION=	2.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	plasTeX-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LaTeX Document Processing Framework

LICENSE=	MIT

RUN_DEPENDS=	${PY_PILLOW}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
USE_TEX=	base:run

NO_ARCH=	yes

.include <bsd.port.mk>

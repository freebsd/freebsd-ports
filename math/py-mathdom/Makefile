# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mathdom
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP/source/m/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Content MathML in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>

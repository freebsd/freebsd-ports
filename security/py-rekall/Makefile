# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Memory forensics analysis framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rekall-core>=1.4.0:security/py-rekall-core \
		${PYTHON_PKGNAMEPREFIX}rekall_gui>=1.4.0:security/py-rekall_gui

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-wx
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Hachoir GUI

BROKEN=		unfetchable
DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-08

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:devel/hachoir-parser

USES=		python:2.7
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	python

.include <bsd.port.mk>

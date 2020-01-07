# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-subfile
PORTVERSION=	0.5.3
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Find subfiles in any binary stream

BROKEN=		unfetchable
DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-08

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:devel/hachoir-parser \
		${PYTHON_SITELIBDIR}/hachoir_regex/__init__.py:devel/hachoir-regex

USES=		python:2.7
USE_PYTHON=	distutils

.include <bsd.port.mk>

# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-urwid
PORTVERSION=	1.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Binary file explorer

BROKEN=		unfetchable
DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-08

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:devel/hachoir-parser \
		${PYTHON_SITELIBDIR}/urwid/__init__.py:devel/py-urwid@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils

.include <bsd.port.mk>

# New ports collection makefile for:	hachoir-urwid
# Date created:		25 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hachoir-urwid
PORTVERSION=	0.8.0
CATEGORIES=	sysutils python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/h/${PORTNAME}/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Binary file explorer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:${PORTSDIR}/devel/hachoir-parser \
		${PYTHON_SITELIBDIR}/urwid/__init__.py:${PORTSDIR}/devel/py-urwid

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>

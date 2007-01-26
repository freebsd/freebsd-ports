# New ports collection makefile for:	hachoir-wx
# Date created:		25 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hachoir-wx
PORTVERSION=	0.1.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/h/${PORTNAME}/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Hachoir GUI

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:${PORTSDIR}/devel/hachoir-parser

USE_PYTHON=	yes
USE_WX=		yes
WX_COMPS=	python
WX_UNICODE=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>

# New ports collection makefile for:	xyzcmd
# Date created:		2010-01-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	xyzcmd
PORTVERSION=	0.0.3
CATEGORIES=	misc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Pure console visual file manager

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/urwid/raw_display.py:${PORTSDIR}/devel/py-urwid
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/urwid/raw_display.py:${PORTSDIR}/devel/py-urwid

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes

.include <bsd.port.mk>

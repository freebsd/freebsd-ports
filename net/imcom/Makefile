# New ports collection makefile for:	imcom
# Date created:				Jun 09 2002
# Whom:					Martijn Lina
#
# $FreeBSD$

PORTNAME=	imcom
PORTVERSION=	1.31
CATEGORIES=	net
MASTER_SITES=	http://nafai.dyndns.org/files/

MAINTAINER=	martijn@pacno.net
COMMENT=	IMCom is a command-line Jabber client written in Python

RUN_DEPENDS=	${LOCALBASE}/lib/python2.2/xml/parsers/expat.py:${PORTSDIR}/textproc/py-expat

GNU_CONFIGURE=	yes
USE_PYTHON=	yes

MAN1=		imcom.1

.include <bsd.port.mk>

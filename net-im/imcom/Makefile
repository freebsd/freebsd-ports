# New ports collection makefile for:	imcom
# Date created:				Jun 09 2002
# Whom:					Martijn Lina
#
# $FreeBSD$

PORTNAME=	imcom
PORTVERSION=	1.30.b8
CATEGORIES=	net
MASTER_SITES=	http://nafai.dyndns.org/files/imcom-betas/
DISTNAME=	${PORTNAME}-1.30beta8

MAINTAINER=	martijn@pacno.net
COMMENT=	IMCom is a command-line Jabber client written in Python

RUN_DEPENDS=	${LOCALBASE}/lib/python2.2/xml/parsers/expat.py:${PORTSDIR}/textproc/py-expat

GNU_CONFIGURE=	yes
USE_PYTHON=	yes

MAN1=		imcom.1

pre-install:
	@cd ${WRKSRC} ; \
	${RM} -rf docs/CVS; \
	${RM} -rf docs/*~

.include <bsd.port.mk>

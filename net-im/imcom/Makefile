# New ports collection makefile for:	imcom
# Date created:				Jun 09 2002
# Whom:					Martijn Lina
#
# $FreeBSD$

PORTNAME=	imcom
PORTVERSION=	1.34
CATEGORIES=	net
MASTER_SITES=	http://nafai.dyndns.org/files/
#Main Site Down:	http://imcom.floobin.cx/files/

MAINTAINER=	martijn@pacno.net
COMMENT=	IMCom is a command-line Jabber client written in Python

BUILD_DEPENDS=	${PYEXPAT}
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PYTHON=	yes

MAN1=		imcom.1

.include <bsd.port.mk>

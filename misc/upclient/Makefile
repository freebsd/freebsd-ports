# New ports collection makefile for:	upclient
# Date created:		20 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	upclient
PORTVERSION=	3.04
CATEGORIES=	misc
MASTER_SITES=	http://uptime.hexon.cx/download/

MAINTAINER=	kbyanc@posi.net

BROKEN=		Client is outdated and new client cannot be reasonably ported

ALL_TARGET=	bsd
INSTALL_TARGET=	bsd install CP=$(CP)

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} 's:/usr/local:${PREFIX}:g'

.include <bsd.port.mk>

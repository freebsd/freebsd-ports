# New ports collection makefile for:	redir
# Date created:			Apr 10, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	redir
PORTVERSION=	2.2.1
CATEGORIES=	net
MASTER_SITES=	http://sammy.net/~sammy/hacks/

MAINTAINER=	mark@kyne.com.au

MAN1=		redir.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redir ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/redir.man ${PREFIX}/man/man1/redir.1

.include <bsd.port.mk>

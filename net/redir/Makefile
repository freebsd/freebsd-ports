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

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A tcp connection redirection utility

MAN1=		redir.1
PLIST_FILES=	bin/redir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redir ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/redir.man ${PREFIX}/man/man1/redir.1

.include <bsd.port.mk>

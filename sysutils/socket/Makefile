# New ports collection makefile for: socket
# Date created:         14 August 1996
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	socket
PORTVERSION=	1.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.de.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org

MAN1=		socket.1

post-install:

	@${MKDIR} ${PREFIX}/share/doc/socket
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/socket

.include <bsd.port.mk>

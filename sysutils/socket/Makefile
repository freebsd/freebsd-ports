# New ports collection makefile for: socket
# Date created:         14 August 1996
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	socket
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils net ipv6
MASTER_SITES=	http://wolfram.schneider.org/src/

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	Create tcp socket and connect to stdin/out

MAKE_ENV+=	SWITCHES="-DUSE_INET6 -DHAVE_SYS_PARAM_H -Wall"
MAN1=		socket.1

post-install:

	@${MKDIR} ${PREFIX}/share/doc/socket
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/socket

.include <bsd.port.mk>

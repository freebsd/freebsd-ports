# New ports collection makefile for:	ipcad
# Date created:				15 April 2001
# Whom:					vlm@spelio.net.ru
#
# $FreeBSD$
#

PORTNAME=	ipcad
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	http://www.spelio.net.ru/soft/

MAINTAINER=	vlm@spelio.net.ru

post-install:
	strip ${PREFIX}/bin/ipcad
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ipcad
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/ipcad
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	ipcad
# Date created:				15 April 2001
# Whom:					Lev Walkin <vlm@spelio.net.ru>
#
# $FreeBSD$
#

PORTNAME=	ipcad
PORTVERSION=	2.6.3
CATEGORIES=	net
MASTER_SITES=	http://www.spelio.net.ru/soft/

MAINTAINER=	vlm@spelio.net.ru

MANCOMPRESSED=	no
MAN5=	ipcad.conf.5
MAN8=	ipcad.8

post-install:
	strip ${PREFIX}/bin/ipcad
	${INSTALL_MAN} ${WRKSRC}/ipcad.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/ipcad.conf.5 ${PREFIX}/man/man5

.include <bsd.port.mk>

# New ports collection makefile for:	cyrproxy
# Date created:				20 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		cyrproxy
PORTVERSION=		1.4.2.20010208
CATEGORIES=		russian net www
MASTER_SITES=		ftp://ftp.lexa.ru/pub/domestic/lexa/
DISTNAME=		cyrproxy-1.4.2

MAINTAINER=		ports@FreeBSD.org

PORTCOMMENT=	Cyrillic proxy for network protocols

do-install:
	@ ${MKDIR} ${PREFIX}/share/cyrproxy
	@ ${MKDIR} ${PREFIX}/www/cgi-bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrproxy ${PREFIX}/libexec
	@ ${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${PREFIX}/libexec
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrtrans ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/discover/discover ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrwww ${PREFIX}/www/cgi-bin
	@ ${INSTALL_DATA} ${WRKSRC}/config.gen ${PREFIX}/etc/cyrproxy.conf.sample
.for file in alt-iso alt-koi8 alt-win iso-alt iso-koi8 iso-win koi8-alt koi8-iso koi8-mac koi8-win mac-koi8 win-alt win-iso win-koi8
	@ ${INSTALL_DATA} ${WRKSRC}/tables/${file} ${PREFIX}/share/cyrproxy
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cyrproxy

.for file in History README README.http
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cyrproxy
.endfor
.endif

.include <bsd.port.mk>

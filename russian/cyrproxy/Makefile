# New ports collection makefile for:	cyrproxy
# Version required:			1.4.2
# Date created:				20 May 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1997/10/23 13:38:44 itojun Exp $
#

DISTNAME=		cyrproxy-1.4.2
CATEGORIES=		russian net www
MASTER_SITES=		ftp://ftp.lexa.ru/pub/domestic/lexa/

MAINTAINER=		andy@icc.surw.chel.su

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

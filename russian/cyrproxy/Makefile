# New ports collection makefile for:	cyrproxy
# Version required:			1.4.1
# Date created:				20 May 1997
# Whom:					Andrey Zakhvatov
#

DISTNAME=		cyrproxy-1.4.1
CATEGORIES=		russian net www
MASTER_SITES=		ftp://ftp.lexa.ru/pub/domestic/lexa/

MAINTAINER=		andy@icc.surw.chel.su

do-install:
	@ ${MKDIR} ${PREFIX}/etc/cyrproxy
	@ ${MKDIR} ${PREFIX}/share/cyrproxy
	@ ${MKDIR} ${PREFIX}/share/doc/cyrproxy
	@ ${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/cyrproxy ${PREFIX}/libexec/cyrproxy
	${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${PREFIX}/libexec/tcpspy
	${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrtrans ${PREFIX}/bin/cyrtrans
#        ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/transfiles ${PREFIX}/bin/transfiles
#        ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/transtree ${PREFIX}/bin/transtree
	${INSTALL_PROGRAM} ${WRKSRC}/discover/discover ${PREFIX}/bin/discover
	${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrwww ${PREFIX}/www/cgi-bin/cyrwww
	${INSTALL_DATA} ${WRKSRC}/config.gen ${PREFIX}/etc/cyrproxy/cyrproxy.conf.sample
.for file in alt-iso alt-koi8 alt-win iso-alt iso-koi8 iso-win koi8-alt koi8-iso koi8-mac koi8-win mac-koi8 win-alt win-iso win-koi8
	${INSTALL_DATA} ${WRKSRC}/tables/${file} ${PREFIX}/share/cyrproxy/${file}
.endfor
.for file in History README README.http
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cyrproxy/${file}
.endfor

.include <bsd.port.mk>

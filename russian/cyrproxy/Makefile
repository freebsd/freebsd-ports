# New ports collection makefile for:	cyrproxy
# Date created:				20 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cyrproxy
PORTVERSION=	1.4.2.20010208
PORTREVISION=	2
CATEGORIES=	russian net www
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/lexa/
DISTNAME=	cyrproxy-1.4.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cyrillic proxy for network protocols

post-extract:
	@ ${RM} ${WRKSRC}/discover/discover

do-install:
	@ ${MKDIR} ${DATADIR}
	@ ${MKDIR} ${PREFIX}/www/cgi-bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrproxy ${PREFIX}/libexec
	@ ${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${PREFIX}/libexec
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrtrans ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/discover/discover ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrcoder/cyrwww ${PREFIX}/www/cgi-bin
	@ ${INSTALL_DATA} ${WRKSRC}/config.gen ${PREFIX}/etc/cyrproxy.conf.sample
.for f in alt-iso alt-koi8 alt-win iso-alt iso-koi8 iso-win koi8-alt koi8-iso \
		koi8-mac koi8-win mac-koi8 win-alt win-iso win-koi8
	@ ${INSTALL_DATA} ${WRKSRC}/tables/${f} ${DATADIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for f in History README README.http
	@ ${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

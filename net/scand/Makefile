# New ports collection makefile for:  scand
# Date created:        13 May 2003
# Whom:                sand
#
# $FreeBSD$
#

PORTNAME=	scand
PORTVERSION=	0.11
CATEGORIES=	net
MASTER_SITES=	http://free.babolo.ru/src/

MAINTAINER=	sand@links.ru
COMMENT=	Scan detection and blocking daemon

MAN8=		scand.8 scandctl.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/scandctl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scand.8.gz ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/scandctl.8.gz ${MANPREFIX}/man/man8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README README.ru
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

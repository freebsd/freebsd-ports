# New ports collection makefile for:	antiword
# Date created:				8 June 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	antiword
PORTVERSION=	0.31
CATEGORIES=	textproc
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

MAN1=		antiword.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/antiword ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/kantiword ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/Docs/antiword.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/antiword
.for file in COPYING ChangeLog FAQ History Netscape QandA ReadMe
	@${INSTALL_DATA} ${WRKSRC}/Docs/${file} ${PREFIX}/share/doc/antiword
.endfor
.endif

.include <bsd.port.mk>

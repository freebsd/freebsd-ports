# Ports collection makefile for:  amap
# Date created:			  23 Mar  2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	amap
PORTVERSION=	4.5
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Application mapper

HAS_CONFIGURE=	yes

MAN1=		amap.1
PORTDOCS=	README TODO CHANGES VOTE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/amap
.	for i in appdefs.resp appdefs.rpc appdefs.trig
		${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/amap
.	endfor
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${MANPREFIX}/man/man1
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.		for i in ${PORTDOCS}
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.mk>

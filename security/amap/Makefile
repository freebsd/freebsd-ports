# Ports collection makefile for:  amap
# Date created:			  23 Mar  2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	amap
PORTVERSION=	4.2
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Application mapper

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		amap.1

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|' ${WRKSRC}/amap.h

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
.		for i in README TODO CHANGES LICENSE IGNORE VOTE
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.mk>

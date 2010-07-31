# New ports collection makefile for:	pstotext
# Date created:		December 6, 1999
# Whom:			Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$
#

PORTNAME=	pstotext
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://mirror.cs.wisc.edu/pub/mirrors/ghost/contrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PostScript to Text converter

USE_GHOSTSCRIPT_RUN=	yes

MAN1=		pstotext.1
PLIST_FILES=	bin/pstotext
PORTDOCS=	copyright

post-patch:
	${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g' ${WRKSRC}/main.c
	${REINPLACE_CMD} -e 's;%%PREFIX%%;${PREFIX};g' ${WRKSRC}/pstotext.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstotext.1 ${MAN1PREFIX}/man/man1
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pstotext.txt ${DOCSDIR}/copyright
.endif

.include <bsd.port.mk>

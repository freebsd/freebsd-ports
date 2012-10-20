# Created by: Oliver Breuninger <ob@seicom.NET>
# $FreeBSD$

PORTNAME=	pstotext
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/ghostscript/contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript to Text converter

USE_GHOSTSCRIPT_RUN=	yes

MAN1=		pstotext.1
PLIST_FILES=	bin/pstotext
PORTDOCS=	copyright

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's;%%LOCALBASE%%;${LOCALBASE};g' ${WRKSRC}/main.c
	${REINPLACE_CMD} -e 's;%%PREFIX%%;${PREFIX};g' ${WRKSRC}/pstotext.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstotext.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pstotext.txt ${DOCSDIR}/copyright
.endif

.include <bsd.port.mk>

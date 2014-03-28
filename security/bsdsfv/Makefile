# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bsdsfv
PORTVERSION=	1.18
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Flexible SFV checksum utility

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/bsdsfv
PORTDOCS=	MANUAL

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^\(INSTALL_PREFIX =\).*$$|\1 ${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

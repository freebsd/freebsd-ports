PORTNAME=	filetype
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pldaniels.com/filetype/

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	New file-type detection system
WWW=		https://www.pldaniels.com/filetype/

PORTDOCS=	README CHANGELOG CONTRIBUTORS INSTALL LICENSE TODO

PLIST_FILES=	bin/filetype share/man/man1/filetype-compile.1.gz \
		share/man/man1/filetype.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filetype ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/filetype.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/filetype-compile.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

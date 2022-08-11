PORTNAME=	filetype
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pldaniels.com/filetype/

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	New file-type detection system

PORTDOCS=	README CHANGELOG CONTRIBUTORS INSTALL LICENSE TODO

PLIST_FILES=	bin/filetype man/man1/filetype-compile.1.gz \
		man/man1/filetype.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filetype ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/filetype.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/filetype-compile.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

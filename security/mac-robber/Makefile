PORTNAME=	mac-robber
PORTVERSION=	1.02
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	Tool for listing Modify, Access, Create timestamps from files

LICENSE=	GPLv2

PLIST_FILES=	bin/mac-robber
PORTDOCS=	CHANGES README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o mac-robber mac-robber.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

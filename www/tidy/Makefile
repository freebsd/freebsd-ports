PORTNAME=	tidy4
PORTVERSION=	20000804
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
DISTNAME=	tidy4aug00

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fixes and tidies up HTML files
WWW=		https://www.w3.org/People/Raggett/tidy/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${FILESDIR}/COPYRIGHT

USES=		tar:tgz
ALL_TARGET=	tidy
PLIST_FILES=	bin/tidy4 share/man/man1/tidy4.1.gz
PORTDOCS=	Overview.html tidy.gif release-notes.html grid.gif

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} -e 's|tidy|tidy4|' ${WRKSRC}/man_page.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tidy ${STAGEDIR}${PREFIX}/bin/tidy4
	${INSTALL_MAN} ${WRKSRC}/man_page.txt \
		${STAGEDIR}${PREFIX}/share/man/man1/tidy4.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

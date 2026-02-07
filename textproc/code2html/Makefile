PORTNAME=	code2html
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF \
		http://www.palfrader.org/code2html/all/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Source code to HTML converter
WWW=		https://www.palfrader.org/code2html/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	code2html

PLIST_FILES=	bin/code2html share/man/man1/code2html.1.gz
PORTDOCS=	CREDITS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/bzip2|${BZIP2_CMD}|' \
		-e 's|/bin/gzip|${GZIP_CMD:[1]}|' \
		-e 's|/etc/|${PREFIX}&|' \
		${WRKSRC}/code2html
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}&|' \
		${WRKSRC}/code2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

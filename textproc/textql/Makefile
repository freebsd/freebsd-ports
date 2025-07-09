PORTNAME=	textql
PORTVERSION=	g20210706
PORTREVISION=	21
CATEGORIES=	textproc

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Execute SQL against structured text like CSV or TSV
WWW=		https://github.com/dinedal/textql/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	dinedal
GH_TAGNAME=	fca00ec
GH_TUPLE=	mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		olekukonko:tablewriter:d4647c9c7a84:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter

GO_TARGET=	textql/main.go:textql

PLIST_FILES=	bin/textql \
		share/man/man1/textql.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/textql.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

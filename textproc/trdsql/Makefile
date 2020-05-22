# $FreeBSD$

PORTNAME=	trdsql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	Execute SQL queries on CSV, LTSV, JSON and TBLN

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	noborus
GH_TUPLE=	dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		golang:crypto:4b2356b1ed79:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:6aff5f38e54f:golang_sys/vendor/golang.org/x/sys \
		klauspost:compress:v1.10.5:klauspost_compress/vendor/github.com/klauspost/compress \
		lib:pq:v1.5.2:lib_pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:e9ef32dff381:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		noborus:tbln:v0.0.1:noborus_tbln/vendor/github.com/noborus/tbln \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/vendor/github.com/ulikunitz/xz

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

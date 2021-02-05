# $FreeBSD$

PORTNAME=	trdsql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Execute SQL queries on CSV, LTSV, JSON and TBLN

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	noborus
GH_TUPLE=	dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		iancoleman:orderedmap:v0.2.0:iancoleman_orderedmap/vendor/github.com/iancoleman/orderedmap \
		klauspost:compress:v1.11.7:klauspost_compress/vendor/github.com/klauspost/compress \
		lib:pq:v1.9.0:lib_pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.6:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		noborus:tbln:v0.0.1:noborus_tbln/vendor/github.com/noborus/tbln \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		ulikunitz:xz:v0.5.9:ulikunitz_xz/vendor/github.com/ulikunitz/xz

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

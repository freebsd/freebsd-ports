PORTNAME=	kepubify
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
CATEGORIES=	textproc converters

MAINTAINER=	fuz@fuz.su
COMMENT=	EPUB to KEPUB converter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pgaskin
GH_TUPLE=	bamiaux:rez:29f4463c688b:bamiaux_rez/vendor/github.com/bamiaux/rez \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		hexops:gotextdiff:v1.0.3:hexops_gotextdiff/vendor/github.com/hexops/gotextdiff \
		kr:smartypants:v0.1.0:kr_smartypants/vendor/github.com/kr/smartypants \
		mattn:go-sqlite3:v1.14.8:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		pgaskin:kepubify:2d89b3182523:pgaskin_kepubify_go116_zip_go117/vendor/github.com/pgaskin/kepubify \
		pgaskin:kepubify:337924fbbaf0:pgaskin_kepubify_html \
		pgaskin:koboutils:v2.1.1:pgaskin_koboutils_v2/vendor/github.com/pgaskin/koboutils/v2 \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./cmd/covergen ./cmd/kepubify ./cmd/seriesmeta
GO_BUILDFLAGS=	-tags zip117 -ldflags '-X main.version=${DISTVERSIONPREFIX}${DISTVERSION}'
PLIST_FILES=	bin/covergen \
		bin/kepubify \
		bin/seriesmeta

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/pgaskin/kepubify/_/html
	@${RLN} ${WRKSRC_pgaskin_kepubify_html}/_/html ${WRKSRC}/vendor/github.com/pgaskin/kepubify/_/html

.include <bsd.port.mk>

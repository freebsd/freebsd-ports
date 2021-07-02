PORTNAME=	kepubify
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.6
CATEGORIES=	textproc

MAINTAINER=	fuz@fuz.su
COMMENT=	EPUB to KEPUB converter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pgaskin
GH_TUPLE=	andybalholm:cascadia:v1.2.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		bamiaux:rez:29f4463c688b:bamiaux_rez/vendor/github.com/bamiaux/rez \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		golang:sync:b3e1573b7520:golang_sync/vendor/golang.org/x/sync \
		kr:smartypants:v0.1.0:kr_smartypants/vendor/github.com/kr/smartypants \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		pgaskin:koboutils:v2.1.1:pgaskin_koboutils_v2/vendor/github.com/pgaskin/koboutils/v2 \
		pgaskin:net:0135d2310fe0:pgaskin_net/vendor/golang.org/x/net \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag
GO_TARGET=	./cmd/covergen ./cmd/kepubify ./cmd/seriesmeta

PLIST_FILES=	bin/covergen \
		bin/kepubify \
		bin/seriesmeta

.include <bsd.port.mk>

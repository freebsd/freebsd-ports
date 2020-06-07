# $FreeBSD$

PORTNAME=	annie
DISTVERSION=	0.10.1
CATEGORIES=	www

MAINTAINER=	vulcan@wired.sh
COMMENT=	Fast, simple and clean video downloader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	iawia002
GH_TUPLE=	MercuryEngineering:CookieMonster:1584578b3403:mercuryengineering_cookiemonster/vendor/github.com/MercuryEngineering/CookieMonster \
		PuerkitoBio:goquery:v1.4.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		cheggaaa:pb:v1.0.25:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:sys:e8c54fb511f6:golang_sys/vendor/golang.org/x/sys \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.6:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mihaiav:ytdl:5f2bf8b4fec0:mihaiav_ytdl/vendor/github.com/rylio/ytdl \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		rs:zerolog:v1.16.0:rs_zerolog/vendor/github.com/rs/zerolog \
		tidwall:gjson:v1.3.2:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

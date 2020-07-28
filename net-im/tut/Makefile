# $FreeBSD$

PORTNAME=	tut
DISTVERSION=	0.0.16
CATEGORIES=	net-im

MAINTAINER=	vulcan@wired.sh
COMMENT=	TUI for Mastodon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	RasmusLindroth
GH_TUPLE=	aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		chris-ramon:douceur:v0.2.0:chris_ramon_douceur \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.3.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		kyoh86:xdg:v1.2.0:kyoh86_xdg/vendor/github.com/kyoh86/xdg \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-mastodon:315df7d9162e:mattn_go_mastodon/vendor/github.com/mattn/go-mastodon \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.3:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		rivo:tview:c65badfc3d92:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

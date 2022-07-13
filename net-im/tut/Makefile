PORTNAME=	tut
DISTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	TUI for Mastodon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	RasmusLindroth
GH_TUPLE=	RasmusLindroth:go-mastodon:v0.0.8:rasmuslindroth_go_mastodon/vendor/github.com/RasmusLindroth/go-mastodon \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.1:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		gen2brain:beeep:d7852edf42fc:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-ini:ini:v1.66.6:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-toast:toast:01e6764cf0a4:go_toast_toast/vendor/github.com/go-toast/toast \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:net:c960675eff93:golang_net/vendor/golang.org/x/net \
		golang:sys:bc2c85ada10a:golang_sys/vendor/golang.org/x/sys \
		golang:term:065cf7ba2467:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		icza:gox:e2d488ab2fbc:icza_gox/vendor/github.com/icza/gox \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.18:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pelletier:go-toml:v2.0.1:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		rivo:tview:9994674d60a8:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	config.example.ini

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

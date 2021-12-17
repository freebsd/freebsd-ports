PORTNAME=	tut
DISTVERSION=	0.0.42
CATEGORIES=	net-im

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	TUI for Mastodon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	RasmusLindroth
GH_TUPLE=	atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:f057f0a857a1:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		gen2brain:beeep:5586760f0cc1:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-ini:ini:v1.66.2:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-toast:toast:01e6764cf0a4:go_toast_toast/vendor/github.com/go-toast/toast \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		godbus:dbus:v5.0.6:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:net:4852103109b8:golang_net/vendor/golang.org/x/net \
		golang:sys:fe61309f8881:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		gopherjs:gopherjs:d0d5ecc1a356:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:gopherwasm:v1.1.0:gopherjs_gopherwasm/vendor/github.com/gopherjs/gopherwasm \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		icza:gox:cd40a3f8d324:icza_gox/vendor/github.com/icza/gox \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-mastodon:58c389181352:mattn_go_mastodon/vendor/github.com/mattn/go-mastodon \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.16:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pelletier:go-toml:v2.0.0-beta.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		rivo:tview:2a6de950f73b:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	toot.tmpl

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

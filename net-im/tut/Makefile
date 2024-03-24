PORTNAME=	tut
DISTVERSION=	2.0.1
PORTREVISION=	5
CATEGORIES=	net-im

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	TUI for Mastodon
WWW=		https://tut.anv.nu/

DEPRECATED=Requires deprecated lang/go119
EXPIRATION_DATE=2024-04-24

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.19,modules
USE_GITHUB=	yes
GH_ACCOUNT=	RasmusLindroth
GH_TUPLE=	RasmusLindroth:go-mastodon:v0.0.21:rasmuslindroth_go_mastodon/vendor/github.com/RasmusLindroth/go-mastodon \
		adrg:xdg:v0.4.0:adrg_xdg/vendor/github.com/adrg/xdg \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.4:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		gen2brain:beeep:5a9ec94374f6:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-toast:toast:01e6764cf0a4:go_toast_toast/vendor/github.com/go-toast/toast \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:exp:b3c2aaf6208d:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.5.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.4.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.6.0:golang_text/vendor/golang.org/x/text \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		icza:gox:93f961aa2755:icza_gox/vendor/github.com/icza/gox \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.21:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mvdan:xurls:v2.4.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		rivo:tview:892d1a2eb0da:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.4.3:rivo_uniseg/vendor/github.com/rivo/uniseg \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	config.example.toml

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

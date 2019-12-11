# $FreeBSD$

PORTNAME=	6cord
DISTVERSION=	9.5
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	vulcan@wired.sh
COMMENT=	Terminal-driven Discord client

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	nodefault
GH_TUPLE=	BurntSushi:freetype-go:b763ddbfe298:burntsushi_freetype_go/vendor/github.com/BurntSushi/freetype-go \
		BurntSushi:graphics-go:b43f31a4a966:burntsushi_graphics_go/vendor/github.com/BurntSushi/graphics-go \
		BurntSushi:xgb:27f122750802:burntsushi_xgb/vendor/github.com/BurntSushi/xgb \
		BurntSushi:xgbutil:ad855c713046:burntsushi_xgbutil/vendor/github.com/BurntSushi/xgbutil \
		alecthomas:chroma:v0.6.7:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		danieljoos:wincred:v1.0.2:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		diamondburned:discordgo:v1.2.1:diamondburned_discordgo/vendor/github.com/diamondburned/discordgo \
		diamondburned:go-colorful:238d3721526c:diamondburned_go_colorful/vendor/github.com/diamondburned/go-colorful \
		diamondburned:tcell:v1.1.8:diamondburned_tcell/vendor/github.com/diamondburned/tcell \
		diamondburned:tview:v2.4.0:diamondburned_tview/vendor/github.com/diamondburned/tview/v2 \
		disintegration:imaging:v1.6.1:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gen2brain:beeep:ece0cb67ca77:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-test:deep:v1.0.3:go_test_deep/vendor/github.com/go-test/deep \
		go-toast:toast:0a84660828b2:go_toast_toast/vendor/gopkg.in/toast.v1 \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:httphead:2c6c146eadee:gobwas_httphead/vendor/github.com/gobwas/httphead \
		gobwas:pool:v0.2.0:gobwas_pool/vendor/github.com/gobwas/pool \
		gobwas:ws:v1.0.2:gobwas_ws/vendor/github.com/gobwas/ws \
		godbus:dbus:v4.1.0:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:e7c1f5e7dbb8:golang_image/vendor/golang.org/x/image \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gopherjs:gopherjs:d3ddacdb130f:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:gopherwasm:v1.1.0:gopherjs_gopherwasm/vendor/github.com/gopherjs/gopherwasm \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.9.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-retryablehttp:v0.6.2:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		jonas747:gojay:b3bd5c8fcd50:jonas747_gojay/vendor/github.com/jonas747/gojay \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sixel:v0.0.1:mattn_go_sixel/vendor/github.com/mattn/go-sixel \
		mattn:go-tty:523744f04859:mattn_go_tty/vendor/github.com/mattn/go-tty \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pelletier:go-toml:v1.5.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		soniakeys:quant:v1.0.0:soniakeys_quant/vendor/github.com/soniakeys/quant \
		stevenroose:gonfig:v0.1.4:stevenroose_gonfig/vendor/github.com/stevenroose/gonfig \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.1.0:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate \
		zalando:go-keyring:62750a1ff80d:zalando_go_keyring/vendor/github.com/zalando/go-keyring

USE_GITLAB=	yes
GL_ACCOUNT=	diamondburned
GL_COMMIT=	0e534fe84bf5430d99309e50b213002ae545a8a1
GL_TUPLE=	diamondburned:go-w3m:1b390b8a3d1fd142bcaf77a949223cb36ef84cbc:diamondburned_go_w3m/vendor/gitlab.com/diamondburned/go-w3m \
		diamondburned:ueberzug-go:7c15a5f63b064530b92411f2850d0fc7fe9059ea:diamondburned_ueberzug_go/vendor/gitlab.com/diamondburned/ueberzug-go

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md
PORTEXAMPLES=	${PORTNAME}.toml

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_DESC=	Install example ${PORTNAME} configuration file

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

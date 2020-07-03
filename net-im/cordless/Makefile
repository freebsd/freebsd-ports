# $FreeBSD$

PORTNAME=	cordless
DISTVERSION=	2020-01-05
CATEGORIES=	net-im

MAINTAINER=	vulcan@wired.sh
COMMENT=	Discord TUI client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Bios-Marcel
GH_TUPLE=	Bios-Marcel:discordemojimap:v1.0.1:bios_marcel_discordemojimap/vendor/github.com/Bios-Marcel/discordemojimap \
		Bios-Marcel:discordgo:8703d1772aea:bios_marcel_discordgo/vendor/github.com/Bios-Marcel/discordgo \
		Bios-Marcel:femto:a733a9347742:bios_marcel_femto/vendor/github.com/Bios-Marcel/femto \
		Bios-Marcel:goclipimg:d0f7b06fbe82:bios_marcel_goclipimg/vendor/github.com/Bios-Marcel/goclipimg \
		Bios-Marcel:shortnotforlong:v1.0.0:bios_marcel_shortnotforlong/vendor/github.com/Bios-Marcel/shortnotforlong \
		Bios-Marcel:tview:82f4aa41eebe:bios_marcel_tview/vendor/github.com/Bios-Marcel/tview \
		alecthomas:chroma:v0.6.6:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.1.6:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:b6a97de0c118:gdamore_tcell/vendor/github.com/gdamore/tcell \
		gen2brain:beeep:aa3d7c1499fd:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-toast:toast:0a84660828b2:go_toast_toast/vendor/gopkg.in/toast.v1 \
		godbus:dbus:v4.1.0:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:c709ea063b76:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-github:v28.1.1:google_go_github/vendor/github.com/google/go-github/v28 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gopherjs:gopherjs:0210a2f0f73c:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:gopherwasm:v1.1.0:gopherjs_gopherwasm/vendor/github.com/gopherjs/gopherwasm \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mdp:qrterminal:v3.0.0:mdp_qrterminal/vendor/github.com/mdp/qrterminal/v3 \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robertkrimen:otto:15f95af6e78d:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	cordless
DISTVERSION=	2020-10-24
CATEGORIES=	net-im

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Discord TUI client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# See: https://github.com/Bios-Marcel/cordless#i-am-closing-down-the-cordless-project
DEPRECATED=	Unmaintained and dead upstream, uses the old Discord API which notably has got users banned
EXPIRATION_DATE=	2021-04-22

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Bios-Marcel
GH_TUPLE=	\
		Bios-Marcel:discordemojimap:v1.0.1:bios_marcel_discordemojimap/vendor/github.com/Bios-Marcel/discordemojimap \
		Bios-Marcel:discordgo:5060bbaaa5a2:bios_marcel_discordgo/vendor/github.com/Bios-Marcel/discordgo \
		Bios-Marcel:goclipimg:d0f7b06fbe82:bios_marcel_goclipimg/vendor/github.com/Bios-Marcel/goclipimg \
		Bios-Marcel:shortnotforlong:v1.1.1:bios_marcel_shortnotforlong/vendor/github.com/Bios-Marcel/shortnotforlong \
		alecthomas:chroma:v0.6.6:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.0.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		gen2brain:beeep:e9c15c258e28:gen2brain_beeep/vendor/github.com/gen2brain/beeep \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-toast:toast:01e6764cf0a4:go_toast_toast/vendor/github.com/go-toast/toast \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:crypto:8e1b8d32e692:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:669c56c373c4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-github:v29.0.3:google_go_github_v29/vendor/github.com/google/go-github/v29 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gopherjs:gopherjs:0210a2f0f73c:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:gopherwasm:v1.1.0:gopherjs_gopherwasm/vendor/github.com/gopherjs/gopherwasm \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mdp:qrterminal:v3.0.0:mdp_qrterminal_v3/vendor/github.com/mdp/qrterminal/v3 \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		tadvi:systray:11a2b8fa57af:tadvi_systray/vendor/github.com/tadvi/systray

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

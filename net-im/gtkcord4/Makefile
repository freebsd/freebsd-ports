PORTNAME=	gtkcord4
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.11-1
CATEGORIES=	net-im

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Discord client written in go and gtk4
WWW=		https://github.com/diamondburned/gtkcord4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40 libadwaita
GH_ACCOUNT=	diamondburned
GH_TUPLE=	alecthomas:chroma:v0.10.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alessio:shellescape:v1.4.1:alessio_shellescape/vendor/github.com/alessio/shellescape \
		danieljoos:wincred:v1.1.0:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		diamondburned:adaptive:fa139be203a8:diamondburned_adaptive/vendor/github.com/diamondburned/adaptive \
		diamondburned:arikawa:c07f57455870:diamondburned_arikawa_v3/vendor/github.com/diamondburned/arikawa/v3 \
		diamondburned:chatkit:7d9bb654be2f:diamondburned_chatkit/vendor/github.com/diamondburned/chatkit \
		diamondburned:gotext:4e200827134c:diamondburned_gotext/vendor/github.com/leonelquinteros/gotext \
		diamondburned:gotk4-adwaita:bfe82926e1be:diamondburned_gotk4_adwaita_pkg/vendor/github.com/diamondburned/gotk4-adwaita \
		diamondburned:gotk4:6dd75799f56c:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		diamondburned:gotkit:875fedeceb71:diamondburned_gotkit/vendor/github.com/diamondburned/gotkit \
		diamondburned:ningen:d39554fd5d67:diamondburned_ningen_v3/vendor/github.com/diamondburned/ningen/v3 \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		go4org:unsafe-assume-no-moving-gc:e4bae7ad2296:go4org_go4_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		go4org:go4:f5505b9728dd:go4org_go4/vendor/go4.org \
		godbus:dbus:v5.0.6:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:e7cb96979f69:golang_image/vendor/golang.org/x/image \
		golang:sync:886fb9371eb4:golang_sync/vendor/golang.org/x/sync \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		ianlancetaylor:cgosymbolizer:a1ae3e4bba26:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		twmb:murmur3:v1.1.3:twmb_murmur3/vendor/github.com/twmb/murmur3 \
		yalue:merged_fs:v1.2.3:yalue_merged_fs/vendor/github.com/yalue/merged_fs \
		yuin:goldmark:v1.4.13:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.2.1:zalando_go_keyring/vendor/github.com/zalando/go-keyring
CGO_LDFLAGS+=	-Wl,--as-needed # gtk4 deps
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

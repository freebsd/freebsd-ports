PORTNAME=	dissent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.22
CATEGORIES=	net-im

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK4 Discord client in Go, attempt \#4
WWW=		https://github.com/diamondburned/dissent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		gnome go:1.21,modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40 libadwaita
GH_ACCOUNT=	diamondburned
GH_TUPLE=	KarpelesLab:weak:v0.1.1:karpeleslab_weak/vendor/github.com/KarpelesLab/weak \
		alecthomas:chroma:v0.10.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alessio:shellescape:v1.4.1:alessio_shellescape/vendor/github.com/alessio/shellescape \
		danieljoos:wincred:v1.1.0:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		diamondburned:adaptive:fa139be203a8:diamondburned_adaptive/vendor/github.com/diamondburned/adaptive \
		diamondburned:arikawa:v3.3.5:diamondburned_arikawa_v3/vendor/github.com/diamondburned/arikawa/v3 \
		diamondburned:chatkit:4b8acdf0f84b:diamondburned_chatkit/vendor/github.com/diamondburned/chatkit \
		diamondburned:ctxt:07a499f07b78:diamondburned_ctxt/vendor/libdb.so/ctxt \
		diamondburned:gotk4-adwaita:5f283b5d35bc:diamondburned_gotk4_adwaita_pkg/vendor/github.com/diamondburned/gotk4-adwaita \
		diamondburned:gotk4:v0.2.2:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		diamondburned:gotkit:34324269516c:diamondburned_gotkit/vendor/github.com/diamondburned/gotkit \
		diamondburned:ningen:0d35ff052647:diamondburned_ningen_v3/vendor/github.com/diamondburned/ningen/v3 \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		go4org:go4:f5505b9728dd:go4org_go4/vendor/go4.org \
		go4org:unsafe-assume-no-moving-gc:b99613f794b6:go4org_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		godbus:dbus:v5.0.6:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:crypto:v0.17.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:e7cb96979f69:golang_image/vendor/golang.org/x/image \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		ianlancetaylor:cgosymbolizer:a1ae3e4bba26:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		leonelquinteros:gotext:37f474cfb069:leonelquinteros_gotext/vendor/github.com/leonelquinteros/gotext \
		lmittmann:tint:v1.0.4:lmittmann_tint/vendor/github.com/lmittmann/tint \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		twmb:murmur3:v1.1.3:twmb_murmur3/vendor/github.com/twmb/murmur3 \
		yalue:merged_fs:v1.2.3:yalue_merged_fs/vendor/github.com/yalue/merged_fs \
		yuin:goldmark:v1.5.6:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.2.1:zalando_go_keyring/vendor/github.com/zalando/go-keyring
CGO_LDFLAGS+=	-Wl,--as-needed # gtk4 deps
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/so.libdb.dissent.desktop \
		share/dbus-1/services/so.libdb.dissent.service \
		share/icons/hicolor/scalable/apps/so.libdb.dissent.svg \
		share/metainfo/so.libdb.dissent.metainfo.xml

post-patch:
	@${REINPLACE_CMD} 's,/usr/bin,${PREFIX}/bin,' ${WRKSRC}/nix/*.service

post-install:
# Install extras similar to Nix flake
.for f in nix/*.desktop nix/*.service *.metainfo.xml \
		internal/icons/hicolor/scalable/apps/so.libdb.dissent.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>

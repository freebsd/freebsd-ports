PORTNAME=	dissent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.27
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
		alessio:shellescape:v1.4.2:alessio_shellescape/vendor/github.com/alessio/shellescape \
		danieljoos:wincred:v1.2.1:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		diamondburned:adaptive:fa139be203a8:diamondburned_adaptive/vendor/github.com/diamondburned/adaptive \
		diamondburned:arikawa:v3.3.6:diamondburned_arikawa_v3/vendor/github.com/diamondburned/arikawa/v3 \
		diamondburned:chatkit:5788b19145bc:diamondburned_chatkit/vendor/github.com/diamondburned/chatkit \
		diamondburned:ctxt:2db38a5d3c12:diamondburned_ctxt/vendor/libdb.so/ctxt \
		diamondburned:go-emoji:39776eee41ac:diamondburned_go_emoji/vendor/libdb.so/go-emoji \
		diamondburned:gotk4-adwaita:824c3ce8a5f4:diamondburned_gotk4_adwaita_pkg/vendor/github.com/diamondburned/gotk4-adwaita \
		diamondburned:gotk4:v0.3.1:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		diamondburned:gotkit:b0d58ff2b308:diamondburned_gotkit/vendor/github.com/diamondburned/gotkit \
		diamondburned:ningen:b1a39a908e52:diamondburned_ningen_v3/vendor/github.com/diamondburned/ningen/v3 \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		go4org:go4:214862532bf5:go4org_go4/vendor/go4.org \
		go4org:unsafe-assume-no-moving-gc:b99613f794b6:go4org_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gofrs:flock:v0.12.1:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:crypto:v0.22.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.24.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		gorilla:schema:v1.4.1:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		ianlancetaylor:cgosymbolizer:581a3f7c677f:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		leonelquinteros:gotext:v1.6.0:leonelquinteros_gotext/vendor/github.com/leonelquinteros/gotext \
		lmittmann:tint:v1.0.4:lmittmann_tint/vendor/github.com/lmittmann/tint \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		puzpuzpuz:xsync:v3.1.0:puzpuzpuz_xsync_v3/vendor/github.com/puzpuzpuz/xsync/v3 \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		twmb:murmur3:v1.1.8:twmb_murmur3/vendor/github.com/twmb/murmur3 \
		yalue:merged_fs:v1.3.0:yalue_merged_fs/vendor/github.com/yalue/merged_fs \
		yuin:goldmark:v1.7.1:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.2.4:zalando_go_keyring/vendor/github.com/zalando/go-keyring
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

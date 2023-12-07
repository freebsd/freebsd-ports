PORTNAME=	gtkcord4
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.16-1
PORTREVISION=	1
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
		diamondburned:arikawa:4224b93c4e01:diamondburned_arikawa_v3/vendor/github.com/diamondburned/arikawa/v3 \
		diamondburned:chatkit:f172e4a1e35d:diamondburned_chatkit/vendor/github.com/diamondburned/chatkit \
		diamondburned:gotk4-adwaita:26f1789529b0:diamondburned_gotk4_adwaita_pkg/vendor/github.com/diamondburned/gotk4-adwaita \
		diamondburned:gotk4:eb41da62b149:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		diamondburned:gotkit:ace9cfa5e044:diamondburned_gotkit/vendor/github.com/diamondburned/gotkit \
		diamondburned:ningen:c71ae51f868b:diamondburned_ningen_v3/vendor/github.com/diamondburned/ningen/v3 \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		go4org:go4:f5505b9728dd:go4org_go4/vendor/go4.org \
		go4org:unsafe-assume-no-moving-gc:e7c30c78aeb2:go4org_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		godbus:dbus:v5.0.6:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:e7cb96979f69:golang_image/vendor/golang.org/x/image \
		golang:sync:886fb9371eb4:golang_sync/vendor/golang.org/x/sync \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		ianlancetaylor:cgosymbolizer:a1ae3e4bba26:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		leonelquinteros:gotext:37f474cfb069:leonelquinteros_gotext/vendor/github.com/leonelquinteros/gotext \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		twmb:murmur3:v1.1.3:twmb_murmur3/vendor/github.com/twmb/murmur3 \
		yalue:merged_fs:v1.2.3:yalue_merged_fs/vendor/github.com/yalue/merged_fs \
		yuin:goldmark:v1.5.6:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.2.1:zalando_go_keyring/vendor/github.com/zalando/go-keyring
CGO_LDFLAGS+=	-Wl,--as-needed # gtk4 deps
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/so.libdb.gtkcord4.desktop \
		share/dbus-1/services/so.libdb.gtkcord4.service \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/metainfo/so.libdb.gtkcord4.metainfo.xml

post-extract:
# Prune after https://github.com/diamondburned/gtkcord4/commit/86b3ea579df1
	${RM} ${WRKSRC}/nix/xyz.diamondb.gtkcord4.desktop

post-patch:
	@${REINPLACE_CMD} 's,/usr/bin,${PREFIX}/bin,' ${WRKSRC}/nix/*.service

post-install:
# Install extras similar to Nix flake
.for f in nix/*.desktop nix/*.service *.metainfo.xml \
		internal/icons/hicolor/scalable/apps/logo.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>

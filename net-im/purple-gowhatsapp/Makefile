PORTNAME=	purple-gowhatsapp
DISTVERSIONPREFIX=v
DISTVERSION=	1.26.0
CATEGORIES=	net-im

MAINTAINER=	ports@virtual-estates.net
COMMENT=	WhatsApp plugin for libpurple
WWW=		https://github.com/hoehermann/purple-gowhatsapp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	lang/go* ports can only created shared libraries for ${ONLY_FOR_ARCHS}

LIB_DEPENDS=	libpurple.so:net-im/libpurple	\
		libopusfile.so:audio/opusfile

USES=		go:no_targets cmake dos2unix localbase:ldflags pkgconfig
USES+=		gnome gettext-runtime
USE_GNOME=	gdkpixbuf glib20

OPTIONS_MULTI=			DB-backend
OPTIONS_MULTI_DB-backend=	SQLITE3 PGSQL
OPTIONS_DEFAULT=SQLITE3
.for o in ${OPTIONS_MULTI_DB-backend}
$o_DESC=	Support use of $o for storing account information
.endfor

post-patch-SQLITE3-off:
	${REINPLACE_CMD} -E \
	    -e '/_ "${SQLITE3_GL_TUPLE:C|.*/([^/]+)/([^/]+)$|\1\\\/\2|:C/ +/|/gW}"/d' \
	    ${WRKSRC}/login.go

post-patch-PGSQL-off:
	${REINPLACE_CMD} -E \
	    -e '/_ "${PGSQL_GH_TUPLE:C|.*/([^/]+)/([^/]+)/([^/]+)$|\1\\\/\2\\\/\3|:C/ +/|/gW}"/d' \
	    ${WRKSRC}/login.go

USE_GITHUB=	yep...
USE_GITLAB=	nodefault	# Only fetch/extract GL_TUPLEs
GH_ACCOUNT=	hoehermann
DOS2UNIX_GLOB=	CMake*.txt
EXTRACT_AFTER_ARGS=--exclude vendor
MAKE_ENV+=	${GO_ENV}

GH_TUPLE=	\
		FiloSottile:edwards25519:v1.2.0:FiloSottile_edwards25519/vendor/filippo.io/edwards25519 \
		alfg:mp4:55ea58c08aeb:alfg_mp4/vendor/github.com/alfg/mp4 \
		mdp:qrterminal:v3.2.1:mdp_qrterminal/vendor/github.com/mdp/qrterminal/v3 \
		petermattis:goid:abfca077860b:petermattis_goid/vendor/github.com/petermattis/goid \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		tulir:libsignal-protocol-go:v0.2.2:tulir_libsignal_protocol_go/vendor/go.mau.fi/libsignal \
		mattn:go-colorable:v0.1.15:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.24:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mautrix:go-util:v0.10.1:mautrix_go_util/vendor/go.mau.fi/util \
		tulir:whatsmeow:b3832c2bd1d1:tulir_whatsmeow/vendor/go.mau.fi/whatsmeow \
		golang:crypto:v0.57.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:85c1c2202aba:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.59.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.48.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.46.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.42.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		protocolbuffers:protobuf-go:v1.36.12:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:zerolog:v1.35.1:rs_zerolog/vendor/github.com/rs/zerolog \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		beeper:argo-go:v1.1.2:beeper_argo_go/vendor/github.com/beeper/argo-go \
		elliotchance:orderedmap:v3.1.1:elliotchance_orderedmap/vendor/github.com/elliotchance/orderedmap \
		vektah:gqlparser:v2.5.58:vektah_gqlparser/vendor/github.com/vektah/gqlparser \
		coder:websocket:v1.8.15:coder_websocket/vendor/github.com/coder/websocket \
		golang:sync:v0.23.0:golang_sync/vendor/golang.org/x/sync

SQLITE3_GH_TUPLE=\
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		dustin:go-humanize:v1.1.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		ncruces:go-strftime:v1.0.0:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime
SQLITE3_GL_TUPLE=\
		cznic:sqlite:v1.59.0:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:mathutil:v1.7.1:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:v1.12.1:cznic_memory/vendor/modernc.org/memory \
		cznic:libc:v1.77.1:cznic_libc/vendor/modernc.org/libc
PGSQL_GH_TUPLE=	lib:pq:v1.12.3:lib_pq/vendor/github.com/lib/pq

CMAKE_ARGS=	-DPURPLE_INCLUDE_DIRS=${LOCALBASE}/include/libpurple	\
		-DPURPLE_LIBRARY_DIRS=${LOCALBASE}/lib	\
		-DPURPLE_PLUGIN_DIR=${PREFIX}/lib/purple-2 \
		-DPURPLE_DATA_DIR=${PREFIX}/share

# Upstream also tags "nightly-YYYYMMDD" snapshots -- accept only x.y.z releases
PORTSCOUT=	limit:^\d+\.\d+\.\d+$$

post-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/_go
	${LN} -sf ${WRKSRC}/vendor ${CONFIGURE_WRKSRC}/_go/src

.include <bsd.port.mk>

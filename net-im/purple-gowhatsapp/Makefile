PORTNAME=	purple-gowhatsapp
DISTVERSIONPREFIX=v
DISTVERSION=	1.22.0
PORTREVISION=	1
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
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		mdp:qrterminal:v3.2.1:mdp_qrterminal/vendor/github.com/mdp/qrterminal \
		petermattis:goid:4f67fd55d3b4:petermattis_goid/vendor/github.com/petermattis/goid \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tulir:libsignal-protocol-go:v0.2.2:tulir_libsignal_protocol_go/vendor/go.mau.fi/libsignal \
		mattn:go-colorable:v0.1.15:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.22:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mautrix:go-util:v0.9.10:mautrix_go_util/vendor/go.mau.fi/util \
		ncruces:go-strftime:v1.0.0:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		tulir:whatsmeow:73fe7355f59f:tulir_whatsmeow/vendor/go.mau.fi/whatsmeow \
		golang:crypto:v0.54.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9ea1abe57597:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.57.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.47.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.45.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.40.0:golang_text/vendor/golang.org/x/text \
		golang:xerrors:7835f813f4da:golang_xerrors/vendor/golang.org/x/xerrors \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		rs:zerolog:v1.35.1:rs_zerolog/vendor/github.com/rs/zerolog \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		beeper:argo-go:v1.1.2:beeper_argo_go/vendor/github.com/beeper/argo-go \
		elliotchance:orderedmap:v3.1.1:elliotchance_orderedmap/vendor/github.com/elliotchance/orderedmap \
		vektah:gqlparser:v2.5.36:vektah_gqlparser/vendor/github.com/vektah/gqlparser \
		agnivade:levenshtein:v1.2.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		kr:pretty:3cd153a126da:kr_pretty/vendor/github.com/kr/pretty \
		arbovm:levenshtein:48b4e1c0c4d0:arbovm_levenshtein/vendor/github.com/arbovm/levenshtein \
		dgryski:trifles:5ecb8eeff266:dgryski_trifles/vendor/github.com/dgryski/trifles \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		coder:websocket:v1.8.15:coder_websocket/vendor/github.com/coder/websocket \
		golang:sync:v0.22.0:golang_sync/vendor/golang.org/x/sync

SQLITE3_GH_TUPLE=\
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft
SQLITE3_GL_TUPLE=\
		cznic:sqlite:v1.53.0:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:mathutil:v1.7.1:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:v1.11.0:cznic_memory/vendor/modernc.org/memory \
		cznic:libc:v1.74.1:cznic_libc/vendor/modernc.org/libc
PGSQL_GH_TUPLE=	lib:pq:v1.12.3:lib_pq/vendor/github.com/lib/pq

CMAKE_ARGS=	-DPURPLE_INCLUDE_DIRS=${LOCALBASE}/include/libpurple	\
		-DPURPLE_LIBRARY_DIRS=${LOCALBASE}/lib	\
		-DPURPLE_PLUGIN_DIR=${PREFIX}/lib/purple-2 \
		-DPURPLE_DATA_DIR=${PREFIX}/share

post-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/_go
	${LN} -sf ${WRKSRC}/vendor ${CONFIGURE_WRKSRC}/_go/src

.include <bsd.port.mk>

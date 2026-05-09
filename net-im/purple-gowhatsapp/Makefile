PORTNAME=	purple-gowhatsapp
DISTVERSIONPREFIX=v
DISTVERSION=	1.18.0
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
		FiloSottile:edwards25519:v1.1.0:FiloSottile_edwards25519/vendor/filippo.io/edwards25519 \
		alfg:mp4:55ea58c08aeb:alfg_mp4/vendor/github.com/alfg/mp4 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		mdp:qrterminal:v3.2.1:mdp_qrterminal/vendor/github.com/mdp/qrterminal \
		petermattis:goid:395b08c:petermattis_goid/vendor/github.com/petermattis/goid \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tulir:libsignal-protocol-go:v0.2.0:tulir_libsignal_protocol_go/vendor/go.mau.fi/libsignal \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mautrix:go-util:v0.8.7:mautrix_go_util/vendor/go.mau.fi/util \
		ncruces:go-strftime:v0.1.9:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		tulir:whatsmeow:0da7ff7:tulir_whatsmeow/vendor/go.mau.fi/whatsmeow \
		golang:crypto:v0.38.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:ce4c2cf36ca6:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.40.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.32.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.25.0:golang_text/vendor/golang.org/x/text \
		golang:xerrors:7835f813f4da:golang_xerrors/vendor/golang.org/x/xerrors \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		protocolbuffers:protobuf-go:v1.36.2:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		rs:zerolog:v1.34.0:rs_zerolog/vendor/github.com/rs/zerolog \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr

SQLITE3_GH_TUPLE=\
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft
SQLITE3_GL_TUPLE=\
		cznic:sqlite:v1.37.1:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:mathutil:v1.7.1:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:v1.10.0:cznic_memory/vendor/modernc.org/memory \
		cznic:libc:v1.65.8:cznic_libc/vendor/modernc.org/libc
PGSQL_GH_TUPLE=	lib:pq:v1.10.9:lib_pq/vendor/github.com/lib/pq

CMAKE_ARGS=	-DPURPLE_INCLUDE_DIRS=${LOCALBASE}/include/libpurple	\
		-DPURPLE_LIBRARY_DIRS=${LOCALBASE}/lib	\
		-DPURPLE_PLUGIN_DIR=${PREFIX}/lib/purple-2 \
		-DPURPLE_DATA_DIR=${PREFIX}/share

post-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/_go
	${LN} -sf ${WRKSRC}/vendor ${CONFIGURE_WRKSRC}/_go/src

.include <bsd.port.mk>

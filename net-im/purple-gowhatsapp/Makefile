PORTNAME=	purple-gowhatsapp
DISTVERSIONPREFIX=v
DISTVERSION=	1.13.0
PORTREVISION=	5
CATEGORIES=	net-im

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	WhatsApp plugin for libpurple
WWW=		https://github.com/hoehermann/purple-gowhatsapp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpurple.so:net-im/libpurple	\
		libopusfile.so:audio/opusfile

USES=		go:no_targets cmake dos2unix localbase:ldflags pkgconfig

OPTIONS_MULTI=			DB-backend
OPTIONS_MULTI_DB-backend=	SQLITE3 PGSQL MYSQL
OPTIONS_DEFAULT=SQLITE3
.for o in ${OPTIONS_MULTI_DB-backend}
$o_DESC=	Support use of $o for storing account information
post-patch-$o-off:
	${REINPLACE_CMD} '/${$o_GH_TUPLE:C/^([^:]+):([^:]+):.*/\1\\\/\2/}"/d' \
	    ${WRKSRC}/src/go/login.go
.endfor

USE_GITHUB=	yep...
GH_ACCOUNT=	hoehermann
DOS2UNIX_GLOB=	CMake*.txt
EXTRACT_AFTER_ARGS=--exclude vendor
MAKE_ENV+=	${GO_ENV}

GH_TUPLE=	\
		FiloSottile:edwards25519:v1.0.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		alfg:mp4:55ea58c08aeb:alfg_mp4/vendor/github.com/alfg/mp4 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		mdp:qrterminal:v3.2.0:mdp_qrterminal/vendor/github.com/mdp/qrterminal \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify \
		tulir:libsignal-protocol-go:v0.1.0:tulir_libsignal_protocol_go/vendor/go.mau.fi/libsignal \
		mautrix:go-util:v0.3.0:mautrix_go_util/vendor/go.mau.fi/util \
		tulir:whatsmeow:66c756f1ba45:tulir_whatsmeow/vendor/go.mau.fi/whatsmeow \
		golang:crypto:v0.18.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.20.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.16.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.16.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		protocolbuffers:protobuf-go:v1.32.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr

SQLITE3_GH_TUPLE=\
		mattn:go-sqlite3:v1.14.19:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3
PGSQL_GH_TUPLE=	lib:pq:v1.10.9:lib_pq/vendor/github.com/lib/pq
MYSQL_GH_TUPLE=	go-sql-driver:mysql:v1.7.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql

CMAKE_ARGS=	-DPURPLE_INCLUDE_DIRS=${LOCALBASE}/include/libpurple	\
		-DPURPLE_LIBRARY_DIRS=${LOCALBASE}/lib	\
		-DPURPLE_PLUGIN_DIR=${PREFIX}/lib/purple-2 \
		-DPURPLE_DATA_DIR=${PREFIX}/share

post-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/src/go/go
	${LN} -sf ${WRKSRC}/vendor ${CONFIGURE_WRKSRC}/src/go/go/src

.include <bsd.port.mk>

PORTNAME=	miniflux
DISTVERSION=	2.0.50
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Self-hosted software to read RSS/Atom/JSON feeds
WWW=		https://miniflux.app/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules,1.21

USE_GITHUB=	yes
GH_PROJECT=	v2
GH_TUPLE=	\
		PuerkitoBio:goquery:v1.8.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		abadojack:whatlanggo:v1.0.1:abadojack_whatlanggo/vendor/github.com/abadojack/whatlanggo \
		andybalholm:cascadia:v1.3.2:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v3.7.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		fxamacker:cbor:v2.5.0:fxamacker_cbor_v2/vendor/github.com/fxamacker/cbor/v2 \
		go-jose:go-jose:v3.0.0:go_jose_go_jose_v3/vendor/github.com/go-jose/go-jose/v3 \
		go-webauthn:webauthn:v0.8.6:go_webauthn_webauthn/vendor/github.com/go-webauthn/webauthn \
		go-webauthn:x:v0.1.4:go_webauthn_x/vendor/github.com/go-webauthn/x \
		golang-jwt:jwt:v5.0.0:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:appengine:v1.6.8:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.15.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.18.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.14.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.14.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.14.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		google:go-tpm:v0.9.0:google_go_tpm/vendor/github.com/google/go-tpm \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		lib:pq:v1.10.9:lib_pq/vendor/github.com/lib/pq \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mvdan:xurls:v2.5.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		prometheus:client_golang:v1.17.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:9a2bf3000d16:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.11.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		tdewolff:minify:v2.20.6:tdewolff_minify_v2/vendor/github.com/tdewolff/minify/v2 \
		tdewolff:parse:v2.7.4:tdewolff_parse_v2/vendor/github.com/tdewolff/parse/v2 \
		x448:float16:v0.8.4:x448_float16/vendor/github.com/x448/float16 \
		yuin:goldmark:v1.6.0:yuin_goldmark/vendor/github.com/yuin/goldmark

USE_RC_SUBR=	miniflux

GO_PKGNAME=	miniflux.app
GO_TARGET=	:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X miniflux.app/version.Version=${DISTVERSION} \
		-X miniflux.app/version.BuildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ')"

USERS=		miniflux
GROUPS=		miniflux

OPTIONS_DEFINE=		PGSQL_SERVER
PGSQL_SERVER_DESC=	Install the PostgreSQL Server Component
PGSQL_SERVER_USES=	pgsql
PGSQL_SERVER_VARS=	WANT_PGSQL+="server contrib"

post-install:
	${INSTALL_MAN} ${WRKSRC}/miniflux.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_DATA} ${FILESDIR}/miniflux.env.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

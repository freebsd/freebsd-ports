PORTNAME=	miniflux
DISTVERSION=	2.0.34
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Self-hosted software to read RSS/Atom/JSON feeds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules

USE_GITHUB=	yes
GH_PROJECT=	v2
GH_TUPLE=	PuerkitoBio:goquery:v1.8.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.3.1:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-telegram-bot-api:telegram-bot-api:v4.6.4:go_telegram_bot_api_telegram_bot_api/vendor/github.com/go-telegram-bot-api/telegram-bot-api \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:gddo:721e228c7686:golang_gddo/vendor/github.com/golang/gddo \
		golang:net:12bc252f5db8:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:0f9fa26af87c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		lib:pq:v1.10.4:lib_pq/vendor/github.com/lib/pq \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-server-timing:feb680ab92c2:mitchellh_go_server_timing/vendor/github.com/mitchellh/go-server-timing \
		mvdan:xurls:v2.3.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0-rc.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rylans:getlang:4c3188ff8a2d:rylans_getlang/vendor/github.com/rylans/getlang \
		square:go-jose:v2.5.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tdewolff:minify:v2.9.22:tdewolff_minify_v2/vendor/github.com/tdewolff/minify/v2 \
		tdewolff:parse:v2.5.21:tdewolff_parse_v2/vendor/github.com/tdewolff/parse/v2 \
		technoweenie:multipartstreamer:v1.0.1:technoweenie_multipartstreamer/vendor/github.com/technoweenie/multipartstreamer

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

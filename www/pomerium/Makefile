PORTNAME=	pomerium
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Identity-aware access proxy
WWW=		https://pomerium.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
GO_TARGET=	./cmd/${PORTNAME}:${PREFIX}/libexec/${PORTNAME} ./cmd/${PORTNAME}-cli:${PREFIX}/bin/${PORTNAME}-cli

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/version

GO_BUILDFLAGS=	-ldflags "${STRIP} -w \
		-X github.com/pomerium/pomerium/version.Version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X github.com/pomerium/pomerium/version.ProjectName=${PORTNAME} \
		-X github.com/pomerium/pomerium/version.ProjectURL=${GO_PKGNAME}"
CGO_ENABLED=	0

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes

GH_TUPLE=	\
		OneOfOne:xxhash:v1.2.7:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		armon:go-metrics:v0.3.0:armon_go_metrics/vendor/github.com/armon/go-metrics \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		caddyserver:certmagic:v0.10.12:caddyserver_certmagic/vendor/github.com/caddyserver/certmagic \
		cenkalti:backoff:v4.0.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.2.0:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.1.0:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.4:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-acme:lego:v3.7.0:go_acme_lego_v3/vendor/github.com/go-acme/lego/v3 \
		go-ini:ini:v1.51.1:go_ini_ini/vendor/gopkg.in/ini.v1 \
		redis:go-redis:v7.2.0:go_redis_redis_v7/vendor/github.com/go-redis/redis/v7 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:06a226fb4e37:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.4.3:golang_mock/vendor/github.com/golang/mock \
		golang:net:7e3656a0809f:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:1957bb5e6d1f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1ee6d9798940:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-jsonnet:v0.15.0:google_go_jsonnet/vendor/github.com/google/go-jsonnet \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.23.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.28.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:memberlist:v0.2.2:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		klauspost:cpuid:v1.2.3:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		onsi:gocleanup:c1a5478700b5:onsi_gocleanup/vendor/github.com/onsi/gocleanup \
		open-policy-agent:opa:v0.19.2:open_policy_agent_opa/vendor/github.com/open-policy-agent/opa \
		pelletier:go-toml:v1.6.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pomerium:autocache:8c1cd659f055:pomerium_autocache/vendor/github.com/pomerium/autocache \
		pomerium:csrf:f3318380bad3:pomerium_csrf/vendor/github.com/pomerium/csrf \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.22.0:protobuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rakyll:statik:v0.1.7:rakyll_statik/vendor/github.com/rakyll/statik \
		rcrowley:go-metrics:cac0b30c2563:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rs:zerolog:v1.18.0:rs_zerolog/vendor/github.com/rs/zerolog \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber:jaeger-client-go:v2.20.1:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		yashtewari:glob-intersection:5c77d914dd0b:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection

POMERIUMPIDDIR=		/var/run/${PORTNAME}/
POMERIUM_USER?=		www

SUB_LIST+=	POMERIUM_USER=${POMERIUM_USER} \
		POMERIUMPIDDIR=${POMERIUMPIDDIR}
PLIST_SUB+=	${SUB_LIST}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${POMERIUMPIDDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/configuration/examples/config/config.example.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yaml.sample

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	pomerium
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	www

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Identity-aware access proxy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_TARGET=	./cmd/${PORTNAME}:${PREFIX}/libexec/${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/version

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/pomerium/pomerium/version.Version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X github.com/pomerium/pomerium/version.ProjectName=${PORTNAME} \
		-X github.com/pomerium/pomerium/version.ProjectURL=${GO_PKGNAME}"
CGO_ENABLED=	0

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_TUPLE=	\
		armon:go-metrics:v0.3.0:armon_go_metrics/vendor/github.com/armon/go-metrics \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.2.0:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.1.0:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		cespare:xxhash:v2.1.1:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		etcd-io:bbolt:v1.3.3:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.1:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-redis:redis:v6.15.6:go_redis_redis/vendor/github.com/go-redis/redis \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:530e935923ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:6afb5195e5aa:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:34d275377bf9:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:83cc0476cb11:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.14.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.49.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		grpc:grpc-go:v1.25.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:memberlist:v0.1.5:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.6.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pomerium:autocache:dc85d6127c4e:pomerium_autocache/vendor/github.com/pomerium/autocache \
		pomerium:csrf:f3318380bad3:pomerium_csrf/vendor/github.com/pomerium/csrf \
		pomerium:go-oidc:v2.0.0:pomerium_go_oidc/vendor/github.com/pomerium/go-oidc \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.2.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rakyll:statik:v0.1.6:rakyll_statik/vendor/github.com/rakyll/statik \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rs:zerolog:v1.17.2:rs_zerolog/vendor/github.com/rs/zerolog \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.2:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.4.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber:jaeger-client-go:v2.20.1:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go

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

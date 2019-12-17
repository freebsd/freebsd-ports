# $FreeBSD$

PORTNAME=	pomerium
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	1
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
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.1.0:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.1.0:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.3:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:ed6320f186d4:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:fe3aa8a45271:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f43be2a4598c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:919d9bdd9fe6:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.13.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.47.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pomerium:csrf:f3318380bad3:pomerium_csrf/vendor/github.com/pomerium/csrf \
		pomerium:go-oidc:v2.0.0:pomerium_go_oidc/vendor/github.com/pomerium/go-oidc \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v0.9.3:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:5867b95ac084:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rs:zerolog:v1.16.0:rs_zerolog/vendor/github.com/rs/zerolog \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.4.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2

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

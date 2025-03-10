PORTNAME=	oauth2-proxy
PORTVERSION=	7.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	OAuth 2.0 proxy server
WWW=		https://github.com/oauth2-proxy/oauth2-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.22

USE_GITHUB=	yes
GH_TUPLE=	\
		Bose:minisentinel:917c5a9223bb:bose_minisentinel/vendor/github.com/Bose/minisentinel \
		a8m:envsubst:v1.4.2:a8m_envsubst/vendor/github.com/a8m/envsubst \
		alicebob:gopher-json:906a9b012302:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.33.0:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		benbjohnson:clock:v1.3.5:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-simplejson:v0.5.1:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		bsm:redislock:v0.9.4:bsm_redislock/vendor/github.com/bsm/redislock \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v3.11.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:d8423dcdf344:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-jose:go-jose:v3.0.3:go_jose_go_jose_v3/vendor/github.com/go-jose/go-jose/v3 \
		go-jose:go-jose:v4.0.4:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v5.2.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.31.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:2d47ceb2692f:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.33.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.24.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.10.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.28.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.21.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.27.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:324edc3d5d38:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:d1b30febd7db:google_pprof/vendor/github.com/google/pprof \
		google:s2a-go:v0.1.8:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.4:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.13.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.205.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:auth/v0.10.1:googleapis_google_cloud_go_auth/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.5:googleapis_google_cloud_go/vendor/cloud.google.com/go/auth/oauth2adapt \
		googleapis:google-cloud-go:compute/metadata/v0.5.2:googleapis_google_cloud_go_1/vendor/cloud.google.com/go/compute/metadata \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:v1.67.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		justinas:alice:v1.2.0:justinas_alice/vendor/github.com/justinas/alice \
		klauspost:compress:v1.17.10:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes:apimachinery:v0.31.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:gengo:a0386bf69313:kubernetes_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v2.130.1:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mbland:hmacauth:44256dfd4bfa:mbland_hmacauth/vendor/github.com/mbland/hmacauth \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		natefinch:lumberjack:v2.2.1:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nxadm:tail:v1.4.11:nxadm_tail/vendor/github.com/nxadm/tail \
		oauth2-proxy:mockoidc:caebfff84d25:oauth2_proxy_mockoidc/vendor/github.com/oauth2-proxy/mockoidc \
		oauth2-proxy:tools:d3b50d1a591a:oauth2_proxy_tools_reference_gen/vendor/github.com/oauth2-proxy/tools \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:ginkgo:v2.21.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.35.1:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go-contrib:v1.30.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go:v1.30.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		pelletier:go-toml:v2.2.3:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pierrec:lz4:v4.1.21:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.20.5:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.59.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.35.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		redis:go-redis:v9.7.0:redis_go_redis_v9/vendor/github.com/redis/go-redis/v9 \
		sagikazarmark:locafero:v0.6.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.7.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.19.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		vmihailenco:msgpack:v5.4.1:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		yuin:gopher-lua:v1.1.1:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

USE_RC_SUBR=	oauth2_proxy

GO_BUILDFLAGS=	-v -ldflags="-s -X github.com/${PORTNAME}/${PORTNAME}/v7/pkg/version.VERSION=${PORTVERSION}"

USER=		www
GROUP=		www

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
RUN_DIR?=	${VAR_DIR}/run/${PORTNAME}

SUB_LIST+=	GROUP=${GROUP} \
		LOG_DIR=${LOG_DIR} \
		PORTNAME=${PORTNAME} \
		PREFIX=${PREFIX} \
		RUN_DIR=${RUN_DIR} \
		USER=${USER}

post-install:
	${MKDIR} ${STAGEDIR}${LOG_DIR}
	${MKDIR} ${STAGEDIR}${RUN_DIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/${PORTNAME}.cfg.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

.include <bsd.port.mk>

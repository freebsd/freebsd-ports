PORTNAME=	oauth2-proxy
PORTVERSION=	7.5.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	OAuth 2.0 proxy server
WWW=		https://github.com/oauth2-proxy/oauth2-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	oauth2-proxy

USE_GITHUB=	yes
GH_TUPLE=	\
		Bose:minisentinel:917c5a9223bb:bose_minisentinel/vendor/github.com/Bose/minisentinel \
		alicebob:gopher-json:a9ecdc9d1d3a:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.23.0:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		benbjohnson:clock:v1.3.0:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-simplejson:v0.5.0:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		bsm:redislock:v0.9.1:bsm_redislock/vendor/github.com/bsm/redislock \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v3.5.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-jose:go-jose:v3.0.0:go_jose_go_jose_v3/vendor/github.com/go-jose/go-jose/v3 \
		go-logr:logr:v1.2.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.7.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:47ecfdc1ba53:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.6.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.8.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:7f2fa6fef1f4:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.2.3:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.7.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.111.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:compute/v1.18.0:googleapis_google_cloud_go_compute/vendor/cloud.google.com/go \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:v1.53.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		justinas:alice:v1.2.0:justinas_alice/vendor/github.com/justinas/alice \
		kubernetes:apimachinery:v0.26.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:gengo:83324d819ded:kubernetes_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v2.80.1:kubernetes_klog/vendor/k8s.io/klog/v2 \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mbland:hmacauth:44256dfd4bfa:mbland_hmacauth/vendor/github.com/mbland/hmacauth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		natefinch:lumberjack:v2.2.1:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		oauth2-proxy:mockoidc:e3afe97dec43:oauth2_proxy_mockoidc/vendor/github.com/oauth2-proxy/mockoidc \
		oauth2-proxy:tools:56ffd7384404:oauth2_proxy_tools_reference_gen/vendor/github.com/oauth2-proxy/tools \
		ohler55:ojg:v1.14.5:ohler55_ojg/vendor/github.com/ohler55/ojg \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.27.6:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pelletier:go-toml:v2.0.7:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pierrec:lz4:v4.1.17:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.14.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.42.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.9.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		redis:go-redis:v9.0.2:redis_go_redis_v9/vendor/github.com/redis/go-redis/v9 \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.3:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.6.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.4.2:subosito_gotenv/vendor/github.com/subosito/gotenv \
		vmihailenco:msgpack:v5.3.5:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		yuin:gopher-lua:f4c35e4016d9:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

GO_BUILDFLAGS=	-ldflags="-s -X main.VERSION=${PORTVERSION}"

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

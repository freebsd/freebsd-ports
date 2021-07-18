PORTNAME=	oauth2-proxy
PORTVERSION=	7.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	OAuth 2.0 proxy server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	oauth2-proxy

USE_GITHUB=	yes
GH_TUPLE=	\
		Bose:minisentinel:917c5a9223bb:bose_minisentinel/vendor/github.com/Bose/minisentinel \
		alicebob:gopher-json:a9ecdc9d1d3a:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.13.0:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-simplejson:v0.5.0:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		frankban:quicktest:v1.10.0:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v0.2.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-redis:redis:v8.2.3:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f9fddec55a1e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.20.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.38.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.27.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		justinas:alice:v1.2.0:justinas_alice/vendor/github.com/justinas/alice \
		kubernetes:apimachinery:v0.19.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:gengo:83324d819ded:kubernetes_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v2.4.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mbland:hmacauth:44256dfd4bfa:mbland_hmacauth/vendor/github.com/mbland/hmacauth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nxadm:tail:v1.4.4:nxadm_tail/vendor/github.com/nxadm/tail \
		oauth2-proxy:tools:56ffd7384404:oauth2_proxy_tools_reference_gen/vendor/github.com/oauth2-proxy/tools \
		onsi:ginkgo:v1.14.1:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.10.2:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go:v0.11.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.3:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.4.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		vmihailenco:msgpack:v4.3.11:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		yhat:wsutil:1d66fa95c997:yhat_wsutil/vendor/github.com/yhat/wsutil \
		yuin:gopher-lua:ab39c6098bdb:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

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

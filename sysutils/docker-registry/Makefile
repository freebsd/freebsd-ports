# $FreeBSD$

PORTNAME=	docker-registry
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	freebsd@yapsoft.it
COMMENT=	Docker implementation of the OCI Distribution Specification

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_RC_SUBR=	docker_registry
USE_GITHUB=	yes

GH_ACCOUNT=	docker
GH_PROJECT=	distribution

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/registry
GO_BUILDFLAGS=	-ldflags "-s -w -X github.com/docker/distribution/version.Version=${PORTVERSION}"

PLIST_FILES=	bin/registry \
		"@sample ${ETCDIR}/config.yml.sample"

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v16.2.1:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:v10.8.1:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Shopify:logrus-bugsnag:577dee27f20d:shopify_logrus_bugsnag/vendor/github.com/Shopify/logrus-bugsnag \
		aws:aws-sdk-go:v1.15.11:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bshuster-repo:logrus-logstash-hook:v0.4.1:bshuster_repo_logrus_logstash_hook/vendor/github.com/bshuster-repo/logrus-logstash-hook \
		bugsnag:bugsnag-go:b1d153021fcd:bugsnag_bugsnag_go/vendor/github.com/bugsnag/bugsnag-go \
		bugsnag:osext:0dd3f918b21b:bugsnag_osext/vendor/github.com/bugsnag/osext \
		bugsnag:panicwrap:e2c28503fcd0:bugsnag_panicwrap/vendor/github.com/bugsnag/panicwrap \
		denverdino:aliyungo:a747050bb1ba:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		dgrijalva:jwt-go:a601269ab70c:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:go-events:e31b211e4f1c:docker_go_events/vendor/github.com/docker/go-events \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:libtrust:fa567046d9b1:docker_libtrust/vendor/github.com/docker/libtrust \
		garyburd:redigo:535138d7bcd7:garyburd_redigo/vendor/github.com/garyburd/redigo \
		go-check:check:64131543e789:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.25.4:go_ini_ini/vendor/github.com/go-ini/ini \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:69ecbb4d6d5d:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:b5b0513f8c1b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:cbf593c0f2f3:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		googleapis:google-api-go-client:9bf6e6e569ff:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.34.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:handlers:60c7bfde3e33:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.7.2:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:d3ddb4469d5a:grpc_grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jmespath:go-jmespath:bd40a432e4c7:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		marstr:guid:v1.1.0:marstr_guid/vendor/github.com/marstr/guid \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		ncw:swift:v1.0.47:ncw_swift/vendor/github.com/ncw/swift \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		yvasiyarov:go-metrics:57bccd1ccd43:yvasiyarov_go_metrics/vendor/github.com/yvasiyarov/go-metrics \
		yvasiyarov:gorelic:a9bba5b9ab50:yvasiyarov_gorelic/vendor/github.com/yvasiyarov/gorelic \
		yvasiyarov:newrelic_platform_go:b21fdbd4370f:yvasiyarov_newrelic_platform_go/vendor/github.com/yvasiyarov/newrelic_platform_go

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/cmd/registry/config-example.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.sample

.include <bsd.port.mk>

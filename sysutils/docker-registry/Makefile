PORTNAME=	docker-registry
PORTVERSION=	2.8.3
DISTVERSIONPREFIX=v
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	freebsd@yapsoft.it
COMMENT=	Docker implementation of the OCI Distribution Specification
WWW=		https://github.com/docker/distribution/

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
EXTRACT_AFTER_ARGS=--exclude vendor.conf --exclude vendor

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v68.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Shopify:logrus-bugsnag:004243a:shopify_logrus_bugsnag/vendor/github.com/Shopify/logrus-bugsnag \
		aws:aws-sdk-go:v1.55.6:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bshuster-repo:logrus-logstash-hook:v0.4.1:bshuster_repo_logrus_logstash_hook/vendor/github.com/bshuster-repo/logrus-logstash-hook \
		bugsnag:bugsnag-go:v2.5.1:bugsnag_bugsnag_go/vendor/github.com/bugsnag/bugsnag-go \
		bugsnag:panicwrap:v1.3.4:bugsnag_panicwrap/vendor/github.com/bugsnag/panicwrap \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		distribution:reference:v0.6.0:distribution_reference/vendor/github.com/distribution/reference \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:libtrust:aabc10e:docker_libtrust/vendor/github.com/docker/libtrust \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		garyburd:redigo:v1.6.4:garyburd_redigo/vendor/github.com/garyburd/redigo \
		golang:crypto:v0.32.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.34.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.30.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.22.0:golang_text/vendor/golang.org/x/text \
		gofrs:uuid:v5.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:handlers:v1.5.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		klauspost:compress:v1.17.11:klauspost_compress/vendor/github.com/klauspost/compress \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		ncw:swift:v1.0.53:ncw_swift/vendor/github.com/ncw/swift \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.0:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.20.5:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.62.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.4:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.8.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/github.com/spf13/pflag \
		yvasiyarov:gorelic:a9bba5b9ab50:yvasiyarov_gorelic/vendor/github.com/yvasiyarov/gorelic \
		yvasiyarov:newrelic_platform_go:9c099fb:yvasiyarov_newrelic_platform_go/vendor/github.com/yvasiyarov/newrelic_platform_go \
		yvasiyarov:go-metrics:57bccd1ccd43:yvasiyarov_go_metrics/vendor/github.com/yvasiyarov/go-metrics \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/cmd/registry/config-example.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.sample

.include <bsd.port.mk>

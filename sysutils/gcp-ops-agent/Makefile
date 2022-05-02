PORTNAME=	ops-agent
DISTVERSION=	2.18.1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	gcp-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Gather logs and metrics from Google Compute Engine instances

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_TUPLE=	StackExchange:wmi:v1.2.1:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		cenkalti:backoff:v4.1.2:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-ole:go-ole:v1.2.5:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-playground:locales:v0.14.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.9.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v2.2.3:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-yaml:v1.9.4:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:a769d52b0f97:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:7fd8e65b6420:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d3ed0bb246c8:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:1d35b9e2eb4e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:00ab72f36ad5:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.65.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:logging/v1.4.2:googleapis_google_cloud_go_logging \
		googleapis:google-cloud-go:monitoring/v1.2.0:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:storage/v1.18.2:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.1.0:googleapis_google_cloud_go_compute/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:v0.100.2:googleapis_google_cloud_go \
		grpc:grpc-go:v1.40.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.4.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		shirou:gopsutil:v3.21.8:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		tklauser:go-sysconf:v0.3.6:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr
GO_TARGET=	./cmd/google_cloud_ops_agent_engine

PLIST_FILES=	bin/google_cloud_ops_agent_engine

post-extract:
	@${RLN} ${WRKSRC_googleapis_google_cloud_go} ${WRKSRC}/vendor/cloud.google.com/go
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_logging}/logging ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage

.include <bsd.port.mk>

PORTNAME=	google-guest-agent
DISTVERSION=	20260724.00
CATEGORIES=	sysutils

MAINTAINER=	spadhi@google.com
COMMENT=	Google Compute Engine Guest Agent
WWW=		https://github.com/GoogleCloudPlatform/guest-agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	guest-agent

GO_TARGET=	./google_guest_agent:${PREFIX}/sbin/google_guest_agent \
		./google_metadata_script_runner:${PREFIX}/sbin/google_metadata_script_runner

GH_TUPLE=	GoogleCloudPlatform:confidential-space:d522e41e9e74:googlecloudplatform_confidential_space_server/vendor/github.com/GoogleCloudPlatform/confidential-space \
		GoogleCloudPlatform:guest-logging-go:02d6ddff2dfb:googlecloudplatform_guest_logging_go/vendor/github.com/GoogleCloudPlatform/guest-logging-go \
		GoogleCloudPlatform:opentelemetry-operations-go:detectors/gcp/v1.33.0:googlecloudplatform_opentelemetry_operations_go_gcp/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go \
		GoogleCloudPlatform:opentelemetry-operations-go:exporter/metric/v0.57.0:googlecloudplatform_opentelemetry_operations_go_metric \
		GoogleCloudPlatform:opentelemetry-operations-go:internal/resourcemapping/v0.57.0:googlecloudplatform_opentelemetry_operations_go_resourcemapping \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		bugst:go-serial:v1.8.0:bugst_go_serial/vendor/go.bug.st/serial \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cncf:xds:dba9d589def2:cncf_xds_go/vendor/github.com/cncf/xds \
		envoyproxy:go-control-plane:envoy/v1.37.0:envoyproxy_go_control_plane_envoy/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v1.3.3:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		felixge:httpsnoop:v1.1.0:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-ini:ini:v1.67.3:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-jose:go-jose:v4.1.4:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.53.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.56.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.36.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.21.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.46.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.38.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		google:cel-spec:v0.25.2:google_cel_spec/vendor/cel.dev/expr \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-configfs-tsm:v0.3.3:google_go_configfs_tsm/vendor/github.com/google/go-configfs-tsm \
		google:go-eventlog:883cc5652c69:google_go_eventlog/vendor/github.com/google/go-eventlog \
		google:go-genproto:925bb5da69e7:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-sev-guest:c930ed67bebf:google_go_sev_guest/vendor/github.com/google/go-sev-guest \
		google:go-tdx-guest:fff6cc779034:google_go_tdx_guest/vendor/github.com/google/go-tdx-guest \
		google:go-tpm-tools:v0.4.9:google_go_tpm_tools/vendor/github.com/google/go-tpm-tools \
		google:go-tpm:v0.9.8:google_go_tpm/vendor/github.com/google/go-tpm \
		google:logger:v1.1.2:google_logger/vendor/github.com/google/logger \
		google:s2a-go:v0.1.9:google_s2a_go/vendor/github.com/google/s2a-go \
		google:tink:go/v1.7.0:google_tink_go/vendor/github.com/google/tink \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.17:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.22.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.286.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.8:googleapis_google_cloud_go_oauth2adapt \
		googleapis:google-cloud-go:auth/v0.20.0:googleapis_google_cloud_go_auth \
		googleapis:google-cloud-go:compute/metadata/v0.9.0:googleapis_google_cloud_go_metadata \
		googleapis:google-cloud-go:iam/v1.11.0:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:logging/v1.18.0:googleapis_google_cloud_go_logging \
		googleapis:google-cloud-go:longrunning/v1.1.0:googleapis_google_cloud_go_longrunning \
		googleapis:google-cloud-go:monitoring/v1.29.0:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:storage/v1.63.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.123.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.82.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		kardianos:service:v1.2.4:kardianos_service/vendor/github.com/kardianos/service \
		open-telemetry:opentelemetry-go-contrib:detectors/gcp/v1.44.0:open_telemetry_opentelemetry_go_contrib_gcp/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go-contrib:instrumentation/google.golang.org/grpc/otelgrpc/v0.69.0:open_telemetry_opentelemetry_go_contrib_otelgrpc \
		open-telemetry:opentelemetry-go-contrib:instrumentation/net/http/otelhttp/v0.69.0:open_telemetry_opentelemetry_go_contrib_otelhttp \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:open_telemetry_opentelemetry_go_instrumentation_sdk/vendor/go.opentelemetry.io/auto \
		open-telemetry:opentelemetry-go:metric/v1.44.0:open_telemetry_opentelemetry_go_metric \
		open-telemetry:opentelemetry-go:sdk/metric/v1.44.0:open_telemetry_opentelemetry_go_metric_1 \
		open-telemetry:opentelemetry-go:sdk/v1.44.0:open_telemetry_opentelemetry_go_sdk \
		open-telemetry:opentelemetry-go:v1.44.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		planetscale:vtprotobuf:0393e58bdf10:planetscale_vtprotobuf/vendor/github.com/planetscale/vtprotobuf \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		spiffe:go-spiffe:v2.8.1:spiffe_go_spiffe_v2/vendor/github.com/spiffe/go-spiffe/v2 \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		SSLMate:go-pkcs12:v0.7.3:group_name/vendor/software.sslmate.com/src/go-pkcs12

USE_RC_SUBR=	google_guest_agent

PLIST_FILES=	sbin/google_guest_agent \
		sbin/google_metadata_script_runner

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/auth
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_auth}/auth ${WRKSRC}/vendor/cloud.google.com/go/auth
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/auth/oauth2adapt
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_oauth2adapt}/auth/oauth2adapt ${WRKSRC}/vendor/cloud.google.com/go/auth/oauth2adapt
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_metadata}/compute/metadata ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_logging}/logging ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_longrunning}/longrunning ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/exporter/metric
	@${RLN} ${WRKSRC_googlecloudplatform_opentelemetry_operations_go_metric}/exporter/metric ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/exporter/metric
	@${RM} -r ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/internal/resourcemapping
	@${RLN} ${WRKSRC_googlecloudplatform_opentelemetry_operations_go_resourcemapping}/internal/resourcemapping ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/internal/resourcemapping
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_contrib_otelgrpc}/instrumentation/google.golang.org/grpc/otelgrpc ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_contrib_otelhttp}/instrumentation/net/http/otelhttp ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_metric}/metric ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_sdk}/sdk ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk/metric
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_metric_1}/sdk/metric ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk/metric

post-patch:
	${MV} ${WRKSRC}/modules.txt ${WRKSRC}/vendor/modules.txt

.include <bsd.port.mk>

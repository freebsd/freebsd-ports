PORTNAME=	loki
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.2
PORTREVISION=	15
CATEGORIES=	sysutils
PKGNAMEPREFIX=	grafana-

MAINTAINER=	freebsd@funzi.org
COMMENT=	Scalable, highly-available, multi-tenant log aggregation system
WWW=		https://github.com/grafana/loki

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules cpe
CPE_VENDOR=	grafana
USE_GITHUB=	yes

GH_ACCOUNT=	grafana
GH_PROJECT=	loki
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:2f352faf4f49:azure_azure_sdk_for_go_azblob \
		Azure:azure-sdk-for-go:76834b7386c1:azure_azure_sdk_for_go_azidentity \
		Azure:azure-sdk-for-go:96096feee7ba:azure_azure_sdk_for_go_azcore \
		Azure:azure-sdk-for-go:e3202264a0d4:azure_azure_sdk_for_go_internal \
		Azure:azure-sdk-for-go:v36.2.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:553a90ae65a6:azure_go_autorest_adal \
		Azure:go-autorest:70a178d6ca59:azure_go_autorest_cli \
		Azure:go-autorest:9038e4a609b1:azure_go_autorest_auth \
		Azure:go-autorest:autorest/v0.11.29:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		AzureAD:microsoft-authentication-library-for-go:v0.7.0:azuread_microsoft_authentication_library_for_go/vendor/github.com/AzureAD/microsoft-authentication-library-for-go \
		DmitriyVTitov:size:v1.5.0:dmitriyvtitov_size/vendor/github.com/DmitriyVTitov/size \
		IBM:go-sdk-core:v5.13.1:ibm_go_sdk_core_v5/vendor/github.com/IBM/go-sdk-core/v5 \
		IBM:ibm-cos-sdk-go:v1.10.0:ibm_ibm_cos_sdk_go/vendor/github.com/IBM/ibm-cos-sdk-go \
		MasslessParticle:azure-storage-blob-go:b5e698eff68e:masslessparticle_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.2.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.3:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Microsoft:go-winio:v0.6.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		Shopify:sarama:v1.38.1:shopify_sarama/vendor/github.com/Shopify/sarama \
		Workiva:go-datastructures:v1.1.0:workiva_go_datastructures/vendor/github.com/Workiva/go-datastructures \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		alicebob:gopher-json:a9ecdc9d1d3a:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.30.4:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		aliyun:aliyun-oss-go-sdk:v2.2.7:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		armon:go-metrics:v0.4.1:armon_go_metrics/vendor/github.com/armon/go-metrics \
		asaskevich:govalidator:a9d515a09cc2:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		aws:aws-sdk-go-v2:5399c50f8a2f:aws_aws_sdk_go_v2_ini \
		aws:aws-sdk-go-v2:v1.11.0:aws_aws_sdk_go_v2_credentials \
		aws:aws-sdk-go-v2:v1.11.1:aws_aws_sdk_go_v2_sso \
		aws:aws-sdk-go-v2:v1.16.0:aws_aws_sdk_go_v2 \
		aws:aws-sdk-go-v2:v1.16.1:aws_aws_sdk_go_v2_sts \
		aws:aws-sdk-go-v2:v1.9.1:aws_aws_sdk_go_v2_presigned_url/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:aws-sdk-go:v1.44.315:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		aws:smithy-go:v1.11.1:aws_smithy_go/vendor/github.com/aws/smithy-go \
		axiomhq:hyperloglog:3ddf4bad03dc:axiomhq_hyperloglog/vendor/github.com/axiomhq/hyperloglog \
		baidubce:bce-sdk-go:v0.9.141:baidubce_bce_sdk_go/vendor/github.com/baidubce/bce-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmatcuk:doublestar:v1.3.4:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		buger:jsonparser:v1.1.1:buger_jsonparser/vendor/github.com/buger/jsonparser \
		c2h5oh:datasize:28bbd4740fee:c2h5oh_datasize/vendor/github.com/c2h5oh/datasize \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.4.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cncf:udpa:c52dc94e7fbe:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:e9ce68804cb4:cncf_xds_go/vendor/github.com/cncf/xds \
		containerd:fifo:v1.0.0:containerd_fifo/vendor/github.com/containerd/fifo \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cristalhq:hedgedhttp:v0.7.2:cristalhq_hedgedhttp/vendor/github.com/cristalhq/hedgedhttp \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dennwc:varint:v1.0.0:dennwc_varint/vendor/github.com/dennwc/varint \
		dgryski:go-metro:280f6062b5bc:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		digitalocean:godo:v1.98.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:distribution:v2.8.2:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-plugins-helpers:1e6269c305b8:docker_go_plugins_helpers/vendor/github.com/docker/go-plugins-helpers \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		drone:envsubst:v1.0.3:drone_envsubst/vendor/github.com/drone/envsubst \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.3.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:bf00bc1b83b6:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		edsrzf:mmap-go:v1.1.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		efficientgo:core:v1.0.0-rc.2:efficientgo_core/vendor/github.com/efficientgo/core \
		emicklei:go-restful:v3.10.1:emicklei_go_restful_v3/vendor/github.com/emicklei/go-restful/v3 \
		envoyproxy:go-control-plane:9239064ad72f:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.10.1:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:v3.5.4:etcd_io_etcd/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:v3.5.4:etcd_io_etcd_1/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:v3.5.4:etcd_io_etcd_2/vendor/go.etcd.io/etcd/client/v3 \
		facette:natsort:2cd4dd1e2dcb:facette_natsort/vendor/github.com/facette/natsort \
		fatih:color:v1.15.0:fatih_color/vendor/github.com/fatih/color \
		felixge:fgprof:v0.9.3:felixge_fgprof/vendor/github.com/felixge/fgprof \
		felixge:httpsnoop:v1.0.3:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fluent:fluent-bit-go:ea13c021720c:fluent_fluent_bit_go/vendor/github.com/fluent/fluent-bit-go \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify_1/vendor/gopkg.in/fsnotify/fsnotify.v1 \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:fake-gcs-server:v1.7.0:fsouza_fake_gcs_server/vendor/github.com/fsouza/fake-gcs-server \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-kit:kit:v0.12.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.6.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v1.2.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-openapi:analysis:v0.21.4:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.20.3:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:jsonpointer:v0.19.6:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.20.2:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.21.2:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:spec:v0.20.8:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.21.3:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.22.3:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.22.1:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-playground:locales:v0.14.1:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.1:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.11.2:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-zookeeper:zk:v1.0.3:go_zookeeper_zk/vendor/github.com/go-zookeeper/zk \
		go4org:netipx:8449b0a6169f:go4org_go4/vendor/go4.org/netipx \
		gofrs:flock:v0.8.1:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:googleapis:v1.4.0:gogo_googleapis/vendor/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		gogo:status:v1.1.1:gogo_status/vendor/github.com/gogo/status \
		golang-jwt:jwt:v4.5.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.14.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:10a507213a29:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.12.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.10.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.3.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.13.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.13.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.13.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.3.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.11.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:04be3eba64a2:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.1.2:google_btree/vendor/github.com/google/btree \
		google:gnostic:v0.6.9:google_gnostic/vendor/github.com/google/gnostic \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:e85fd2cbaebc:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.2.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:pprof:1710fef4ab10:google_pprof/vendor/github.com/google/pprof \
		google:renameio:v2.0.0:google_renameio_v2/vendor/github.com/google/renameio/v2 \
		google:s2a-go:v0.1.4:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.2.3:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.11.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.126.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigtable/v1.18.1:googleapis_google_cloud_go_bigtable \
		googleapis:google-cloud-go:compute/metadata/v0.2.3:googleapis_google_cloud_go_1/vendor/cloud.google.com/go/compute/metadata \
		googleapis:google-cloud-go:compute/v1.20.1:googleapis_google_cloud_go_compute \
		googleapis:google-cloud-go:longrunning/v0.4.1:googleapis_google_cloud_go_longrunning \
		googleapis:google-cloud-go:pubsub/v1.30.0:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:storage/v1.29.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.110.2:googleapis_google_cloud_go \
		googleapis:google-cloud-go:v0.13.0:googleapis_google_cloud_go_iam/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v1.2.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grafana:cloudflare-go:c627cf6792f2:grafana_cloudflare_go/vendor/github.com/grafana/cloudflare-go \
		grafana:dskit:740f56bd2934:grafana_dskit/vendor/github.com/grafana/dskit \
		grafana:go-gelf:v2.0.1:grafana_go_gelf_v2/vendor/github.com/grafana/go-gelf/v2 \
		grafana:gocql:ba5dc39ece85:grafana_gocql/vendor/github.com/gocql/gocql \
		grafana:gomemcache:a081dae0aba9:grafana_gomemcache/vendor/github.com/grafana/gomemcache \
		grafana:memberlist:09ffed8adbbe:grafana_memberlist/vendor/github.com/hashicorp/memberlist \
		grafana:regexp:b4c2bcb0a4b6:grafana_regexp/vendor/github.com/grafana/regexp \
		grafana:tail:77b18831edf0:grafana_tail/vendor/github.com/grafana/tail \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.56.3:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		hashicorp:consul:api/v1.20.0:hashicorp_consul_api \
		hashicorp:consul:v1.5.1:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v1.4.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.1:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.7.2:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-uuid:v1.0.3:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.6.0:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:serf:v0.10.1:hashicorp_serf/vendor/github.com/hashicorp/serf \
		heroku:x:v0.0.59:heroku_x/vendor/github.com/heroku/x \
		huandu:xstrings:v1.3.3:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.15:imdario_mergo/vendor/github.com/imdario/mergo \
		influxdata:go-syslog:a1889d947b48:influxdata_go_syslog_v3/vendor/github.com/influxdata/go-syslog/v3 \
		influxdata:telegraf:v1.16.3:influxdata_telegraf/vendor/github.com/influxdata/telegraf \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.7.6:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v8.4.3:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joncrlsn:dque:956d14155fa2:joncrlsn_dque/vendor/github.com/joncrlsn/dque \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		klauspost:compress:v1.16.7:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.2.5:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kubernetes-sigs:json:bc3834ca7abd:kubernetes_sigs_json/vendor/sigs.k8s.io/json \
		kubernetes-sigs:structured-merge-diff:v4.2.3:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.3.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.26.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.26.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.26.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.90.1:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:afdc3dddf62d:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:d77c459e9343:kubernetes_utils/vendor/k8s.io/utils \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		leodido:ragel-machinery:299bdde78165:leodido_ragel_machinery/vendor/github.com/leodido/ragel-machinery \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.17:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.53:miekg_dns/vendor/github.com/miekg/dns \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.61:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:sha256-simd:v1.0.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v23.0.3:moby_moby/vendor/github.com/docker/docker \
		moby:term:3f7ff695adc6:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.11.2:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		ncw:swift:v1.0.53:ncw_swift/vendor/github.com/ncw/swift \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		open-telemetry:opentelemetry-go-contrib:zpages/v0.40.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp \
		open-telemetry:opentelemetry-go:metric/v0.37.0:open_telemetry_opentelemetry_go_1/vendor/go.opentelemetry.io/otel/metric \
		open-telemetry:opentelemetry-go:v1.14.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.2:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing-contrib:go-grpc:73cb765af46e:opentracing_contrib_go_grpc/vendor/github.com/opentracing-contrib/go-grpc \
		opentracing-contrib:go-stdlib:v1.0.0:opentracing_contrib_go_stdlib/vendor/github.com/opentracing-contrib/go-stdlib \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		oschwald:geoip2-golang:v1.8.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.10.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pierrec:lz4:v4.1.17:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pkg:browser:681adbf594b8:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:alertmanager:v0.25.0:prometheus_alertmanager/vendor/github.com/prometheus/alertmanager \
		prometheus:client_golang:v1.16.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.4.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.1.0:prometheus_common_sigv4/vendor/github.com/prometheus/common/sigv4 \
		prometheus:common:v0.43.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.9.1:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.10.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:69155c6ba1e9:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		richardartoul:molecule:v1.0.0:richardartoul_molecule/vendor/github.com/richardartoul/molecule \
		rootless-containers:rootlesskit:v1.1.0:rootless_containers_rootlesskit/vendor/github.com/rootless-containers/rootlesskit \
		rs:xid:v1.5.0:rs_xid/vendor/github.com/rs/xid \
		rsc:binaryregexp:v0.2.0:rsc_binaryregexp/vendor/rsc.io/binaryregexp \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		segmentio:fasthash:v1.0.3:segmentio_fasthash/vendor/github.com/segmentio/fasthash \
		sercand:kuberesolver:v4.0.0:sercand_kuberesolver_v4/vendor/github.com/sercand/kuberesolver/v4 \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:0d455de96546:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/github.com/soheilhy/cmux \
		sony:gobreaker:v0.5.0:sony_gobreaker/vendor/github.com/sony/gobreaker \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		spf13:afero:v1.9.5:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.5.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.8.3:stretchr_testify/vendor/github.com/stretchr/testify \
		thanos-io:objstore:11ffbc490204:thanos_io_objstore/vendor/github.com/thanos-io/objstore \
		tonistiigi:fifo:a9fb20d87448:tonistiigi_fifo/vendor/github.com/tonistiigi/fifo \
		uber-go:atomic:v1.11.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.2.1:uber_go_goleak/vendor/go.uber.org/goleak \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.21.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.30.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		ugorji:go:v1.1.7:ugorji_go_codec/vendor/github.com/ugorji/go \
		weaveworks:common:334485600903:weaveworks_common/vendor/github.com/weaveworks/common \
		weaveworks:promrus:v1.2.0:weaveworks_promrus/vendor/github.com/weaveworks/promrus \
		willf:bitset:v1.1.11:willf_bitset/vendor/github.com/willf/bitset \
		willf:bloom:v2.0.3:willf_bloom/vendor/github.com/willf/bloom \
		xdg-go:pbkdf2:v1.0.0:xdg_go_pbkdf2/vendor/github.com/xdg-go/pbkdf2 \
		xdg-go:scram:v1.1.2:xdg_go_scram/vendor/github.com/xdg-go/scram \
		xdg-go:stringprep:v1.0.4:xdg_go_stringprep/vendor/github.com/xdg-go/stringprep \
		yuin:gopher-lua:v1.1.0:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

USE_RC_SUBR=	loki promtail

GO_TARGET=	./cmd/loki ./cmd/loki-canary ./cmd/logcli ./clients/cmd/promtail
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=HEAD \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
		${LD_FLAG_X_PREFIX}.BuildDate=$$(date -u +"%Y-%m-%dT%H:%M:%SZ")
LD_FLAG_X_PREFIX=	-X github.com/grafana/loki/pkg/util/build
BUILD_USER?=	${USER}

LOKI_USER?=	loki
LOKI_GROUP?=	loki
LOKI_DATADIR?=	/var/db/${PORTNAME}

PROMTAIL_USER?=	promtail
PROMTAIL_GROUP?=	promtail
PROMTAIL_DATADIR?=	/var/db/promtail

SUB_LIST=	LOKI_USER=${LOKI_USER} \
		LOKI_GROUP=${LOKI_GROUP} \
		LOKI_DATADIR=${LOKI_DATADIR} \
		PROMTAIL_USER=${PROMTAIL_USER} \
		PROMTAIL_GROUP=${PROMTAIL_GROUP} \
		PROMTAIL_DATADIR=${PROMTAIL_DATADIR}

USERS=		${LOKI_USER} ${PROMTAIL_USER}
GROUPS=		${LOKI_GROUP} ${PROMTAIL_GROUP}

PLIST_SUB=	${SUB_LIST}

post-extract:
	@${RLN} ${WRKSRC_googleapis_google_cloud_go} ${WRKSRC}/vendor/cloud.google.com/go
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigtable}/bigtable ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute}/compute ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_longrunning}/longrunning ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_azcore}/sdk/azcore ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore

post-install:
	@${CP} ${WRKSRC}/cmd/loki/loki-local-config.yaml ${STAGEDIR}${PREFIX}/etc/loki.yaml.sample
	@${CP} ${WRKSRC}/clients/cmd/promtail/promtail-local-config.yaml ${STAGEDIR}${PREFIX}/etc/promtail.yaml.sample
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}/rules-temp
	@${MKDIR} ${STAGEDIR}${PROMTAIL_DATADIR}

.include <bsd.port.mk>

PORTNAME=	loki
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	grafana-

MAINTAINER=	freebsd@funzi.org
COMMENT=	Scalable, highly-available, multi-tenant log aggregation system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 armv7 armv6 amd64 i386
USES=		go:modules cpe
CPE_VENDOR=	grafana
USE_GITHUB=	yes


GH_ACCOUNT=	grafana
GH_PROJECT=	loki
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:v36.2.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:76c7860e9b60:azure_go_autorest_auth \
		Azure:go-autorest:a46566dfcbdc:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.24:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		MasslessParticle:azure-storage-blob-go:b5e698eff68e:masslessparticle_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.2:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Microsoft:go-winio:v0.4.17:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		Shopify:sarama:v1.30.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		Workiva:go-datastructures:v1.0.53:workiva_go_datastructures/vendor/github.com/Workiva/go-datastructures \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		alicebob:gopher-json:a9ecdc9d1d3a:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.14.3:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		armon:go-metrics:v0.3.9:armon_go_metrics/vendor/github.com/armon/go-metrics \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		aws:aws-sdk-go:v1.43.10:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		baidubce:bce-sdk-go:v0.9.81:baidubce_bce_sdk_go/vendor/github.com/baidubce/bce-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmatcuk:doublestar:v1.2.2:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		buger:jsonparser:v1.1.1:buger_jsonparser/vendor/github.com/buger/jsonparser \
		c2h5oh:datasize:28bbd4740fee:c2h5oh_datasize/vendor/github.com/c2h5oh/datasize \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		containerd:containerd:v1.5.9:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:fifo:v1.0.0:containerd_fifo/vendor/github.com/containerd/fifo \
		coreos:etcd:v3.3.25:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		cristalhq:hedgedhttp:v0.7.0:cristalhq_hedgedhttp/vendor/github.com/cristalhq/hedgedhttp \
		cyriltovena:cloudflare-go:ff77400bcb93:cyriltovena_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dennwc:varint:v1.0.0:dennwc_varint/vendor/github.com/dennwc/varint \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		digitalocean:godo:v1.75.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-plugins-helpers:1e6269c305b8:docker_go_plugins_helpers/vendor/github.com/docker/go-plugins-helpers \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		drone:envsubst:v1.0.2:drone_envsubst/vendor/github.com/drone/envsubst \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		edsrzf:mmap-go:v1.1.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:v3.3.25:etcd_io_etcd \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_1/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_2/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:v3.5.0:etcd_io_etcd_3/vendor/go.etcd.io/etcd/client/v3 \
		facette:natsort:2cd4dd1e2dcb:facette_natsort/vendor/github.com/facette/natsort \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		felixge:fgprof:v0.9.1:felixge_fgprof/vendor/github.com/felixge/fgprof \
		felixge:httpsnoop:v1.0.2:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fluent:fluent-bit-go:ea13c021720c:fluent_fluent_bit_go/vendor/github.com/fluent/fluent-bit-go \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify_1/vendor/gopkg.in/fsnotify.v1 \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:fake-gcs-server:v1.7.0:fsouza_fake_gcs_server/vendor/github.com/fsouza/fake-gcs-server \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-kit:kit:v0.12.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-kit:log:v0.2.0:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v1.2.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-openapi:analysis:v0.20.0:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.20.0:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.20.2:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:runtime:v0.19.29:go_openapi_runtime/vendor/github.com/go-openapi/runtime \
		go-openapi:spec:v0.20.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.21.2:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.15:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.20.2:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-redis:redis:v8.11.4:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-zookeeper:zk:v1.0.2:go_zookeeper_zk/vendor/github.com/go-zookeeper/zk \
		go4org:go4:d4a079459e60:go4org_go4/vendor/go4.org/intern \
		go4org:go4:d4a079459e60:go4org_go4_1/vendor/go4.org/unsafe/assume-no-moving-gc \
		gofrs:flock:v0.7.1:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:googleapis:v1.4.0:gogo_googleapis/vendor/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		gogo:status:v1.1.0:gogo_status/vendor/github.com/gogo/status \
		golang-jwt:jwt:v4.2.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:e495a2d5b3d3:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.5.1:golang_mod/vendor/golang.org/x/mod \
		golang:net:cd36cc0744dd:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d3ed0bb246c8:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:00053529121e:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:90d013bbcef8:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.9:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.7:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:daf995802d7b:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:pprof:0368bd9e19a7:google_pprof/vendor/github.com/google/pprof \
		google:renameio:v2.0.0:google_renameio_v2/vendor/github.com/google/renameio/v2 \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.5.5:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.70.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigtable/v1.3.0:googleapis_google_cloud_go_bigtable \
		googleapis:google-cloud-go:compute/v1.3.0:googleapis_google_cloud_go_compute \
		googleapis:google-cloud-go:kms/v1.0.0:googleapis_google_cloud_go_kms \
		googleapis:google-cloud-go:pubsub/v1.3.1:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.1.0:googleapis_google_cloud_go_iam/vendor/cloud.google.com/go/iam \
		googleapis:google-cloud-go:v0.100.2:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.24.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grafana:dskit:99f3d0043c23:grafana_dskit/vendor/github.com/grafana/dskit \
		grafana:go-gelf:v2.0.1:grafana_go_gelf_v2/vendor/github.com/grafana/go-gelf/v2 \
		grafana:gocql:ba5dc39ece85:grafana_gocql/vendor/github.com/gocql/gocql \
		grafana:memberlist:bd88e10a3d91:grafana_memberlist/vendor/github.com/hashicorp/memberlist \
		grafana:regexp:149c8afcd6cb:grafana_regexp/vendor/github.com/grafana/regexp \
		grafana:tail:98e8eb28ea4c:grafana_tail/vendor/github.com/hpcloud/tail \
		grpc-ecosystem:go-grpc-middleware:9f6bf00c00a7:grpc_ecosystem_go_grpc_middleware_v2/vendor/github.com/grpc-ecosystem/go-grpc-middleware/v2 \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.44.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		hashicorp:consul:v1.12.0:hashicorp_consul_api \
		hashicorp:consul:v1.5.1:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.16.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.1:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:serf:v0.9.6:hashicorp_serf/vendor/github.com/hashicorp/serf \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inetaf:netaddr:c74959edd3b6:inetaf_netaddr/vendor/inet.af/netaddr \
		influxdata:go-syslog:a1889d947b48:influxdata_go_syslog_v3/vendor/github.com/influxdata/go-syslog/v3 \
		influxdata:telegraf:v1.16.3:influxdata_telegraf/vendor/github.com/influxdata/telegraf \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joncrlsn:dque:956d14155fa2:joncrlsn_dque/vendor/github.com/joncrlsn/dque \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		klauspost:compress:v1.14.1:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kubernetes-sigs:json:c049b76a60c6:kubernetes_sigs_json/vendor/sigs.k8s.io/json \
		kubernetes-sigs:structured-merge-diff:v4.2.1:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.23.6:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.23.6:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.23.6:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.40.1:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:e816edb12b65:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:6203023598ed:kubernetes_utils/vendor/k8s.io/utils \
		leodido:ragel-machinery:299bdde78165:leodido_ragel_machinery/vendor/github.com/leodido/ragel-machinery \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.46:miekg_dns/vendor/github.com/miekg/dns \
		minio:md5-simd:v1.1.0:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.24:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v20.10.12:moby_moby/vendor/github.com/docker/docker \
		moby:term:3f7ff695adc6:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.7.5:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		ncw:swift:v1.0.52:ncw_swift/vendor/github.com/ncw/swift \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		open-telemetry:opentelemetry-go-contrib:zpages/v0.29.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp \
		open-telemetry:opentelemetry-go:metric/v0.27.0:open_telemetry_opentelemetry_go_1/vendor/go.opentelemetry.io/otel/internal/metric \
		open-telemetry:opentelemetry-go:metric/v0.27.0:open_telemetry_opentelemetry_go_2/vendor/go.opentelemetry.io/otel/metric \
		open-telemetry:opentelemetry-go:v1.4.1:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.2:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing-contrib:go-grpc:73cb765af46e:opentracing_contrib_go_grpc/vendor/github.com/opentracing-contrib/go-grpc \
		opentracing-contrib:go-stdlib:v1.0.0:opentracing_contrib_go_stdlib/vendor/github.com/opentracing-contrib/go-stdlib \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pierrec:lz4:v2.6.1:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pierrec:lz4:v4.1.12:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:alertmanager:e35efbddb66a:prometheus_alertmanager/vendor/github.com/prometheus/alertmanager \
		prometheus:client_golang:v1.12.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.1.0:prometheus_common_sigv4/vendor/github.com/prometheus/common/sigv4 \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.7.1:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:edfe657b5405:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		rsc:binaryregexp:v0.2.0:rsc_binaryregexp/vendor/rsc.io/binaryregexp \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		segmentio:fasthash:v1.0.2:segmentio_fasthash/vendor/github.com/segmentio/fasthash \
		sercand:kuberesolver:v2.4.0:sercand_kuberesolver/vendor/github.com/sercand/kuberesolver \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:0d455de96546:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sony:gobreaker:v0.4.1:sony_gobreaker/vendor/github.com/sony/gobreaker \
		spaolacci:murmur3:f09979ecbc72:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify \
		thanos-io:thanos:c5505f5eaa7d:thanos_io_thanos/vendor/github.com/thanos-io/thanos \
		themihai:gomemcache:24332e2d58ab:themihai_gomemcache/vendor/github.com/bradfitz/gomemcache \
		tonistiigi:fifo:a9fb20d87448:tonistiigi_fifo/vendor/github.com/tonistiigi/fifo \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.12:uber_go_goleak/vendor/go.uber.org/goleak \
		uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.19.1:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.30.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		ugorji:go:v1.1.7:ugorji_go_codec/vendor/github.com/ugorji/go \
		weaveworks:common:e3b70df0f08b:weaveworks_common/vendor/github.com/weaveworks/common \
		weaveworks:promrus:v1.2.0:weaveworks_promrus/vendor/github.com/weaveworks/promrus \
		willf:bitset:v1.1.11:willf_bitset/vendor/github.com/willf/bitset \
		willf:bloom:v2.0.3:willf_bloom/vendor/github.com/willf/bloom \
		xdg-go:pbkdf2:v1.0.0:xdg_go_pbkdf2/vendor/github.com/xdg-go/pbkdf2 \
		xdg-go:scram:v1.0.2:xdg_go_scram/vendor/github.com/xdg-go/scram \
		xdg-go:stringprep:v1.0.2:xdg_go_stringprep/vendor/github.com/xdg-go/stringprep \
		yuin:gopher-lua:ee81675732da:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

USE_RC_SUBR=	loki

GO_TARGET=	./cmd/loki ./cmd/loki-canary ./cmd/logcli ./clients/cmd/promtail

SUB_LIST=	LOKI_USER=${LOKI_USER} \
		LOKI_GROUP=${LOKI_GROUP} \
		LOKI_DATADIR=${LOKI_DATADIR}

LOKI_USER?=	loki
LOKI_GROUP?=	loki

USERS=		${LOKI_USER}
GROUPS=		${LOKI_GROUP}

PLIST_SUB=	${SUB_LIST}

LOKI_DATADIR?=	/var/db/${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigtable}/bigtable ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute}/compute ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/kms
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_kms}/kms ${WRKSRC}/vendor/cloud.google.com/go/kms
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/consul/api
	@${RLN} ${WRKSRC_hashicorp_consul_api}/api ${WRKSRC}/vendor/github.com/hashicorp/consul/api
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io
	@${RLN} ${WRKSRC_coreos_etcd} ${WRKSRC}/vendor/go.etcd.io/etcd
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in/fsnotify
	@${RLN} ${WRKSRC_fsnotify_fsnotify_1} ${WRKSRC}/vendor/gopkg.in/fsnotify/fsnotify.v1

post-install:
	@${CP} ${WRKSRC}/cmd/loki/loki-local-config.yaml ${STAGEDIR}${PREFIX}/etc/loki.yaml.sample
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}/rules-temp

.include <bsd.port.mk>

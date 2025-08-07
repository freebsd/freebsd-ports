PORTNAME=	beats
DISTVERSIONPREFIX=	v
DISTVERSION=	7.17.11
PORTREVISION=	16
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	7

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Send logs, network, metrics and heartbeat to elasticsearch or logstash
WWW=		https://www.elastic.co/products/beats/

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/mage:devel/mage

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	elastic
GH_TUPLE=	Azure:azure-amqp-common-go:v3.2.1:azure_azure_amqp_common_go_v3/vendor/github.com/Azure/azure-amqp-common-go/v3 \
		Azure:azure-event-hubs-go:v3.3.15:azure_azure_event_hubs_go_v3/vendor/github.com/Azure/azure-event-hubs-go/v3 \
		Azure:azure-pipeline-go:v0.2.1:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.8.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-amqp:v0.16.0:azure_go_amqp/vendor/github.com/Azure/go-amqp \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:4e2e1bb52ffb:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.18:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:b965d219bd9d:azure_go_autorest_auth \
		Azure:go-autorest:cc407fb4f94c:azure_go_autorest_cli \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Masterminds:semver:v1.4.2:masterminds_semver/vendor/github.com/Masterminds/semver \
		PaesslerAG:gval:v1.0.0:paesslerag_gval/vendor/github.com/PaesslerAG/gval \
		PaesslerAG:jsonpath:v0.1.1:paesslerag_jsonpath/vendor/github.com/PaesslerAG/jsonpath \
		StackExchange:wmi:9f32b5905fd6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		adriansr:fsnotify:a81f2b630e7c:adriansr_fsnotify_1/vendor/github.com/fsnotify/fsnotify \
		adriansr:gopacket:dd62abfa8a41:adriansr_gopacket/vendor/github.com/google/gopacket \
		aerospike:aerospike-client-go:0f3b54da6bdc:aerospike_aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		akavel:rsrc:v0.8.0:akavel_rsrc/vendor/github.com/akavel/rsrc \
		andrewkroh:goja:dd2ac4456e20:andrewkroh_goja/vendor/github.com/dop251/goja \
		andrewkroh:sys:287798fe3e43:andrewkroh_sys/vendor/github.com/andrewkroh/sys \
		antlr:antlr4:be881fa6b91d:antlr_antlr4/vendor/github.com/antlr/antlr4 \
		apache:thrift:eac4d0c79a5f:apache_thrift/vendor/github.com/apache/thrift \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		aws:aws-lambda-go:v1.13.3:aws_aws_lambda_go/vendor/github.com/aws/aws-lambda-go \
		aws:aws-sdk-go-v2:v0.24.0:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:aws-sdk-go:v1.19.48:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		awslabs:goformation:v4.1.0:awslabs_goformation_v4/vendor/github.com/awslabs/goformation/v4 \
		awslabs:kinesis-aggregation:d352038274c0:awslabs_kinesis_aggregation_go/vendor/github.com/awslabs/kinesis-aggregation \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bi-zone:go-winio:v0.4.15:bi_zone_go_winio/vendor/github.com/Microsoft/go-winio \
		blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bsm:sarama-cluster:7e67d87a6b3f:bsm_sarama_cluster/vendor/github.com/bsm/sarama-cluster \
		cavaliergopher:badio:ce5280129e9e:cavaliergopher_badio/vendor/github.com/cavaliergopher/badio \
		cavaliergopher:rpm:7a9c54e3d83e:cavaliergopher_go_rpm/vendor/github.com/cavaliergopher/rpm \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.3.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudfoundry-community:go-cfclient:35bcce23fc5f:cloudfoundry_community_go_cfclient/vendor/github.com/cloudfoundry-community/go-cfclient \
		cloudfoundry-incubator:rfc5424:236a6d29298a:cloudfoundry_incubator_rfc5424/vendor/code.cloudfoundry.org/rfc5424 \
		cloudfoundry:go-diodes:f77fb823c7ee:cloudfoundry_go_diodes/vendor/code.cloudfoundry.org/go-diodes \
		cloudfoundry:go-loggregator:v7.4.0:cloudfoundry_go_loggregator/vendor/code.cloudfoundry.org/go-loggregator \
		cloudfoundry:gofileutils:4d0c80011a0f:cloudfoundry_gofileutils/vendor/code.cloudfoundry.org/gofileutils \
		cloudfoundry:noaa:v2.1.0:cloudfoundry_noaa/vendor/github.com/cloudfoundry/noaa \
		cloudfoundry:sonde-go:b33733203bb4:cloudfoundry_sonde_go/vendor/github.com/cloudfoundry/sonde-go \
		cncf:udpa:04548b0d99d4:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:a8f946100490:cncf_xds_go/vendor/github.com/cncf/xds \
		containerd:containerd:v1.5.13:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:fifo:bda0ff6ed73c:containerd_fifo_1/vendor/github.com/tonistiigi/fifo \
		containerd:fifo:v1.0.0:containerd_fifo/vendor/github.com/containerd/fifo \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		cucumber:godog:v0.8.1:cucumber_godog/vendor/github.com/cucumber/godog \
		cyphar:filepath-securejoin:v0.2.3:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davecgh:go-xdr:e6a2ba005892:davecgh_go_xdr/vendor/github.com/davecgh/go-xdr \
		denisenkom:go-mssqldb:bbfc9a55622e:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		devigned:tab:0c15cf42f9a2:devigned_tab/vendor/github.com/devigned/tab \
		dgraph-io:badger:v3.2103.1:dgraph_io_badger_v3/vendor/github.com/dgraph-io/badger/v3 \
		dgraph-io:ristretto:v0.1.0:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		digitalocean:go-libvirt:6075ea3c39a1:digitalocean_go_libvirt/vendor/github.com/digitalocean/go-libvirt \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dlclark:regexp2:7632a260cbaf:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docker:distribution:v2.8.0:docker_distribution/vendor/github.com/docker/distribution \
		docker:engine:ea84732a7725:docker_engine/vendor/github.com/docker/docker \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dolmen-go:contextio:68fc5150bcd5:dolmen_go_contextio/vendor/github.com/dolmen-go/contextio \
		dop251:goja_nodejs:adff31b136e6:dop251_goja_nodejs/vendor/github.com/dop251/goja_nodejs \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:0d940dd29fd2:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		elastic:apm-agent-go:v1.15.0:elastic_apm_agent_go \
		elastic:dhcp:57ec251c7eb3:elastic_dhcp/vendor/github.com/insomniacslk/dhcp \
		elastic:ecs-logging-go-zap:v1.0.1:elastic_ecs_logging_go_zap/vendor/go.elastic.co/ecszap \
		elastic:ecs:v1.12.0:elastic_ecs/vendor/github.com/elastic/ecs \
		elastic:elastic-agent-client:f0905d9377f6:elastic_elastic_agent_client_v7/vendor/github.com/elastic/elastic-agent-client/v7 \
		elastic:elastic-agent-libs:v0.2.11:elastic_elastic_agent_libs/vendor/github.com/elastic/elastic-agent-libs \
		elastic:elastic-agent-system-metrics:v0.4.4:elastic_elastic_agent_system_metrics/vendor/github.com/elastic/elastic-agent-system-metrics \
		elastic:fsevents:e1d381a4d270:elastic_fsevents/vendor/github.com/fsnotify/fsevents \
		elastic:glog:7d8b5c89dfc4:elastic_glog/vendor/github.com/golang/glog \
		elastic:go-concert:v0.2.0:elastic_go_concert/vendor/github.com/elastic/go-concert \
		elastic:go-fastjson:v1.1.0:elastic_go_fastjson/vendor/go.elastic.co/fastjson \
		elastic:go-libaudit:v2.3.1:elastic_go_libaudit_v2/vendor/github.com/elastic/go-libaudit/v2 \
		elastic:go-licence-detector:v0.5.0:elastic_go_licence_detector/vendor/go.elastic.co/go-licence-detector \
		elastic:go-licenser:v0.4.0:elastic_go_licenser/vendor/github.com/elastic/go-licenser \
		elastic:go-lookslike:v0.3.0:elastic_go_lookslike/vendor/github.com/elastic/go-lookslike \
		elastic:go-lumber:v0.1.0:elastic_go_lumber/vendor/github.com/elastic/go-lumber \
		elastic:go-perf:9c656876f595:elastic_go_perf/vendor/github.com/elastic/go-perf \
		elastic:go-plugins-helpers:bdf17607b79f:elastic_go_plugins_helpers/vendor/github.com/docker/go-plugins-helpers \
		elastic:go-seccomp-bpf:v1.2.0:elastic_go_seccomp_bpf/vendor/github.com/elastic/go-seccomp-bpf \
		elastic:go-structform:v0.0.9:elastic_go_structform/vendor/github.com/elastic/go-structform \
		elastic:go-sysinfo:v1.8.1:elastic_go_sysinfo/vendor/github.com/elastic/go-sysinfo \
		elastic:go-txfile:v0.0.7:elastic_go_txfile/vendor/github.com/elastic/go-txfile \
		elastic:go-ucfg:v0.8.6:elastic_go_ucfg/vendor/github.com/elastic/go-ucfg \
		elastic:go-windows:v1.0.1:elastic_go_windows/vendor/github.com/elastic/go-windows \
		elastic:gosigar:v0.14.2:elastic_gosigar/vendor/github.com/elastic/gosigar \
		elastic:sarama:11c3ef800752:elastic_sarama/vendor/github.com/Shopify/sarama \
		envoyproxy:go-control-plane:49ff273808a1:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.6.2:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		evanphx:json-patch:v4.9.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-mgo:mgo:3f83fa500528:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-test:deep:v1.0.7:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gobuffalo:here:v0.6.0:gobuffalo_here/vendor/github.com/gobuffalo/here \
		gocarina:gocsv:ffef3ffc77be:gocarina_gocsv/vendor/github.com/gocarina/gocsv \
		godbus:dbus:ade71ed3457e:godbus_dbus/vendor/github.com/godbus/dbus \
		godbus:dbus:v5.0.5:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		godror:godror:v0.10.4:godror_godror/vendor/github.com/godror/godror \
		gofrs:flock:5135e617513b:gofrs_flock/vendor/github.com/gofrs/flock \
		gofrs:uuid:v4.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.0.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:6edffad5e616:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:2871e0cb64e4:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d3ed0bb246c8:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:c0bba94af5f8:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.11:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodule:redigo:v1.8.3:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:flatbuffers:v1.12.1:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:31bebdecfb46:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:licenseclassifier:879cb1424de0:google_licenseclassifier/vendor/github.com/google/licenseclassifier \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.62.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigquery/v1.8.0:googleapis_google_cloud_go_bigquery \
		googleapis:google-cloud-go:monitoring/v1.1.0:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:pubsub/v1.17.1:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:v0.99.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorhill:cronexpr:88b0669f7d75:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		gotestyourself:gotestsum:v0.6.0:gotestyourself_gotestsum/vendor/gotest.tools/gotestsum \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.46.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.1.1:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.6:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.0.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:nomad:e31695b5bbe6:hashicorp_nomad_api/vendor/github.com/hashicorp/nomad \
		hectane:go-acl:da78bae5fc95:hectane_go_acl/vendor/github.com/hectane/go-acl \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:v1.0.4:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v3.0.0:jcmturner_goidentity/vendor/gopkg.in/jcmturner/goidentity.v3 \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jmoiron:sqlx:d7d95172beb5:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		joeshaw:multierror:69b34d4ec901:joeshaw_multierror/vendor/github.com/joeshaw/multierror \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		josephspurrier:goversioninfo:63e6d1acd3dd:josephspurrier_goversioninfo/vendor/github.com/josephspurrier/goversioninfo \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kardianos:service:a323c3813bc7:kardianos_service/vendor/github.com/kardianos/service \
		karrick:godirwalk:v1.15.8:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes-sigs:structured-merge-diff:v4.1.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.21.1:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.21.1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.21.1:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.8.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:591a79e4bda7:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:67b214c5f920:kubernetes_utils/vendor/k8s.io/utils \
		lib:pq:2ff3cb3adc01:lib_pq/vendor/github.com/lib/pq \
		magefile:mage:v1.14.0:magefile_mage/vendor/github.com/magefile/mage \
		mailru:easyjson:v0.7.1:mailru_easyjson/vendor/github.com/mailru/easyjson \
		markbates:pkger:v0.17.0:markbates_pkger/vendor/github.com/markbates/pkger \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:7c0f6868bffe:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.41:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:hashstructure:ab25296c0f51:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:iochan:v1.0.0:mitchellh_iochan/vendor/github.com/mitchellh/iochan \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:spdystream:v0.2.0:moby_spdystream/vendor/github.com/moby/spdystream \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.2:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		osquery:osquery-go:99b4efa62ec5:osquery_osquery_go/vendor/github.com/osquery/osquery-go \
		otiai10:copy:v1.2.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pierrre:gotestcover:924dca7d15f0:pierrre_gotestcover/vendor/github.com/pierrre/gotestcover \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		poy:eachers:23942921fe77:poy_eachers/vendor/github.com/apoydence/eachers \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.10.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:v2.5.0:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		samuel:go-parser:ca8abbf65d0e:samuel_go_parser/vendor/github.com/samuel/go-parser \
		samuel:go-thrift:2187045faa54:samuel_go_thrift/vendor/github.com/samuel/go-thrift \
		sanathkr:go-yaml:ed9d249f429b:sanathkr_go_yaml/vendor/github.com/sanathkr/go-yaml \
		sanathkr:yaml:0056894fa522:sanathkr_yaml/vendor/github.com/sanathkr/yaml \
		santhosh-tekuri:jsonschema:v1.2.4:santhosh_tekuri_jsonschema/vendor/github.com/santhosh-tekuri/jsonschema \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shirou:gopsutil:v3.20.12:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.3.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tsg:go-daemon:e704b93fd89b:tsg_go_daemon/vendor/github.com/tsg/go-daemon \
		tsg:gopacket:2ab8e397a786:tsg_gopacket/vendor/github.com/tsg/gopacket \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.21.0:uber_go_zap/vendor/go.uber.org/zap \
		ugorji:go:v1.1.8:ugorji_go_codec/vendor/github.com/ugorji/go \
		urso:diag:21b3cc8eb797:urso_diag/vendor/github.com/urso/diag \
		urso:go-bin:781c575c9f0e:urso_go_bin/vendor/github.com/urso/go-bin \
		urso:magetools:290c89e0c230:urso_magetools/vendor/github.com/urso/magetools \
		urso:sderr:52b04e8f5c71:urso_sderr/vendor/github.com/urso/sderr \
		vmware:govmomi:2cad15190b41:vmware_govmomi/vendor/github.com/vmware/govmomi \
		xdg:scram:v1.0.3:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.3:xdg_stringprep/vendor/github.com/xdg/stringprep \
		yuin:gopher-lua:b402f3114ec7:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.howett.net:go:plist:607711222ff2484a487cdec33866b965f4a89653:go_plist/vendor/howett.net/plist

USE_RC_SUBR=	${GO_TARGETS}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
CGO_CFLAGS=	-I.
CGO_LDFLAGS=	-L.
MAKE_ENV+=	GOBUILD_FLAGS="-mod=vendor"

CONFLICTS=	beats6*

PORTSCOUT=	limit:^7

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		AUDITBEAT FILEBEAT HEARTBEAT METRICBEAT PACKETBEAT
OPTIONS_DEFAULT=	FILEBEAT HEARTBEAT METRICBEAT
OPTIONS_SUB=		yes

AUDITBEAT_DESC=			Auditbeat
FILEBEAT_DESC=			Filebeat
HEARTBEAT_DESC=			Heartbeat
METRICBEAT_DESC=		Metricbeat
PACKETBEAT_DESC=		Packetbeat
AUDITBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/auditbeat/:auditbeat
AUDITBEAT_DISTFILES=		auditbeat-${DISTVERSION}-darwin-x86_64.tar.gz:auditbeat
AUDITBEAT_VARS=			GO_TARGETS+=auditbeat
FILEBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/filebeat/:filebeat
FILEBEAT_DISTFILES=		filebeat-${DISTVERSION}-darwin-x86_64.tar.gz:filebeat
FILEBEAT_VARS=			GO_TARGETS+=filebeat
HEARTBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/heartbeat/:heartbeat
HEARTBEAT_DISTFILES=		heartbeat-${DISTVERSION}-darwin-x86_64.tar.gz:heartbeat
HEARTBEAT_VARS=			GO_TARGETS+=heartbeat
METRICBEAT_MASTER_SITES=	https://artifacts.elastic.co/downloads/beats/metricbeat/:metricbeat
METRICBEAT_DISTFILES=		metricbeat-${DISTVERSION}-darwin-x86_64.tar.gz:metricbeat
METRICBEAT_VARS=		GO_TARGETS+=metricbeat
PACKETBEAT_MASTER_SITES=	https://artifacts.elastic.co/downloads/beats/packetbeat/:packetbeat
PACKETBEAT_DISTFILES=		packetbeat-${DISTVERSION}-darwin-x86_64.tar.gz:packetbeat
PACKETBEAT_VARS=		CGO_CFLAGS+=-I/usr/include \
				CGO_LDFLAGS+=-L/usr/lib \
				GO_TARGETS+=packetbeat

.include <bsd.port.options.mk>

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigquery}/bigquery ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
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
	@${RLN} ${WRKSRC_elastic_apm_agent_go} ${WRKSRC}/vendor/go.elastic.co/apm

post-patch:
	${REINPLACE_CMD} -e "s|%%BEATSVERSION%%|v${PORTVERSION}|g" ${WRKSRC}/dev-tools/mage/settings.go
.for BEATMOD in ${GO_TARGETS}
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/${BEATMOD}/*.yml
.endfor

do-build:
.for GO_TARGET in ${GO_TARGETS}
	(cd ${GO_WRKSRC}/${GO_TARGET}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${LOCALBASE}/bin/mage build)
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for BEATMOD in ${GO_TARGETS}
	${MKDIR} ${STAGEDIR}/var/db/beats/${BEATMOD}
	${INSTALL_PROGRAM} ${GO_WRKSRC}/${BEATMOD}/${BEATMOD} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${BEATMOD}/${BEATMOD}.yml \
		${STAGEDIR}${ETCDIR}/${BEATMOD}.yml.sample
	${INSTALL_DATA} ${WRKSRC}/${BEATMOD}/${BEATMOD}.reference.yml \
		${STAGEDIR}${ETCDIR}/${BEATMOD}.yml.reference
.endfor
.for BEATMOD in ${GO_TARGETS}
	(MODULE_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/module; \
	 if [ -d $${MODULE_SRC} ]; then \
	   MODULE_DEST=${STAGEDIR}${DATADIR}/${BEATMOD}/module && \
	   ${MKDIR} $${MODULE_DEST} && \
	   cd $${MODULE_SRC} && ${COPYTREE_SHARE} . $${MODULE_DEST} && \
	   cd $${MODULE_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${DATADIR_REL}/${BEATMOD}/module,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${DATADIR_REL}/${BEATMOD}/module,' >> ${TMPPLIST}; \
	 fi)
	(MODULESD_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/modules.d; \
	 if [ -d $${MODULESD_SRC} ]; then \
	   MODULESD_DEST=${STAGEDIR}${EXAMPLESDIR}/${BEATMOD}.modules.d && \
	   ${MKDIR} $${MODULESD_DEST} && \
	   cd $${MODULESD_SRC} && ${COPYTREE_SHARE} . $${MODULESD_DEST} && \
	   cd $${MODULESD_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${EXAMPLESDIR_REL}/${BEATMOD}.modules.d,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${EXAMPLESDIR_REL}/${BEATMOD}.modules.d,' >> ${TMPPLIST}; \
	   ${MKDIR} ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d && \
	   echo "The modules.d files are now in ${EXAMPLESDIR}/${BEATMOD}.modules.d" > \
	     ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d/README; \
	   echo ${ETCDIR_REL}/${BEATMOD}.modules.d/README >> ${TMPPLIST}; \
	 fi)
	(MONITORSD_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/monitors.d; \
	 if [ -d $${MONITORSD_SRC} ]; then \
	   MONITORSD_DEST=${STAGEDIR}${EXAMPLESDIR}/${BEATMOD}.monitors.d && \
	   ${MKDIR} $${MONITORSD_DEST} && \
	   cd $${MONITORSD_SRC} && ${COPYTREE_SHARE} . $${MONITORSD_DEST} && \
	   cd $${MONITORSD_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${EXAMPLESDIR_REL}/${BEATMOD}.monitors.d,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${EXAMPLESDIR_REL}/${BEATMOD}.monitors.d,' >> ${TMPPLIST}; \
	   ${MKDIR} ${STAGEDIR}${ETCDIR}/${BEATMOD}.monitors.d && \
	   echo "The monitors.d files are now in ${EXAMPLESDIR}/${BEATMOD}.monitors.d" > \
	     ${STAGEDIR}${ETCDIR}/${BEATMOD}.monitors.d/README; \
	   echo ${ETCDIR_REL}/${BEATMOD}.monitors.d/README >> ${TMPPLIST}; \
	 fi)
	(KIBANA_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/kibana; \
	 if [ -d $${KIBANA_SRC} ]; then \
	   KIBANA_PATH=${STAGEDIR}${DATADIR}/${BEATMOD}/kibana; \
	   ${MKDIR} $${KIBANA_PATH} && \
	   cd $${KIBANA_SRC} && ${COPYTREE_SHARE} . $${KIBANA_PATH}; \
	   cd $${KIBANA_PATH} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${DATADIR_REL}/${BEATMOD}/kibana,' >> ${TMPPLIST}; \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${DATADIR_REL}/${BEATMOD}/kibana,' >> ${TMPPLIST}; \
	 fi)
.endfor

.include <bsd.port.mk>

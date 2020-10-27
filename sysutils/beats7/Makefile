# $FreeBSD$

PORTNAME=	beats
PORTVERSION=	7.9.3
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	7

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Send logs, network, metrics and heartbeat to elasticsearch or logstash

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/mage:devel/mage

USES=		gmake go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

GH_ACCOUNT=	elastic
GH_TUPLE=	\
		Azure:azure-amqp-common-go:v3.0.0:azure_azure_amqp_common_go_v3/vendor/github.com/Azure/azure-amqp-common-go/v3 \
		Azure:azure-event-hubs-go:v3.1.2:azure_azure_event_hubs_go_v3/vendor/github.com/Azure/azure-event-hubs-go/v3 \
		Azure:azure-pipeline-go:v0.2.1:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:v37.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-storage-blob-go:v0.8.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-amqp:v0.12.6:azure_go_amqp/vendor/github.com/Azure/go-amqp \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date \
		Azure:go-autorest:aff029487b89:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.9.4:azure_go_autorest_autorest \
		Azure:go-autorest:b965d219bd9d:azure_go_autorest_auth \
		Azure:go-autorest:cc407fb4f94c:azure_go_autorest_cli \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		Azure:go-autorest:v12.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Masterminds:semver:v1.4.2:masterminds_semver/vendor/github.com/Masterminds/semver \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.7:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		StackExchange:wmi:9f32b5905fd6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		adriansr:fsnotify:c9bbe1f46f1d:adriansr_fsnotify/vendor/github.com/fsnotify/fsnotify \
		adriansr:gopacket:dd62abfa8a41:adriansr_gopacket_1/vendor/github.com/google/gopacket \
		aerospike:aerospike-client-go:0f3b54da6bdc:aerospike_aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		akavel:rsrc:v0.8.0:akavel_rsrc/vendor/github.com/akavel/rsrc \
		andrewkroh:goja:dd2ac4456e20:andrewkroh_goja_1/vendor/github.com/dop251/goja \
		andrewkroh:sys:287798fe3e43:andrewkroh_sys/vendor/github.com/andrewkroh/sys \
		antlr:antlr4:a4c66dc863bb:antlr_antlr4/vendor/github.com/antlr/antlr4 \
		apoydence:eachers:23942921fe77:apoydence_eachers/vendor/github.com/apoydence/eachers \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		aws:aws-lambda-go:v1.6.0:aws_aws_lambda_go/vendor/github.com/aws/aws-lambda-go \
		aws:aws-sdk-go-v2:v0.9.0:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		awslabs:goformation:v4.1.0:awslabs_goformation_v4/vendor/github.com/awslabs/goformation/v4 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blakesmith:ar:8bd4349a67f2:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bradleyfalzon:ghinstallation:v1.1.0:bradleyfalzon_ghinstallation/vendor/github.com/bradleyfalzon/ghinstallation \
		bsm:sarama-cluster:7e67d87a6b3f:bsm_sarama_cluster/vendor/github.com/bsm/sarama-cluster \
		cavaliercoder:badio:ce5280129e9e:cavaliercoder_badio/vendor/github.com/cavaliercoder/badio \
		cavaliercoder:go-rpm:7a9c54e3d83e:cavaliercoder_go_rpm/vendor/github.com/cavaliercoder/go-rpm \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudfoundry-community:go-cfclient:35bcce23fc5f:cloudfoundry_community_go_cfclient/vendor/github.com/cloudfoundry-community/go-cfclient \
		cloudfoundry:go-diodes:f77fb823c7ee:cloudfoundry_go_diodes/vendor/code.cloudfoundry.org/go-diodes \
		cloudfoundry:go-loggregator:v7.4.0:cloudfoundry_go_loggregator/vendor/code.cloudfoundry.org/go-loggregator \
		cloudfoundry:gofileutils:4d0c80011a0f:cloudfoundry_gofileutils/vendor/code.cloudfoundry.org/gofileutils \
		cloudfoundry:noaa:v2.1.0:cloudfoundry_noaa/vendor/github.com/cloudfoundry/noaa \
		cloudfoundry-incubator:rfc5424:236a6d29298a:cloudfoundry_rfc5424/vendor/code.cloudfoundry.org/rfc5424 \
		cloudfoundry:sonde-go:b33733203bb4:cloudfoundry_sonde_go/vendor/github.com/cloudfoundry/sonde-go \
		containerd:containerd:v1.3.3:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:26c1120b8d41:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:fifo:bda0ff6ed73c:containerd_fifo/vendor/github.com/containerd/fifo \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		coreos:pkg:97fdf19511ea:coreos_pkg/vendor/github.com/coreos/pkg \
		cucumber:godog:v0.8.1:cucumber_godog/vendor/github.com/cucumber/godog \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davecgh:go-xdr:e6a2ba005892:davecgh_go_xdr/vendor/github.com/davecgh/go-xdr \
		denisenkom:go-mssqldb:bbfc9a55622e:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		devigned:tab:0c15cf42f9a2:devigned_tab/vendor/github.com/devigned/tab \
		dgrijalva:jwt-go:5e25c22bd5d6:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		digitalocean:go-libvirt:6075ea3c39a1:digitalocean_go_libvirt/vendor/github.com/digitalocean/go-libvirt \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dlclark:regexp2:7632a260cbaf:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:engine:ea84732a7725:docker_engine/vendor/github.com/docker/docker \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dop251:goja_nodejs:adff31b136e6:dop251_goja_nodejs/vendor/github.com/dop251/goja_nodejs \
		dustin:go-humanize:bb3d318650d4:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:0d940dd29fd2:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		elastic:apm-agent-go:v1.7.2:elastic_apm_agent_go/vendor/go.elastic.co/apm \
		elastic:dhcp:57ec251c7eb3:elastic_dhcp/vendor/github.com/insomniacslk/dhcp \
		elastic:ecs-logging-go-zap:cdd95a104193:elastic_ecs_logging_go_zap/vendor/go.elastic.co/ecszap \
		elastic:ecs:v1.5.0:elastic_ecs/vendor/github.com/elastic/ecs \
		elastic:elastic-agent-client:d43b7ad5833a:elastic_elastic_agent_client_v7/vendor/github.com/elastic/elastic-agent-client/v7 \
		elastic:fsevents:e1d381a4d270:elastic_fsevents_1/vendor/github.com/fsnotify/fsevents \
		elastic:go-concert:v0.0.3:elastic_go_concert/vendor/github.com/elastic/go-concert \
		elastic:go-fastjson:v1.0.0:elastic_go_fastjson/vendor/go.elastic.co/fastjson \
		elastic:go-libaudit:92371bef3fb8:elastic_go_libaudit_v2/vendor/github.com/elastic/go-libaudit/v2 \
		elastic:go-licence-detector:v0.4.0:elastic_go_licence_detector/vendor/go.elastic.co/go-licence-detector \
		elastic:go-licenser:v0.3.1:elastic_go_licenser/vendor/github.com/elastic/go-licenser \
		elastic:go-lookslike:v0.3.0:elastic_go_lookslike/vendor/github.com/elastic/go-lookslike \
		elastic:go-lumber:v0.1.0:elastic_go_lumber/vendor/github.com/elastic/go-lumber \
		elastic:go-perf:9c656876f595:elastic_go_perf/vendor/github.com/elastic/go-perf \
		elastic:go-plugins-helpers:bdf17607b79f:elastic_go_plugins_helpers_1/vendor/github.com/docker/go-plugins-helpers \
		elastic:go-seccomp-bpf:v1.1.0:elastic_go_seccomp_bpf/vendor/github.com/elastic/go-seccomp-bpf \
		elastic:go-structform:v0.0.7:elastic_go_structform/vendor/github.com/elastic/go-structform \
		elastic:go-sysinfo:v1.3.0:elastic_go_sysinfo/vendor/github.com/elastic/go-sysinfo \
		elastic:go-txfile:v0.0.7:elastic_go_txfile/vendor/github.com/elastic/go-txfile \
		elastic:go-ucfg:v0.8.3:elastic_go_ucfg/vendor/github.com/elastic/go-ucfg \
		elastic:go-windows:v1.0.1:elastic_go_windows/vendor/github.com/elastic/go-windows \
		elastic:gosigar:f115143bb233:elastic_gosigar/vendor/github.com/elastic/gosigar \
		elastic:sarama:0e7b69039eec:elastic_sarama/vendor/github.com/Shopify/sarama \
		etcd-io:bbolt:v1.3.4:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		evanphx:json-patch:v4.2.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.5.0:fatih_color/vendor/github.com/fatih/color \
		garyburd:redigo:b8dc90050f24:garyburd_redigo/vendor/github.com/garyburd/redigo \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-mgo:mgo:3f83fa500528:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:14974a1cf647:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:here:v0.6.0:gobuffalo_here/vendor/github.com/gobuffalo/here \
		gocarina:gocsv:ffef3ffc77be:gocarina_gocsv/vendor/github.com/gocarina/gocsv \
		godbus:dbus:ade71ed3457e:godbus_dbus/vendor/github.com/godbus/dbus \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		godror:godror:v0.10.4:godror_godror/vendor/github.com/godror/godror \
		gofrs:flock:5135e617513b:gofrs_flock/vendor/github.com/gofrs/flock \
		gofrs:uuid:v3.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:06a226fb4e37:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:da58074b4299:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:910be7a94367:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:16171245cfb2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:c00d67ef29d0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:flatbuffers:7a6b2bf521e9:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f3c370f40bfb:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v28.1.1:google_go_github_v28/vendor/github.com/google/go-github/v28 \
		google:go-github:v29.0.2:google_go_github_v29/vendor/github.com/google/go-github/v29 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:licenseclassifier:879cb1424de0:google_licenseclassifier/vendor/github.com/google/licenseclassifier \
		google:uuid:c2e93f3ae59f:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:25d8b0b66985:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:datastore/v1.0.0:googleapis_google_cloud_go_datastore \
		googleapis:google-cloud-go:pubsub/v1.0.1:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:storage/v1.0.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.51.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorhill:cronexpr:d520615e531a:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		gorilla:mux:v1.7.2:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		grpc-ecosystem:grpc-gateway:v1.13.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.12:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.6:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.0.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:59383c442f7d:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		haya14busa:go-actions-toolkit:ca0307860f01:haya14busa_go_actions_toolkit/vendor/github.com/haya14busa/go-actions-toolkit \
		hectane:go-acl:da78bae5fc95:hectane_go_acl/vendor/github.com/hectane/go-acl \
		imdario:mergo:v0.3.6:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v3.0.0:jcmturner_goidentity/vendor/gopkg.in/jcmturner/goidentity.v3 \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jmoiron:sqlx:d7d95172beb5:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		joeshaw:multierror:69b34d4ec901:joeshaw_multierror/vendor/github.com/joeshaw/multierror \
		josephspurrier:goversioninfo:14b0ab84c6ca:josephspurrier_goversioninfo/vendor/github.com/josephspurrier/goversioninfo \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.8:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		karrick:godirwalk:v1.15.6:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		klauspost:compress:v1.9.8:klauspost_compress/vendor/github.com/klauspost/compress \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.18.3:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.18.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.18.3:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:61e04a5be9a6:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:a9aa75ae1b89:kubernetes_utils/vendor/k8s.io/utils \
		leighmcculloch:embedfiles:995e0740726f:leighmcculloch_embedfiles/vendor/4d63.com/embedfiles \
		leighmcculloch:go-tz:6d37baae851b:leighmcculloch_go_tz/vendor/4d63.com/tz \
		lib:pq:2ff3cb3adc01:lib_pq/vendor/github.com/lib/pq \
		magefile:mage:v1.10.0:magefile_mage/vendor/github.com/magefile/mage \
		mailru:easyjson:v0.7.1:mailru_easyjson/vendor/github.com/mailru/easyjson \
		markbates:pkger:v0.17.0:markbates_pkger/vendor/github.com/markbates/pkger \
		mattn:go-colorable:v0.0.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:7c0f6868bffe:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.2:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.7:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.15:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:hashstructure:ab25296c0f51:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:iochan:v1.0.0:mitchellh_iochan/vendor/github.com/mitchellh/iochan \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		opencontainers:go-digest:ac19fd6e7483:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:775207bd45b6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc9:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pierrec:lz4:v2.4.1:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pierrre:gotestcover:7b94f124d338:pierrre_gotestcover/vendor/github.com/pierrre/gotestcover \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		poy:eachers:23942921fe77:poy_eachers \
		prometheus:client_golang:20428fa0bffc:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:v2.5.0:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cac0b30c2563:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		reviewdog:errorformat:8983be9bc7dd:reviewdog_errorformat/vendor/github.com/reviewdog/errorformat \
		reviewdog:reviewdog:v0.9.17:reviewdog_reviewdog/vendor/github.com/reviewdog/reviewdog \
		samuel:go-parser:ca8abbf65d0e:samuel_go_parser/vendor/github.com/samuel/go-parser \
		samuel:go-thrift:2187045faa54:samuel_go_thrift/vendor/github.com/samuel/go-thrift \
		sanathkr:go-yaml:ed9d249f429b:sanathkr_go_yaml/vendor/github.com/sanathkr/go-yaml \
		sanathkr:yaml:0056894fa522:sanathkr_yaml/vendor/github.com/sanathkr/yaml \
		santhosh-tekuri:jsonschema:v1.2.4:santhosh_tekuri_jsonschema/vendor/github.com/santhosh-tekuri/jsonschema \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shirou:gopsutil:v2.19.11:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tsg:go-daemon:e704b93fd89b:tsg_go_daemon/vendor/github.com/tsg/go-daemon \
		tsg:gopacket:2ab8e397a786:tsg_gopacket/vendor/github.com/tsg/gopacket \
		uber-go:atomic:v1.5.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.3.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.14.0:uber_go_zap/vendor/go.uber.org/zap \
		urso:diag:21b3cc8eb797:urso_diag/vendor/github.com/urso/diag \
		urso:go-bin:781c575c9f0e:urso_go_bin/vendor/github.com/urso/go-bin \
		urso:magetools:290c89e0c230:urso_magetools/vendor/github.com/urso/magetools \
		urso:sderr:c2a16f3d43ec:urso_sderr/vendor/github.com/urso/sderr \
		vmware:govmomi:2cad15190b41:vmware_govmomi/vendor/github.com/vmware/govmomi \
		xanzy:go-gitlab:v0.22.3:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab \
		yuin:gopher-lua:b402f3114ec7:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

USE_RC_SUBR=	${GO_TARGETS}

CONFLICTS=	beats6*

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
FIND_ARGS=	"! ( -regex .*/*\.(go|in|log) ) ! -path *test* ! -path *vendor*"
MAKE_ENV+=	GOBUILD_FLAGS="-mod=vendor"

CGO_CFLAGS=	-I.
CGO_LDFLAGS=	-L.

OPTIONS_DEFAULT=FILEBEAT HEARTBEAT METRICBEAT
OPTIONS_DEFINE=	FILEBEAT HEARTBEAT METRICBEAT AUDITBEAT PACKETBEAT
OPTIONS_SUB=	yes

FILEBEAT_DESC=	Filebeat
FILEBEAT_VARS=	GO_TARGETS+=filebeat

PACKETBEAT_DESC=Packetbeat
PACKETBEAT_VARS=GO_TARGETS+=packetbeat CGO_CFLAGS+=-I/usr/include CGO_LDFLAGS+=-L/usr/lib

METRICBEAT_DESC=Metricbeat
METRICBEAT_VARS=GO_TARGETS+=metricbeat

HEARTBEAT_DESC=	Heartbeat
HEARTBEAT_VARS=	GO_TARGETS+=heartbeat

AUDITBEAT_DESC=	Auditbeat
AUDITBEAT_VARS=	GO_TARGETS+=auditbeat

.include <bsd.port.options.mk>

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/datastore
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_datastore}/datastore ${WRKSRC}/vendor/cloud.google.com/go/datastore
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
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${MKDIR} ${WRKSRC}/vendor/github.com/poy
	@${RLN} ${WRKSRC_apoydence_eachers} ${WRKSRC}/vendor/github.com/poy/eachers

post-patch:
	${REINPLACE_CMD} -e "s|%%BEATSVERSION%%|v${PORTVERSION}|g" ${WRKSRC}/dev-tools/mage/settings.go

do-build:
.for GO_TARGET in ${GO_TARGETS}
#	(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} -C ${GO_TARGET})
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
	(KIBANA_PATH=${STAGEDIR}${DATADIR}/${BEATMOD}/kibana; \
		${MKDIR} $${KIBANA_PATH}; \
		DASHBOARD_FIND_ARGS="-path */_meta/kibana -type d"; \
		DASHBOARD_PATHS=$$(${SETENV} ${FIND} ${WRKSRC}/${BEATMOD} $${DASHBOARD_FIND_ARGS}); \
		for DASHBOARD_PATH in $${DASHBOARD_PATHS}; \
		do \
			(cd $${DASHBOARD_PATH} && ${COPYTREE_SHARE} . $${KIBANA_PATH}); \
		done)
.endfor
.for BEATMOD in filebeat metricbeat
.if !empty(GO_TARGETS:M${BEATMOD})
	${MKDIR} ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d ${STAGEDIR}${DATADIR}/${BEATMOD}/module
	(cd ${WRKSRC}/${BEATMOD}/module && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${BEATMOD}/module ${FIND_ARGS})
	(cd ${WRKSRC}/${BEATMOD}/modules.d && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d)
.endif
.endfor
.for BEATMOD in auditbeat
.if !empty(GO_TARGETS:M${BEATMOD})
	${MKDIR} ${STAGEDIR}${DATADIR}/${BEATMOD}/module
	(cd ${WRKSRC}/${BEATMOD}/module && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${BEATMOD}/module ${FIND_ARGS})
.endif
.endfor

.include <bsd.port.mk>

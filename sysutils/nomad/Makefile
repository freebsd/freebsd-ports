PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.6
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp

GO_BUILDFLAGS=	-tags ui \
		-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"

USERS=		nomad
GROUPS=		nomad

USE_RC_SUBR=	nomad

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/hashicorp/nomad

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v44.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:0529470822b5:azure_go_autorest_auth \
		Azure:go-autorest:8ac76a649a39:azure_go_autorest_cli \
		Azure:go-autorest:autorest/v0.11.4:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:cbf46deb11b5:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.4.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:datadog-go:v3.2.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		LK4D4:joincontext:1724345da6d5:lk4d4_joincontext/vendor/github.com/LK4D4/joincontext \
		Microsoft:hcsshim:v0.8.9:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.0.0:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-cidr:v1.0.1:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v12.0.0:apparentlymart_go_textseg_v12/vendor/github.com/apparentlymart/go-textseg/v12 \
		apparentlymart:go-textseg:v13.0.0:apparentlymart_go_textseg_v13/vendor/github.com/apparentlymart/go-textseg/v13 \
		armon:circbuf:bbbad097214e:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:v0.3.10:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.42.6:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.3.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		checkpoint-restore:go-criu:v4.1.0:checkpoint_restore_go_criu_v4/vendor/github.com/checkpoint-restore/go-criu/v4 \
		cheggaaa:pb:v3.0.5:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		cilium:ebpf:v0.2.0:cilium_ebpf/vendor/github.com/cilium/ebpf \
		circonus-labs:circonus-gometrics:v2.3.1:circonus_labs_circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		circonus-labs:circonusllhist:v0.1.3:circonus_labs_circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		cncf:udpa:04548b0d99d4:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:cb28da3451f1:cncf_xds_go/vendor/github.com/cncf/xds \
		container-storage-interface:spec:v1.4.0:container_storage_interface_spec/vendor/github.com/container-storage-interface/spec \
		containerd:console:v1.0.1:containerd_console/vendor/github.com/containerd/console \
		containerd:containerd:v1.3.4:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:daa8e1ccc0bc:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:go-cni:d20b7eebc7ee:containerd_go_cni/vendor/github.com/containerd/go-cni \
		containernetworking:cni:dc953e2fd91f:containernetworking_cni/vendor/github.com/containernetworking/cni \
		containernetworking:plugins:2d6d46d308b2:containernetworking_plugins/vendor/github.com/containernetworking/plugins \
		coreos:go-iptables:969b135e941d:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.1.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cyphar:filepath-securejoin:7efe413b52e1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denverdino:aliyungo:a747050bb1ba:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		digitalocean:godo:v1.10.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:cli:eb310fca4956:docker_cli/vendor/github.com/docker/cli \
		docker:docker-credential-helpers:73e5f5dbfea3:docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:engine:v17.12.0-ce-rc1:docker_docker/vendor/github.com/docker/docker \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libnetwork:9e99af28df21:docker_libnetwork/vendor/github.com/docker/libnetwork \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		elazarl:go-bindata-assetfs:234c15e7648f:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		endocrimes:go-winio:fb47a8b41948:endocrimes_go_winio/vendor/github.com/Microsoft/go-winio \
		envoyproxy:go-control-plane:v0.10.0:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.6.2:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify_1/vendor/gopkg.in/fsnotify.v1 \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:v1.6.5:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-resty:resty:v1.12.0:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-tomb:tomb:14b3d72120e8:go_tomb_tomb_1/vendor/gopkg.in/tomb.v2 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:6635138e15ea:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d3ed0bb246c8:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:02f5c0300f6e:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:d6a9af8af023:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:4c6863e31247:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:53e6ce116135:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.60.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.18.2:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.97.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gookit:color:v1.3.1:gookit_color/vendor/github.com/gookit/color \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		grpc-ecosystem:go-grpc-middleware:3ce3d519df39:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.42.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul-template:v0.25.2:hashicorp_consul_template/vendor/github.com/hashicorp/consul-template \
		hashicorp:consul:v1.7.8:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:consul:sdk/v0.9.0:hashicorp_consul_sdk \
		hashicorp:consul:api/v1.12.0:hashicorp_consul_api \
		hashicorp:cronexpr:v1.1.1:hashicorp_cronexpr/vendor/github.com/hashicorp/cronexpr \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-checkpoint:1545e56e46de:hashicorp_go_checkpoint/vendor/github.com/hashicorp/go-checkpoint \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-connlimit:v0.3.0:hashicorp_go_connlimit/vendor/github.com/hashicorp/go-connlimit \
		hashicorp:go-cty-funcs:2721b1e36840:hashicorp_go_cty_funcs/vendor/github.com/hashicorp/go-cty-funcs \
		hashicorp:go-discover:c573d69da192:hashicorp_go_discover/vendor/github.com/hashicorp/go-discover \
		hashicorp:go-envparse:310ca1881b22:hashicorp_go_envparse/vendor/github.com/hashicorp/go-envparse \
		hashicorp:go-getter:v1.5.11:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v1.1.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-memdb:v1.3.2:hashicorp_go_memdb/vendor/github.com/hashicorp/go-memdb \
		hashicorp:go-msgpack:v1.1.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.4.3:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.6.7:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:a07e7d50bbee:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:eb14f8319bdc:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:mdns:v1.0.1:hashicorp_mdns/vendor/github.com/hashicorp/mdns \
		hashicorp:memberlist:v0.2.2:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		hashicorp:net-rpc-msgpackrpc:a14192a58a69:hashicorp_net_rpc_msgpackrpc/vendor/github.com/hashicorp/net-rpc-msgpackrpc \
		hashicorp:raft-boltdb:6e5ba93211ea:hashicorp_raft_boltdb/vendor/github.com/hashicorp/raft-boltdb \
		hashicorp:raft:365023de17e6:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:1ef507638af6:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vault:v0.2.0:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault/sdk \
		hashicorp:vic:bbfe86ec9443:hashicorp_vic/vendor/github.com/hashicorp/vic \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hpcloud:tail:37f427138745:hpcloud_tail/vendor/github.com/hpcloud/tail \
		ishidawataru:sctp:00ab2ac2db07:ishidawataru_sctp/vendor/github.com/ishidawataru/sctp \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:51ffac552869:joyent_triton_go/vendor/github.com/joyent/triton-go \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:pty:v1.1.5:kr_pty/vendor/github.com/kr/pty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		linode:linodego:v0.7.1:linode_linodego/vendor/github.com/linode/linodego \
		mattn:go-colorable:v0.1.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.10:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.26:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:cli:v1.1.0:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:8631ce90f286:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.1.1:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-glint:6515ceb4a127:mitchellh_go_glint/vendor/github.com/mitchellh/go-glint \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:621e5597135b:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-testing-interface:v1.14.1:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.4.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mrunalp:fileutils:v0.5.0:mrunalp_fileutils/vendor/github.com/mrunalp/fileutils \
		nicolai86:scaleway-sdk:798f60e20bb2:nicolai86_scaleway_sdk/vendor/github.com/nicolai86/scaleway-sdk \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		oklog:run:6934b124db28:oklog_run/vendor/github.com/oklog/run \
		onsi:gomega:v1.9.0:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc93:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:e6143ca7d51d:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opencontainers:selinux:v1.8.0:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		packethost:packngo:b9cb5096f54c:packethost_packngo/vendor/github.com/packethost/packngo \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		prometheus:client_golang:v1.4.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		renier:xmlrpc:ce4a1a486c03:renier_xmlrpc/vendor/github.com/renier/xmlrpc \
		rogpeppe:go-internal:v1.6.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:cors:v1.8.0:rs_cors/vendor/github.com/rs/cors \
		ryanuber:columnize:abc90934186a:ryanuber_columnize/vendor/github.com/ryanuber/columnize \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		seccomp:libseccomp-golang:bdab42bd5128:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		shirou:gopsutil:7ea8062810b6:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:75fb7ed4208c:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		softlayer:softlayer-go:260589d94c7d:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:42c35b437635:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		tencentcloud:tencentcloud-sdk-go:v1.0.162:tencentcloud_tencentcloud_sdk_go/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tj:go-spin:v1.1.0:tj_go_spin/vendor/github.com/tj/go-spin \
		tklauser:go-sysconf:v0.3.6:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tv42:httpunix:b75d8614f926:tv42_httpunix/vendor/github.com/tv42/httpunix \
		uber-go:goleak:v1.1.12:uber_go_goleak/vendor/go.uber.org/goleak \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vishvananda:netlink:v1.1.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/vendor/github.com/vishvananda/netns \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		vmware:govmomi:v0.18.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		willf:bitset:v1.1.11:willf_bitset/vendor/github.com/willf/bitset \
		zclconf:go-cty-yaml:v1.0.2:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.8.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/hashicorp/nomad
	@${RLN} ${WRKSRC}/api ${WRKSRC}/vendor/github.com/hashicorp/nomad/api
	@${MKDIR} ${WRKSRC}/vendor/github.com/Nvveen
	@${RLN} ${WRKSRC_docker_docker}/vendor/github.com/Nvveen/Gotty ${WRKSRC}/vendor/github.com/Nvveen/Gotty
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
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
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/consul/api
	@${RLN} ${WRKSRC_hashicorp_consul_api}/api ${WRKSRC}/vendor/github.com/hashicorp/consul/api
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/consul/sdk
	@${RLN} ${WRKSRC_hashicorp_consul_api}/sdk ${WRKSRC}/vendor/github.com/hashicorp/consul/sdk

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nomad
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client1.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client1.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client2.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client2.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/server.hcl ${STAGEDIR}${PREFIX}/etc/nomad/server.hcl.sample

.include <bsd.port.mk>

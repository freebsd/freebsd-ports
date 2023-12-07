PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler
WWW=		https://www.nomadproject.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.21,modules
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
		Azure:azure-sdk-for-go:v56.3.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:0529470822b5:azure_go_autorest_auth \
		Azure:go-autorest:4e2e1bb52ffb:azure_go_autorest_adal \
		Azure:go-autorest:8ac76a649a39:azure_go_autorest_cli \
		Azure:go-autorest:autorest/v0.11.20:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v1.2.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:datadog-go:v3.2.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		LK4D4:joincontext:1724345da6d5:lk4d4_joincontext/vendor/github.com/LK4D4/joincontext \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.2.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.3:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-cidr:v1.0.1:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v13.0.0:apparentlymart_go_textseg_v13/vendor/github.com/apparentlymart/go-textseg/v13 \
		armon:circbuf:bbbad097214e:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:d9ca9af9f1f9:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.44.184:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		brianvoe:gofakeit:v6.20.1:brianvoe_gofakeit_v6/vendor/github.com/brianvoe/gofakeit/v6 \
		cenkalti:backoff:v3.2.2:cenkalti_backoff_v3/vendor/github.com/cenkalti/backoff/v3 \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		checkpoint-restore:go-criu:v5.3.0:checkpoint_restore_go_criu_v5/vendor/github.com/checkpoint-restore/go-criu/v5 \
		cheggaaa:pb:v3.0.5:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		cilium:ebpf:v0.9.1:cilium_ebpf/vendor/github.com/cilium/ebpf \
		circonus-labs:circonus-gometrics:v2.3.1:circonus_labs_circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		circonus-labs:circonusllhist:v0.1.3:circonus_labs_circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		container-storage-interface:spec:v1.7.0:container_storage_interface_spec/vendor/github.com/container-storage-interface/spec \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		containerd:containerd:v1.6.18:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:go-cni:v1.1.9:containerd_go_cni/vendor/github.com/containerd/go-cni \
		containernetworking:cni:v1.1.2:containernetworking_cni/vendor/github.com/containernetworking/cni \
		containernetworking:plugins:v1.2.0:containernetworking_plugins/vendor/github.com/containernetworking/plugins \
		coreos:go-iptables:v0.6.0:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		coreos:go-oidc:v3.1.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		creack:pty:v1.1.18:creack_pty/vendor/github.com/creack/pty \
		cyphar:filepath-securejoin:v0.2.3:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denverdino:aliyungo:a747050bb1ba:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		digitalocean:godo:v1.10.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:cli:v23.0.1:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:v2.8.2:docker_distribution/vendor/github.com/docker/distribution \
		docker:docker-credential-helpers:73e5f5dbfea3:docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libnetwork:64b7a4574d14:docker_libnetwork/vendor/github.com/docker/libnetwork \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		elazarl:go-bindata-assetfs:v1.0.1:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		endocrimes:go-winio:fb47a8b41948:endocrimes_go_winio/vendor/github.com/Microsoft/go-winio \
		etcd-io:bbolt:v1.3.7:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.15.0:fatih_color/vendor/github.com/fatih/color \
		felixge:httpsnoop:v1.0.3:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		fsouza:go-dockerclient:v1.7.9:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-resty:resty:v1.12.0:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-tomb:tomb:14b3d72120e8:go_tomb_tomb_1/vendor/gopkg.in/tomb.v2 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		gojuno:minimock:v3.0.6:gojuno_minimock_v3/vendor/github.com/gojuno/minimock/v3 \
		golang-jwt:jwt:v4.4.3:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang-jwt:jwt:v5.0.0:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.11.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:b0cb94b80691:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.11.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.12.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.4.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.2.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.10.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.10.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.11.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.3.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.6.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:04be3eba64a2:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:76db0878b65f:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:53e6ce116135:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.2.0:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.7.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.103.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.107.0:googleapis_google_cloud_go \
		googleapis:google-cloud-go:compute/v1.15.1:googleapis_google_cloud_go_compute \
		googleapis:google-cloud-go:compute/metadata/v0.2.3:googleapis_google_cloud_go_compute_metadata \
		googleapis:google-cloud-go:storage/v1.27.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:iam/v0.8.0:googleapis_google_cloud_go_iam \
		gookit:color:v1.3.1:gookit_color/vendor/github.com/gookit/color \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		grpc-ecosystem:go-grpc-middleware:v1.4.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.53.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:cap:v0.2.0:hashicorp_cap/vendor/github.com/hashicorp/cap \
		hashicorp:consul-template:v0.31.0:hashicorp_consul_template/vendor/github.com/hashicorp/consul-template \
		hashicorp:consul:api/v1.23.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:consul:sdk/v0.14.0:hashicorp_consul_sdk \
		hashicorp:cronexpr:v1.1.2:hashicorp_cronexpr/vendor/github.com/hashicorp/cronexpr \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-bexpr:v0.1.12:hashicorp_go_bexpr/vendor/github.com/hashicorp/go-bexpr \
		hashicorp:go-checkpoint:1545e56e46de:hashicorp_go_checkpoint/vendor/github.com/hashicorp/go-checkpoint \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-connlimit:v0.3.0:hashicorp_go_connlimit/vendor/github.com/hashicorp/go-connlimit \
		hashicorp:go-cty-funcs:2721b1e36840:hashicorp_go_cty_funcs/vendor/github.com/hashicorp/go-cty-funcs \
		hashicorp:go-discover:a413e131e836:hashicorp_go_discover/vendor/github.com/hashicorp/go-discover \
		hashicorp:go-envparse:310ca1881b22:hashicorp_go_envparse/vendor/github.com/hashicorp/go-envparse \
		hashicorp:go-getter:v1.7.0:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v1.5.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.1:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-immutable-radix:v2.0.0:hashicorp_go_immutable_radix_v2/vendor/github.com/hashicorp/go-immutable-radix/v2 \
		hashicorp:go-kms-wrapping:v2.0.12:hashicorp_go_kms_wrapping_v2/vendor/github.com/hashicorp/go-kms-wrapping/v2 \
		hashicorp:go-memdb:v1.3.4:hashicorp_go_memdb/vendor/github.com/hashicorp/go-memdb \
		hashicorp:go-msgpack:v1.1.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.4.10:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.7.2:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-secure-stdlib:listenerutil/v0.1.4:hashicorp_go_secure_stdlib_listenerutil \
		hashicorp:go-secure-stdlib:mlock/v0.1.2:hashicorp_go_secure_stdlib_mlock/vendor/github.com/hashicorp/go-secure-stdlib \
		hashicorp:go-secure-stdlib:parseutil/v0.1.7:hashicorp_go_secure_stdlib_parseutil \
		hashicorp:go-secure-stdlib:reloadutil/v0.1.1:hashicorp_go_secure_stdlib_reloadutil \
		hashicorp:go-secure-stdlib:strutil/v0.1.2:hashicorp_go_secure_stdlib_strutil \
		hashicorp:go-secure-stdlib:tlsutil/v0.1.2:hashicorp_go_secure_stdlib_tlsutil \
		hashicorp:go-set:v0.1.14:hashicorp_go_set/vendor/github.com/hashicorp/go-set \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.3:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.6.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:golang-lru:v2.0.1:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		hashicorp:hcl:a07e7d50bbee:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:ab3cae0737bc:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:hil:27a72121fd40:hashicorp_hil/vendor/github.com/hashicorp/hil \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:mdns:v1.0.4:hashicorp_mdns/vendor/github.com/hashicorp/mdns \
		hashicorp:memberlist:v0.5.0:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		hashicorp:net-rpc-msgpackrpc:a14192a58a69:hashicorp_net_rpc_msgpackrpc/vendor/github.com/hashicorp/net-rpc-msgpackrpc \
		hashicorp:raft-autopilot:v0.1.6:hashicorp_raft_autopilot/vendor/github.com/hashicorp/raft-autopilot \
		hashicorp:raft-boltdb:v2.2.2:hashicorp_raft_boltdb_v2/vendor/github.com/hashicorp/raft-boltdb \
		hashicorp:raft:v1.5.0:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hashicorp:serf:v0.10.1:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:v0.3.0:hashicorp_vault_kubernetes/vendor/github.com/hashicorp/vault/api/auth/kubernetes \
		hashicorp:vault:sdk/v0.9.0:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault/sdk \
		hashicorp:vault:api/v1.9.1:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vic:bbfe86ec9443:hashicorp_vic/vendor/github.com/hashicorp/vic \
		hashicorp:yamux:v0.1.1:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hpcloud:tail:37f427138745:hpcloud_tail/vendor/github.com/hpcloud/tail \
		huandu:xstrings:v1.4.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.13:imdario_mergo/vendor/github.com/imdario/mergo \
		indeedeng:libtime:v1.6.0:indeedeng_libtime/vendor/oss.indeed.com/go/libtime \
		ishidawataru:sctp:00ab2ac2db07:ishidawataru_sctp/vendor/github.com/ishidawataru/sctp \
		jefferai:isbadcipher:51d2077c035f:jefferai_isbadcipher/vendor/github.com/jefferai/isbadcipher \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:51ffac552869:joyent_triton_go/vendor/github.com/joyent/triton-go \
		klauspost:compress:v1.15.11:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		linode:linodego:v0.7.1:linode_linodego/vendor/github.com/linode/linodego \
		lufia:plan9stats:39d0f177ccd0:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.17:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.12:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.50:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:cli:v1.1.5:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:8631ce90f286:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-glint:6515ceb4a127:mitchellh_go_glint/vendor/github.com/mitchellh/go-glint \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:621e5597135b:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-testing-interface:2d9075ca8770:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:hashstructure:v1.1.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.2.1:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v23.0.3:moby_moby/vendor/github.com/docker/docker \
		moby:patternmatcher:v0.5.0:moby_patternmatcher/vendor/github.com/moby/patternmatcher \
		moby:sys:mount/v0.3.3:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.6.2:moby_sys_mountinfo \
		moby:sys:sequential/v0.5.0:moby_sys_sequential \
		moby:term:3f7ff695adc6:moby_term/vendor/github.com/moby/term \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mrunalp:fileutils:v0.5.0:mrunalp_fileutils/vendor/github.com/mrunalp/fileutils \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		nicolai86:scaleway-sdk:798f60e20bb2:nicolai86_scaleway_sdk/vendor/github.com/nicolai86/scaleway-sdk \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:c5a74bcca799:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.1.8:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:v1.1.0-rc.3:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opencontainers:selinux:v1.10.1:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		packethost:packngo:b9cb5096f54c:packethost_packngo/vendor/github.com/packethost/packngo \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		power-devops:perfstat:5aafc221ea8c:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		prometheus:client_golang:v1.14.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.39.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		renier:xmlrpc:ce4a1a486c03:renier_xmlrpc/vendor/github.com/renier/xmlrpc \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.10.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:cors:v1.8.3:rs_cors/vendor/github.com/rs/cors \
		ryanuber:columnize:v2.1.2:ryanuber_columnize/vendor/github.com/ryanuber/columnize \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		seccomp:libseccomp-golang:v0.10.0:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		shirou:gopsutil:v3.23.4:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		shoenig:go-landlock:v0.1.5:shoenig_go_landlock/vendor/github.com/shoenig/go-landlock \
		shoenig:go-m1cpu:v0.1.6:shoenig_go_m1cpu/vendor/github.com/shoenig/go-m1cpu \
		shoenig:test:v0.6.7:shoenig_test/vendor/github.com/shoenig/test \
		shopspring:decimal:v1.3.1:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:75fb7ed4208c:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		softlayer:softlayer-go:260589d94c7d:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		square:go-jose:v2.6.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.5.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:42c35b437635:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		tencentcloud:tencentcloud-sdk-go:v1.0.162:tencentcloud_tencentcloud_sdk_go/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tj:go-spin:v1.1.0:tj_go_spin/vendor/github.com/tj/go-spin \
		tklauser:go-sysconf:v0.3.11:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.6.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tv42:httpunix:b75d8614f926:tv42_httpunix/vendor/github.com/tv42/httpunix \
		uber-go:goleak:v1.2.1:uber_go_goleak/vendor/go.uber.org/goleak \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vishvananda:netlink:v1.2.1-beta.2:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:50045581ed74:vishvananda_netns/vendor/github.com/vishvananda/netns \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		vmware:govmomi:v0.18.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi \
		zclconf:go-cty-yaml:v1.0.3:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.12.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/hashicorp/nomad
	@${RLN} ${WRKSRC}/api ${WRKSRC}/vendor/github.com/hashicorp/nomad/api
	@${MKDIR} ${WRKSRC}/vendor/cloud.google.com/go
	@${RLN} ${WRKSRC_googleapis_google_cloud_go}/internal ${WRKSRC}/vendor/cloud.google.com/go/internal
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute}/compute ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute_metadata}/compute/metadata ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
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
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/consul/sdk
	@${RLN} ${WRKSRC_hashicorp_consul_sdk}/sdk ${WRKSRC}/vendor/github.com/hashicorp/consul/sdk
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/listenerutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_listenerutil}/listenerutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/listenerutil
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/parseutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_parseutil}/parseutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/parseutil
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/reloadutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_reloadutil}/reloadutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/reloadutil
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/strutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_strutil}/strutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/strutil
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/tlsutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_tlsutil}/tlsutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/tlsutil
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RLN} ${WRKSRC_moby_sys_sequential}/sequential ${WRKSRC}/vendor/github.com/moby/sys/sequential

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nomad
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client1.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client1.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client2.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client2.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/server.hcl ${STAGEDIR}${PREFIX}/etc/nomad/server.hcl.sample

.include <bsd.port.mk>

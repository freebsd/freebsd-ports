PORTNAME=	nomad-pot-driver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Nomad driver to support pot jails

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pot:sysutils/pot \
		nomad:sysutils/nomad

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	trivago
GH_SUBDIR=	src/github.com/trivago/nomad-pot-driver

GO_TARGET=	:${PREFIX}/libexec/nomad/plugins/nomad-pot-driver

PLIST_FILES=	libexec/nomad/plugins/nomad-pot-driver
SUB_FILES=	pkg-message

GH_TUPLE=	\
		LK4D4:joincontext:1724345da6d5:lk4d4_joincontext/vendor/github.com/LK4D4/joincontext \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		NVIDIA:gpu-monitoring-tools:0d8df858cca4:nvidia_gpu_monitoring_tools/vendor/github.com/NVIDIA/gpu-monitoring-tools \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		appc:spec:v0.8.11:appc_spec/vendor/github.com/appc/spec \
		armon:go-metrics:ec5e00d3c878:armon_go_metrics/vendor/github.com/armon/go-metrics \
		checkpoint-restore:go-criu:fcdcd07065c5:checkpoint_restore_go_criu/vendor/github.com/checkpoint-restore/go-criu \
		containerd:go-cni:60d125212faf:containerd_go_cni/vendor/github.com/containerd/go-cni \
		containernetworking:plugins:v0.8.3:containernetworking_plugins/vendor/github.com/containernetworking/plugins \
		coreos:go-iptables:v0.4.3:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:cli:13fb276442f5:docker_cli/vendor/github.com/docker/cli \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		fsouza:go-dockerclient:v1.6.0:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go4org:go4:132d2879e1e9:go4org_go4/vendor/go4.org \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:a832865fa7ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ca1201d0de80:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:52ab43148777:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		gorhill:cronexpr:88b0669f7d75:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		grpc:grpc-go:v1.23.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul-template:v0.23.0:hashicorp_consul_template/vendor/github.com/hashicorp/consul-template \
		hashicorp:consul:v1.3.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:consul:v1.6.2:hashicorp_consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-envparse:150b3a2a4611:hashicorp_go_envparse/vendor/github.com/hashicorp/go-envparse \
		hashicorp:go-getter:v1.4.0:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.10.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:23165f7bc3c2:hashicorp_go_msgpack/vendor/github.com/ugorji/go \
		hashicorp:go-msgpack:96ddbed8d05b:hashicorp_go_msgpack_1/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.0.1:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-version:v1.1.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:gopsutil:62d5761ddb7d:hashicorp_gopsutil/vendor/github.com/shirou/gopsutil \
		hashicorp:hcl2:fb75b3253c80:hashicorp_hcl2/vendor/github.com/hashicorp/hcl2 \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:nomad:b31573ae7206:hashicorp_nomad_api \
		hashicorp:nomad:v0.10.1:hashicorp_nomad/vendor/github.com/hashicorp/nomad \
		hashicorp:raft:v1.1.1:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hashicorp:serf:v0.8.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:621e5597135b:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v0.6.3:moby_moby_1/vendor/github.com/docker/docker-credential-helpers \
		moby:moby:v1.13.1:moby_moby/vendor/github.com/docker/docker \
		mrunalp:fileutils:7d4729fb3618:mrunalp_fileutils/vendor/github.com/mrunalp/fileutils \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		opencontainers:runc:6cc515888830:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:selinux:v1.3.1:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		seccomp:libseccomp-golang:v0.9.1:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		vbatts:tar-split:v0.11.1:vbatts_tar_split/vendor/github.com/vbatts/tar-split \
		vmihailenco:msgpack:v3.3.3:vmihailenco_msgpack/vendor/github.com/vmihailenco/msgpack \
		zclconf:go-cty:v1.1.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${RLN} ${WRKSRC_hashicorp_consul} ${WRKSRC}/vendor/github.com/hashicorp/consul
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/nomad/api
	@${RLN} ${WRKSRC_hashicorp_nomad_api}/api ${WRKSRC}/vendor/github.com/hashicorp/nomad/api
	@${MKDIR} ${WRKSRC}/vendor/github.com/moby
	@${RLN} ${WRKSRC_moby_moby} ${WRKSRC}/vendor/github.com/moby/moby

.include <bsd.port.mk>

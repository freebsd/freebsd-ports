PORTNAME=	tt
PORTVERSION=	2.1.2
DISTVERSIONSUFFIX=	-complete
MASTER_SITES=	https://github.com/tarantool/tt/releases/download/v${PORTVERSION}/
WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}
CATEGORIES=	sysutils databases

MAINTAINER=	mail@void.so
COMMENT=	Command-line utility to manage Tarantool applications
WWW=		https://github.com/tarantool/tt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 aarch64
ONLY_FOR_ARCHS_REASON=	the managed program only supports these architectures

BUILD_DEPENDS=  ${LOCALBASE}/bin/mage:devel/mage

USES=		go:modules

PLIST_FILES=	bin/tt

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${LOCALBASE}/bin/mage build

GH_TUPLE=	\
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		FZambia:tarantool:v0.2.1:fzambia_tarantool/vendor/github.com/FZambia/tarantool \
		Microsoft:go-winio:v0.5.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		StackExchange:wmi:fe8f1750fd46:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		adam-hanna:arrayOperations:v0.2.6:adam_hanna_arrayoperations/vendor/github.com/adam-hanna/arrayOperations \
		alecthomas:participle:v2.0.0-alpha4:alecthomas_participle_v2/vendor/github.com/alecthomas/participle/v2 \
		apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		avast:retry-go:v3.0.0:avast_retry_go/vendor/github.com/avast/retry-go \
		briandowns:spinner:v1.11.1:briandowns_spinner/vendor/github.com/briandowns/spinner \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		containerd:containerd:v1.6.26:containerd_containerd/vendor/github.com/containerd/containerd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		dave:jennifer:v1.5.0:dave_jennifer/vendor/github.com/dave/jennifer \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:distribution:v2.8.2:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		etcd-io:etcd:v3.5.9:etcd_io_etcd/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:v3.5.9:etcd_io_etcd_1/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:v3.5.9:etcd_io_etcd_2/vendor/go.etcd.io/etcd/client/v3 \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		go-ole:go-ole:v1.2.5:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.17.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:613f0c0eb8a1:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.15.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:782d3b101e98:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.58.3:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-version:v1.4.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jedib0t:go-pretty:v6.4.6:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		klauspost:compress:v1.15.9:klauspost_compress/vendor/github.com/klauspost/compress \
		magefile:mage:v1.12.1:magefile_mage/vendor/github.com/magefile/mage \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pointer:v0.0.1:mattn_go_pointer/vendor/github.com/mattn/go-pointer \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:v0.0.3:mattn_go_tty/vendor/github.com/mattn/go-tty \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:moby:v24.0.7:moby_moby/vendor/github.com/docker/docker \
		moby:patternmatcher:v0.6.0:moby_patternmatcher/vendor/github.com/moby/patternmatcher \
		moby:sys:sequential/v0.5.0:moby_sys_sequential/vendor/github.com/moby/sys \
		moby:term:4eb28fa6025c:moby_term/vendor/github.com/moby/term \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:3a7f492d3f1b:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.1.5:opencontainers_runc/vendor/github.com/opencontainers/runc \
		otiai10:copy:v1.7.1:otiai10_copy/vendor/github.com/otiai10/copy \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:v1.2.0-beta.2:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robfig:config:0f78529c8c7e:robfig_config/vendor/github.com/robfig/config \
		shirou:gopsutil:v3.21.2:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:v1.3.1:shopspring_decimal/vendor/github.com/shopspring/decimal \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spacemonkeygo:spacelog:2296661a0572:spacemonkeygo_spacelog/vendor/github.com/spacemonkeygo/spacelog \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify \
		tarantool:cartridge-cli:53e6a5be9a61:tarantool_cartridge_cli \
		tarantool:cartridge-cli::tarantool_cartridge_cli_1/github.com/tarantool/cartridge-cli \
		tarantool:go-openssl:720eeb389195:tarantool_go_openssl/vendor/github.com/tarantool/go-openssl \
		tarantool:go-prompt:v0.2.6-tarantool:tarantool_go_prompt/vendor/github.com/c-bata/go-prompt \
		tarantool:go-prompt:v1.0.0:tarantool_go_prompt_1/vendor/github.com/tarantool/go-prompt \
		tarantool:go-tarantool:v1.12.2:tarantool_go_tarantool/vendor/github.com/tarantool/go-tarantool \
		tarantool:tt:8676f416ba8f:tarantool_tt_integrity/github.com/tarantool/tt \
		tarantool:tt::tarantool_tt_integrity_1/github.com/tarantool/tt/cli/integrity \
		tklauser:go-sysconf:v0.3.4:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.1:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.17.0:uber_go_zap/vendor/go.uber.org/zap \
		vmihailenco:msgpack:v2.9.2:vmihailenco_msgpack/vendor/gopkg.in/vmihailenco/msgpack.v2 \
		vmihailenco:msgpack:v5.3.5:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		yuin:gopher-lua:71163b697a8f:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

do-install:
	    ${INSTALL_PROGRAM} ${WRKSRC}/tt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

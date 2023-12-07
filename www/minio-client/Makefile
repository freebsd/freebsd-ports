PORTNAME=	minio-client
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
PORTREVISION=	15
CATEGORIES=	www

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Replacement for ls, cp, mkdir, diff and rsync commands for filesystems
WWW=		https://minio.io/downloads/ #minio-client

LICENSE=	APACHE20

BROKEN_i386=	fails to build

BUILD_DEPENDS=	bash:shells/bash

USES=		go:modules

OPTIONS_DEFINE=	MC

MC_DESC=	Install as mc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMC}
MC=	mc
.else
MC=	${PORTNAME}
.endif

USE_GITHUB=	yes
GHTAG=		RELEASE.2023-01-28T20-29-38Z
COMMIT_ID=	2e95a70c98fb9c2629cd89817b8759bfa109a4d0
GH_TUPLE=	minio:mc:${GHTAG}:DEFAULT \
		aymanbagabas:go-osc52:v1.2.1:aymanbagabas_go_osc52/vendor/github.com/aymanbagabas/go-osc52 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		charmbracelet:bubbles:v0.14.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.22.1:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.6.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.4.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
                etcd-io:etcd:v3.5.5:etcd_io_v3 \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.3:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-check:check:038fdea0a05b:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-json:v0.9.11:goccy_go_json/vendor/github.com/goccy/go-json \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.4.2:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:v0.3.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.4.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.3.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.3.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.5.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:63c7b68cfc55:google_go_genproto/vendor/google.golang.org/genproto \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.50.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.5:h2non_filetype/vendor/gopkg.in/h2non/filetype.v1 \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		inconshreveable:mousetrap:v1.0.1:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jedib0t:go-pretty:v6.3.8:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		juju:ratelimit:v1.0.2:juju_ratelimit/vendor/github.com/juju/ratelimit \
		klauspost:compress:v1.15.12:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.2.1:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lestrrat-go:backoff:v2.0.8:lestrrat_go_backoff_v2/vendor/github.com/lestrrat-go/backoff/v2 \
		lestrrat-go:blackmagic:v1.0.1:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:iter:v1.0.2:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v1.2.25:lestrrat_go_jwx/vendor/github.com/lestrrat-go/jwx \
		lestrrat-go:option:v1.0.0:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lufia:plan9stats:115f729f3c8c:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.2:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:cli:v1.24.2:minio_cli/vendor/github.com/minio/cli \
		minio:colorjson:v1.0.4:minio_colorjson/vendor/github.com/minio/colorjson \
		minio:filepath:v1.0.0:minio_filepath/vendor/github.com/minio/filepath \
		minio:madmin-go:v2.0.6:minio_madmin_go_v2/vendor/github.com/minio/madmin-go/v2 \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.46:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:pkg:v1.5.6:minio_pkg/vendor/github.com/minio/pkg \
		minio:selfupdate:v0.5.0:minio_selfupdate/vendor/github.com/minio/selfupdate \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		muesli:ansi:c9f0611b6c70:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.13.0:muesli_termenv/vendor/github.com/muesli/termenv \
		navidys:tvxwidgets:v0.1.1:navidys_tvxwidgets/vendor/github.com/navidys/tvxwidgets \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		philhofer:fwd:5c56ac6d0bb9:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:xattr:v0.4.9:pkg_xattr/vendor/github.com/pkg/xattr \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		power-devops:perfstat:c35f1ee13d7c:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		prometheus:client_golang:v1.13.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.37.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prom2json:v1.3.2:prometheus_prom2json/vendor/github.com/prometheus/prom2json \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:tview:2a6de950f73b:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.4.2:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:xid:v1.4.0:rs_xid/vendor/github.com/rs/xid \
		secure-io:sio-go:v0.3.1:secure_io_sio_go/vendor/github.com/secure-io/sio-go \
		shirou:gopsutil:v3.22.9:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		tidwall:gjson:v1.14.3:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tinylib:msgp:e818a1881b0e:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.11:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.6.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.10.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.23.0:uber_go_zap/vendor/go.uber.org/zap \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

PLIST_FILES=	bin/${MC}
GO_BUILDFLAGS=	-ldflags=" \
		-X github.com/minio/mc/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
		-X github.com/minio/mc/cmd.ReleaseTag=${GH_TAGNAME} \
		-X github.com/minio/mc/cmd.CommitID=${COMMIT_ID} \
		-X github.com/minio/mc/cmd.GOPATH=${WRKSRC} -s -w"
GO_TARGET=	:${MC}
	
post-extract:
	${RM} ${WRKSRC}/cmd/client-fs_freebsd_netbsd.go
	${RM} ${WRKSRC}/pkg/disk/stat_freebsd_netbsd.go
	${MKDIR} ${WRKSRC}/vendor/maze.io/x/duration
	${CP} ${FILESDIR}/duration.go ${WRKSRC}/vendor/maze.io/x/duration/duration.go
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io/etcd/
	@${RLN} ${WRKSRC_etcd_io_v3}/client ${WRKSRC}/vendor/go.etcd.io/etcd/client
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io/etcd/api
	@${RLN} ${WRKSRC_etcd_io_v3}/api ${WRKSRC}/vendor/go.etcd.io/etcd/api/v3
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io/etcd/client/pkg/
	@${RLN} ${WRKSRC_etcd_io_v3}/client/pkg ${WRKSRC}/vendor/go.etcd.io/etcd/client/pkg/v3

.include <bsd.port.mk>

PORTNAME=	minio-client
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Replacement for ls, cp, mkdir, diff and rsync commands for filesystems

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
GHTAG=		RELEASE.2021-12-10T00-14-28Z
COMMIT_ID=	9bdd7660f6039fc540db911d3fcc66c3e99e5a7c
GH_TUPLE=	minio:mc:${GHTAG}:DEFAULT \
		StackExchange:wmi:v1.2.1:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		briandowns:spinner:v1.16.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:etcd:v3.5.0:etcd_io_v3 \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-check:check:038fdea0a05b:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.63.2:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-json:v0.7.9:goccy_go_json/vendor/github.com/goccy/go-json \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:4f30a5c0130f:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:69063c4bb744:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:go-genproto:c7af6a1a74c9:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.41.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.5:h2non_filetype/vendor/gopkg.in/h2non/filetype.v1 \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lestrrat-go:backoff:v2.0.8:lestrrat_go_backoff_v2/vendor/github.com/lestrrat-go/backoff/v2 \
		lestrrat-go:blackmagic:v1.0.0:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.0:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:iter:v1.0.1:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v1.2.7:lestrrat_go_jwx/vendor/github.com/lestrrat-go/jwx \
		lestrrat-go:option:v1.0.0:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		mattn:go-colorable:v0.1.10:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:argon2:v1.0.0:minio_argon2/vendor/github.com/minio/argon2 \
		minio:cli:v1.22.0:minio_cli/vendor/github.com/minio/cli \
		minio:colorjson:v1.0.1:minio_colorjson/vendor/github.com/minio/colorjson \
		minio:filepath:v1.0.0:minio_filepath/vendor/github.com/minio/filepath \
		minio:madmin-go:v1.1.15:minio_madmin_go/vendor/github.com/minio/madmin-go \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:a7a36ee131df:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:pkg:v1.1.3:minio_pkg/vendor/github.com/minio/pkg \
		minio:selfupdate:v0.3.1:minio_selfupdate/vendor/github.com/minio/selfupdate \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.6.0:pkg_profile/vendor/github.com/pkg/profile \
		pkg:xattr:v0.4.3:pkg_xattr/vendor/github.com/pkg/xattr \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.31.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:xid:v1.3.0:rs_xid/vendor/github.com/rs/xid \
		secure-io:sio-go:v0.3.1:secure_io_sio_go/vendor/github.com/secure-io/sio-go \
		shirou:gopsutil:v3.21.8:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		tidwall:gjson:v1.10.2:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tinylib:msgp:v1.1.6:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.9:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.3.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.19.1:uber_go_zap/vendor/go.uber.org/zap

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

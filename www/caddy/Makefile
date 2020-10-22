# Created by: fabian.freyer@physik.tu-berlin.de
# $FreeBSD$

PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
CATEGORIES=	www

MAINTAINER=	daniel.tihanyi@tetragir.com
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}
CADDY_CONFIG=	Caddyfile
CADDY_SAMPLE=	${CADDY_CONFIG}.sample

SUB_FILES=	${PORTNAME} ${CADDY_SAMPLE} pkg-message
SUB_LIST=	CADDY_CONFIG=${CADDY_CONFIG} \
		CADDY_SAMPLE=${CADDY_SAMPLE}

GO_TARGET=	./cmd/caddy
CGO_ENABLED=	0

USE_GITHUB=	yes
GH_ACCOUNT=	caddyserver

GH_TUPLE=	\
		AndreasBriese:bbloom:e2d15f34fcf9:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		DataDog:zstd:v1.4.1:datadog_zstd/vendor/github.com/DataDog/zstd \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.1.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		alecthomas:chroma:v0.8.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		antlr:antlr4:621b933c7a7f:antlr_antlr4/vendor/github.com/antlr/antlr4 \
		aryann:difflib:e206f873d14a:aryann_difflib/vendor/github.com/aryann/difflib \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		caddyserver:certmagic:v0.12.0:caddyserver_certmagic/vendor/github.com/caddyserver/certmagic \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dgraph-io:badger:09dd2e1a4195:dgraph_io_badger_v2/vendor/github.com/dgraph-io/badger/v2 \
		dgraph-io:badger:v1.5.3:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgraph-io:ristretto:8f368f2f2ab3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-farm:6a90982ecee2:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:afde56e7acac:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-chi:chi:v4.1.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:123391ffb6de:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:f1bc736245b1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:cel-go:v0.5.1:google_cel_go/vendor/github.com/google/cel-go \
		google:go-genproto:86f49bd18e98:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		jsternberg:zap-logfmt:v1.2.0:jsternberg_zap_logfmt/vendor/github.com/jsternberg/zap-logfmt \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		klauspost:compress:v1.11.0:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.5:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		libdns:libdns:v0.1.0:libdns_libdns/vendor/github.com/libdns/libdns \
		lucas-clemente:quic-go:v0.18.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.3.1:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		marten-seemann:qpack:v0.2.0:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls-go1-15:v0.1.0:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls:v0.10.0:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mholt:acmez:v0.1.1:mholt_acmez/vendor/github.com/mholt/acmez \
		miekg:dns:v1.1.30:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		naoina:toml:v0.1.1:naoina_toml/vendor/github.com/naoina/toml \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.10.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.1.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		samfoo:ansi:b6bd2ded7189:samfoo_ansi/vendor/github.com/samfoo/ansi \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smallstep:certificates:v0.15.4:smallstep_certificates/vendor/github.com/smallstep/certificates \
		smallstep:cli:v0.15.2:smallstep_cli/vendor/github.com/smallstep/cli \
		smallstep:crypto:v0.6.0:smallstep_crypto/vendor/go.step.sm/crypto \
		smallstep:nosql:v0.3.0:smallstep_nosql/vendor/github.com/smallstep/nosql \
		smallstep:truststore:v0.9.6:smallstep_truststore/vendor/github.com/smallstep/truststore \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.15.0:uber_go_zap/vendor/go.uber.org/zap \
		urfave:cli:v1.22.2:urfave_cli/vendor/github.com/urfave/cli \
		yuin:goldmark-highlighting:60d527fdb691:yuin_goldmark_highlighting/vendor/github.com/yuin/goldmark-highlighting \
		yuin:goldmark:v1.2.1:yuin_goldmark/vendor/github.com/yuin/goldmark

GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

PLIST_FILES=	${LOCALBASE}/bin/${PORTNAME} \
		"@sample ${ETCDIR}/${CADDY_SAMPLE}"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${CADDY_SAMPLE} \
		${STAGEDIR}${ETCDIR}/${CADDY_SAMPLE}

.include <bsd.port.mk>

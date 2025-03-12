PORTNAME=       renterd
DISTVERSIONPREFIX=	v
DISTVERSION=    2.0.1
CATEGORIES=     net-p2p

MAINTAINER=     bruno@tinkerbox.org
COMMENT=        Rent storage space on the Sia network
WWW=            https://sia.tech/renterd

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           go:1.23,modules

USE_RC_SUBR=	renterd

USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GO_TARGET=      ./cmd/renterd
GO_BUILDFLAGS+= -tags='netgo'

GH_TUPLE=       \
                FiloSottile:edwards25519:v1.1.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
                SiaFoundation:core:v0.10.3:siafoundation_core/vendor/go.sia.tech/core \
                SiaFoundation:coreutils:362f2554d5ca:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
                SiaFoundation:gofakes3:v0.0.5:siafoundation_gofakes3/vendor/go.sia.tech/gofakes3 \
                SiaFoundation:hostd:c17f8d0bcfae:siafoundation_hostd/vendor/go.sia.tech/hostd \
                SiaFoundation:jape:v0.12.1:siafoundation_jape/vendor/go.sia.tech/jape \
                SiaFoundation:mux:v1.4.0:siafoundation_mux/vendor/go.sia.tech/mux \
                SiaFoundation:web:5611d44a533e:siafoundation_web/vendor/go.sia.tech/web \
                SiaFoundation:web:renterd/v0.77.0:siafoundation_web_1/vendor/go.sia.tech/web/renterd \
                aws:aws-sdk-go:v1.55.6:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
                cloudflare:cloudflare-go:v0.115.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
                etcd-io:bbolt:v1.4.0:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
                gabriel-vasile:mimetype:v1.4.8:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
                go-sql-driver:mysql:v1.9.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
                go-task:slim-sprig:52ccab3ef572:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
                go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
                goccy:go-json:v0.10.5:goccy_go_json/vendor/github.com/goccy/go-json \
                golang:crypto:v0.35.0:golang_crypto/vendor/golang.org/x/crypto \
                golang:exp:9bf2ced13842:golang_exp/vendor/golang.org/x/exp \
                golang:mod:v0.22.0:golang_mod/vendor/golang.org/x/mod \
                golang:net:v0.34.0:golang_net/vendor/golang.org/x/net \
                golang:sync:v0.11.0:golang_sync/vendor/golang.org/x/sync \
                golang:sys:v0.30.0:golang_sys/vendor/golang.org/x/sys \
                golang:term:v0.29.0:golang_term/vendor/golang.org/x/term \
                golang:text:v0.22.0:golang_text/vendor/golang.org/x/text \
                golang:time:v0.10.0:golang_time/vendor/golang.org/x/time \
                golang:tools:v0.28.0:golang_tools/vendor/golang.org/x/tools \
                google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
                google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
                google:pprof:407c9e7a662f:google_pprof/vendor/github.com/google/pprof \
                gotd:contrib:v0.21.0:gotd_contrib/vendor/github.com/gotd/contrib \
                hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
                jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
                julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
                klauspost:cpuid:v2.2.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
                klauspost:reedsolomon:v1.12.4:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
                lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
                mattn:go-sqlite3:v1.14.24:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
                montanaflynn:stats:v0.7.1:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
                onsi:ginkgo:v2.12.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
                quic-go:qpack:v0.5.1:quic_go_qpack/vendor/github.com/quic-go/qpack \
                quic-go:quic-go:v0.50.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
                quic-go:webtransport-go:4ac2c9250e66:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
                ryszard:goskiplist:2dfbae5fcf46:ryszard_goskiplist/vendor/github.com/ryszard/goskiplist \
                shabbyrobe:gocovmerge:c3350d9342df:shabbyrobe_gocovmerge/vendor/github.com/shabbyrobe/gocovmerge \
                shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
                uber-go:mock:v0.5.0:uber_go_mock/vendor/go.uber.org/mock \
                uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
                uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap

PLIST_FILES=	bin/renterd \
		"@sample ${PREFIX}/etc/renterd.yml.sample" \
		"@sample ${PREFIX}/etc/newsyslog.conf.d/renterd.conf.sample" \
		"@dir(${USERS},${GROUPS},750) /var/lib/${PORTNAME}"

SUB_FILES=	${PORTNAME}.yml ${PORTNAME}.conf

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/lib/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s|BUILDTIME|$$(date +%s)|g" ${WRKSRC}/build/meta.go

.include <bsd.port.mk>

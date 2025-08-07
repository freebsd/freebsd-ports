PORTNAME=	renterd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Rent storage space on the Sia network
WWW=		https://sia.tech/renterd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

USES=		go:1.24,modules

USE_RC_SUBR=	renterd

USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GO_TARGET=	./cmd/renterd
GO_BUILDFLAGS+= -tags='netgo'

GH_TUPLE=       \
                FiloSottile:edwards25519:v1.1.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
                SiaFoundation:core:v0.14.1:siafoundation_core/vendor/go.sia.tech/core \
                SiaFoundation:coreutils:v0.16.5:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
                SiaFoundation:gofakes3:v0.0.5:siafoundation_gofakes3/vendor/go.sia.tech/gofakes3 \
                SiaFoundation:jape:v0.14.0:siafoundation_jape/vendor/go.sia.tech/jape \
                SiaFoundation:mux:v1.4.0:siafoundation_mux/vendor/go.sia.tech/mux \
                SiaFoundation:web:renterd/v0.82.1:siafoundation_web/vendor/go.sia.tech/web \
                aws:aws-sdk-go:v1.55.7:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
                etcd-io:bbolt:v1.4.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
                gabriel-vasile:mimetype:v1.4.9:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
                go-sql-driver:mysql:v1.9.3:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
                go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
                go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
                golang:crypto:v0.39.0:golang_crypto/vendor/golang.org/x/crypto \
                golang:mod:v0.25.0:golang_mod/vendor/golang.org/x/mod \
                golang:net:v0.41.0:golang_net/vendor/golang.org/x/net \
                golang:sync:v0.15.0:golang_sync/vendor/golang.org/x/sync \
                golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
                golang:term:v0.32.0:golang_term/vendor/golang.org/x/term \
                golang:text:v0.26.0:golang_text/vendor/golang.org/x/text \
                golang:time:v0.12.0:golang_time/vendor/golang.org/x/time \
                golang:tools:v0.34.0:golang_tools/vendor/golang.org/x/tools \
                google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
                gotd:contrib:v0.21.0:gotd_contrib/vendor/github.com/gotd/contrib \
                jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
                julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
                klauspost:cpuid:v2.2.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
                klauspost:reedsolomon:v1.12.4:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
                lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
                mattn:go-sqlite3:v1.14.28:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
                montanaflynn:stats:v0.7.1:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
                quic-go:qpack:v0.5.1:quic_go_qpack/vendor/github.com/quic-go/qpack \
                quic-go:quic-go:v0.53.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
                quic-go:webtransport-go:v0.9.0:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
                ryszard:goskiplist:2dfbae5fcf46:ryszard_goskiplist/vendor/github.com/ryszard/goskiplist \
                shabbyrobe:gocovmerge:c3350d9342df:shabbyrobe_gocovmerge/vendor/github.com/shabbyrobe/gocovmerge \
                shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
                uber-go:mock:v0.5.2:uber_go_mock/vendor/go.uber.org/mock \
                uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
                uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@sample etc/newsyslog.conf.d/renterd.conf.sample" \
		"@sample etc/renterd.yml.sample" \
		bin/renterd

SUB_FILES=	${PORTNAME}.conf ${PORTNAME}.yml

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/db/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e "s|%%BUILDTIME%%|$$(date +%s)|g" ${WRKSRC}/build/meta.go

.include <bsd.port.mk>

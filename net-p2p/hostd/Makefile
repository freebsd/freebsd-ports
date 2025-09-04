PORTNAME=	hostd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.6
PORTREVISION=	2
CATEGORIES=	net-p2p

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Offer your storage space on the Sia network
WWW=		https://sia.tech/host

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

USES=		go:1.24,modules

USE_RC_SUBR=	hostd

USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GO_TARGET=	./cmd/hostd
GO_BUILDFLAGS+= -tags='netgo timetzdata'

GH_TUPLE=       \
                SiaFoundation:core:v0.14.1:siafoundation_core/vendor/go.sia.tech/core \
                SiaFoundation:coreutils:6ece69f09f12:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
                SiaFoundation:jape:v0.14.0:siafoundation_jape/vendor/go.sia.tech/jape \
                SiaFoundation:mux:v1.4.0:siafoundation_mux/vendor/go.sia.tech/mux \
                SiaFoundation:web:hostd/v0.64.0:siafoundation_web/vendor/go.sia.tech/web \
                aws:aws-sdk-go:v1.55.7:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
                cloudflare:cloudflare-go:v0.115.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
                etcd-io:bbolt:v1.4.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
                go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
                go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
                goccy:go-json:v0.10.5:goccy_go_json/vendor/github.com/goccy/go-json \
                golang:crypto:v0.39.0:golang_crypto/vendor/golang.org/x/crypto \
                golang:mod:v0.25.0:golang_mod/vendor/golang.org/x/mod \
                golang:net:v0.41.0:golang_net/vendor/golang.org/x/net \
                golang:sync:v0.15.0:golang_sync/vendor/golang.org/x/sync \
                golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
                golang:term:v0.32.0:golang_term/vendor/golang.org/x/term \
                golang:text:v0.26.0:golang_text/vendor/golang.org/x/text \
                golang:time:v0.12.0:golang_time/vendor/golang.org/x/time \
                golang:tools:v0.34.0:golang_tools/vendor/golang.org/x/tools \
                google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
                google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
                hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
                jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
                julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
                lukechampine:flagg:v1.1.1:lukechampine_flagg/vendor/lukechampine.com/flagg \
                lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
                lukechampine:upnp:v0.3.0:lukechampine_upnp/vendor/lukechampine.com/upnp \
                mattn:go-sqlite3:v1.14.28:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
                quic-go:qpack:v0.5.1:quic_go_qpack/vendor/github.com/quic-go/qpack \
                quic-go:quic-go:v0.53.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
                quic-go:webtransport-go:v0.9.0:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
                rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
                shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
                uber-go:goleak:v1.3.0:uber_go_goleak/vendor/go.uber.org/goleak \
                uber-go:mock:v0.5.2:uber_go_mock/vendor/go.uber.org/mock \
                uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
                uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@sample etc/hostd.yml.sample" \
		"@sample etc/newsyslog.conf.d/hostd.conf.sample" \
		bin/hostd

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

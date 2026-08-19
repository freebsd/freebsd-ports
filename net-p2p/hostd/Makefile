PORTNAME=	hostd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	net-p2p

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Offer your storage space on the Sia network
WWW=		https://sia.tech/host

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

USES=		go:1.26+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GH_TUPLE=	SiaFoundation:core:v0.21.0:siafoundation_core/vendor/go.sia.tech/core \
		SiaFoundation:coreutils:v0.22.0:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
		SiaFoundation:jape:v0.14.1:siafoundation_jape/vendor/go.sia.tech/jape \
		SiaFoundation:mux:v1.5.0:siafoundation_mux/vendor/go.sia.tech/mux \
		SiaFoundation:web:hostd/v0.68.2:siafoundation_web/vendor/go.sia.tech/web \
		aws:aws-sdk-go:v1.55.8:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		cloudflare:cloudflare-go:v0.117.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		dunglas:httpsfv:v1.1.0:dunglas_httpsfv/vendor/github.com/dunglas/httpsfv \
		etcd-io:bbolt:v1.4.3:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.10.5:goccy_go_json/vendor/github.com/goccy/go-json \
		golang:crypto:v0.51.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.54.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.45.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.43.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.37.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.45.0:golang_tools/vendor/golang.org/x/tools \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		lukechampine:flagg:v1.1.1:lukechampine_flagg/vendor/lukechampine.com/flagg \
		lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
		lukechampine:upnp:v0.3.0:lukechampine_upnp/vendor/lukechampine.com/upnp \
		mattn:go-sqlite3:v1.14.44:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		quic-go:qpack:v0.6.0:quic_go_qpack/vendor/github.com/quic-go/qpack \
		quic-go:quic-go:v0.59.1:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		quic-go:webtransport-go:05fe5253a73c:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.28.0:uber_go_zap/vendor/go.uber.org/zap

USE_RC_SUBR=	hostd

GO_TARGET=	./cmd/hostd
GO_BUILDFLAGS+=	-tags='netgo timetzdata'

SUB_FILES=	${PORTNAME}.conf ${PORTNAME}.yml

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@sample etc/hostd.yml.sample" \
		"@sample etc/newsyslog.conf.d/hostd.conf.sample" \
		bin/hostd

pre-configure:
	${REINPLACE_CMD} -e "s|%%BUILDTIME%%|$$(date +%s)|g" ${WRKSRC}/build/meta.go

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>

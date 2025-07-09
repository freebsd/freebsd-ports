PORTNAME=	walletd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.3
PORTREVISION=	1

CATEGORIES=	net-p2p

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Official Sia Wallet
WWW=		https://sia.tech/software/walletd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

USES=		go:1.24,modules
USE_RC_SUBR=	walletd

USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GO_TARGET=	./cmd/walletd
GO_BUILDFLAGS+= -tags='netgo timetzdata'

GH_TUPLE=	\
		SiaFoundation:core:v0.14.0:siafoundation_core/vendor/go.sia.tech/core \
		SiaFoundation:coreutils:v0.16.3:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
		SiaFoundation:jape:v0.14.0:siafoundation_jape/vendor/go.sia.tech/jape \
		SiaFoundation:mux:v1.4.0:siafoundation_mux/vendor/go.sia.tech/mux \
		SiaFoundation:web:walletd/v0.30.0:siafoundation_web/vendor/go.sia.tech/web \
		etcd-io:bbolt:v1.4.1:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-task:slim-sprig:52ccab3ef572:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.39.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9bf2ced13842:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.25.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.41.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.15.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.33.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.32.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.26.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.34.0:golang_tools/vendor/golang.org/x/tools \
		google:pprof:407c9e7a662f:google_pprof/vendor/github.com/google/pprof \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		lukechampine:flagg:v1.1.1:lukechampine_flagg/vendor/lukechampine.com/flagg \
		lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
		lukechampine:upnp:v0.3.0:lukechampine_upnp/vendor/lukechampine.com/upnp \
		mattn:go-sqlite3:v1.14.28:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		onsi:ginkgo:v2.12.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		quic-go:qpack:v0.5.1:quic_go_qpack/vendor/github.com/quic-go/qpack \
		quic-go:quic-go:v0.52.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		quic-go:webtransport-go:4ac2c9250e66:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
		uber-go:mock:v0.5.0:uber_go_mock/vendor/go.uber.org/mock \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@sample(${USERS},${GROUPS},600) etc/walletd.yml.sample" \
		"@sample etc/newsyslog.conf.d/walletd.conf.sample" \
		bin/walletd

SUB_FILES=	${PORTNAME}-syslog.conf ${PORTNAME}.conf ${PORTNAME}.yml pkg-message

SUB_LIST=	GROUPS=${GROUPS} \
		PREFIX=${PREFIX} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-syslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/db/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e "s|%%BUILDTIME%%|$$(date +%s)|g" ${WRKSRC}/build/meta.go

.include <bsd.port.mk>

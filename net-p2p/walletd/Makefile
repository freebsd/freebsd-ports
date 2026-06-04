PORTNAME=	walletd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	net-p2p

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Official Sia Wallet
WWW=		https://sia.tech/software/walletd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	SiaFoundation
GH_TUPLE=	SiaFoundation:core:v0.19.0:siafoundation_core/vendor/go.sia.tech/core \
		SiaFoundation:coreutils:v0.21.0:siafoundation_coreutils/vendor/go.sia.tech/coreutils \
		SiaFoundation:jape:v0.14.1:siafoundation_jape/vendor/go.sia.tech/jape \
		SiaFoundation:mux:v1.4.0:siafoundation_mux/vendor/go.sia.tech/mux \
		SiaFoundation:web:walletd/v0.35.0:siafoundation_web/vendor/go.sia.tech/web \
		dunglas:httpsfv:v1.1.0:dunglas_httpsfv/vendor/github.com/dunglas/httpsfv \
		etcd-io:bbolt:v1.4.3:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.47.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9bf2ced13842:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.48.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.41.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.40.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.33.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.40.0:golang_tools/vendor/golang.org/x/tools \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		lukechampine:flagg:v1.1.1:lukechampine_flagg/vendor/lukechampine.com/flagg \
		lukechampine:frand:v1.5.1:lukechampine_frand/vendor/lukechampine.com/frand \
		lukechampine:upnp:v0.3.0:lukechampine_upnp/vendor/lukechampine.com/upnp \
		mattn:go-sqlite3:v1.14.33:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		quic-go:qpack:v0.6.0:quic_go_qpack/vendor/github.com/quic-go/qpack \
		quic-go:quic-go:v0.59.0:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		quic-go:webtransport-go:v0.10.0:quic_go_webtransport_go/vendor/github.com/quic-go/webtransport-go \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.1:uber_go_zap/vendor/go.uber.org/zap

USE_RC_SUBR=	walletd

GO_TARGET=	./cmd/walletd
GO_BUILDFLAGS+=	-tags='netgo timetzdata'

SUB_FILES=	${PORTNAME}-syslog.conf ${PORTNAME}.conf ${PORTNAME}.yml pkg-message

SUB_LIST=	GROUPS=${GROUPS} \
		PREFIX=${PREFIX} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@dir(${USERS},${GROUPS},750) /var/db/${PORTNAME}" \
		"@sample(${USERS},${GROUPS},600) etc/walletd.yml.sample" \
		"@sample etc/newsyslog.conf.d/walletd.conf.sample" \
		bin/walletd

pre-configure:
	${REINPLACE_CMD} -e "s|%%BUILDTIME%%|$$(date +%s)|g" ${WRKSRC}/build/meta.go

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-syslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>

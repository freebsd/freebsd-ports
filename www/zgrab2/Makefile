PORTNAME=	zgrab2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.8
PORTREVISION=	7
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Go application scanner
WWW=		https://github.com/zmap/zgrab2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: ztypes_freebsd_arm64.go:400:12: undefined: uint128

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	zmap
GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:v0.23.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.25.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.20.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.15.0:golang_text/vendor/golang.org/x/text \
		hdm:jarm-go:v0.0.7:hdm_jarm_go/vendor/github.com/hdm/jarm-go \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		prometheus:client_golang:v1.14.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.42.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.9.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		weppos:publicsuffix-go:v0.30.0:weppos_publicsuffix_go/vendor/github.com/weppos/publicsuffix-go \
		zmap:rc2:abaa70531248:zmap_rc2/vendor/github.com/zmap/rc2 \
		zmap:zcrypto:c8b263fd8300:zmap_zcrypto/vendor/github.com/zmap/zcrypto \
		zmap:zflags:9d95409821b6:zmap_zflags/vendor/github.com/zmap/zflags
#GO_MODULE=	github.com/zmap/zgrab2 # fails to build: "unsafe.Slice requires go1.17 or later"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	snmp_exporter
PORTVERSION=	0.20.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	SNMP Exporter for Prometheus

LICENSE=	APACHE20

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	snmp_exporter

GH_ACCOUNT=	prometheus
GH_TUPLE=	\
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:5f87f3452ae9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:4c5254603344:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f9fddec55a1e:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gosnmp:gosnmp:v1.29.0:gosnmp_gosnmp/vendor/github.com/gosnmp/gosnmp \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.5.1:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_TARGET=	. \
		./generator:snmp_exporter_generator

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${GO_WRKSRC}/generator/main.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp_exporter/
	${INSTALL_DATA} ${FILESDIR}/generator.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/generator.yml

.include <bsd.port.mk>

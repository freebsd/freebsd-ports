PORTNAME=	nut_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	sysutils

MAINTAINER=	bsd@j-star.org
COMMENT=	Prometheus exporter for the Network UPS Tools server
WWW=		https://github.com/DRuggeri/nut_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	DRuggeri
GH_TUPLE=	alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-kit:log:v0.2.0:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ebe580a85c40:golang_sys/vendor/golang.org/x/sys \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0-rc.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robbiet480:go.nut:bd8f121e1fa1:robbiet480_go_nut/vendor/github.com/robbiet480/go.nut

USE_RC_SUBR=	nut_exporter
PLIST_FILES=	bin/nut_exporter

.include <bsd.port.mk>

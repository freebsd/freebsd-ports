PORTNAME=		varnish_exporter
PORTVERSION=		1.6
PORTREVISION=	28
CATEGORIES=		www

MAINTAINER=		ports@zx23.net
COMMENT=		Prometheus metrics exporter for the Varnish WWW cache
WWW=		https://github.com/jonnenauha/prometheus_varnish_exporter

LICENSE=		APACHE20

USES=			go:modules

USE_GITHUB=		yes
GH_ACCOUNT=		jonnenauha
GH_PROJECT=		prometheus_varnish_exporter
GH_TUPLE=		\
			beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
			golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
			golang:sys:5ac8a444bdc5:golang_sys/vendor/golang.org/x/sys \
			matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
			prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
			prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs

USE_RC_SUBR=		${PORTNAME}

GO_TARGET=		:varnish_exporter

USERS=			varnish
GROUPS=			varnish

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.mk>

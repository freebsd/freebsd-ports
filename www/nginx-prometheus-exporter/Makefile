# Created by: Jev Björsell <ports@ecadlabs.com>

PORTNAME=	nginx-prometheus-exporter
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for NGINX and NGINX Plus stats

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	nginxinc
GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ebe580a85c40:golang_sys/vendor/golang.org/x/sys \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		nginxinc:nginx-plus-go-client:v0.9.0:nginxinc_nginx_plus_go_client/vendor/github.com/nginxinc/nginx-plus-go-client \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

USE_RC_SUBR=	${PORTNAME}

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s ${LD_FLAG_X_PREFIX}.version=${PORTVERSION}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

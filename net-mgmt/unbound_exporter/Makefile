PORTNAME=		unbound_exporter
PORTVERSION=		0.4.6
DISTVERSIONPREFIX=	v
PORTREVISION=	12
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver
WWW=			https://github.com/letsencrypt/unbound_exporter

LICENSE=		APACHE20

USES=			go:modules
USE_GITHUB=		yes
GH_ACCOUNT=		letsencrypt

GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.6.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		golang:sys:v0.14.0:golang_sys/vendor/golang.org/x/sys \
		matttproud:golang_protobuf_extensions:v2.0.0:matttproud_golang_protobuf_extensions_v2/vendor/github.com/matttproud/golang_protobuf_extensions/v2 \
		prometheus:client_golang:v1.17.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.5.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.45.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.12.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

USE_RC_SUBR=		unbound_exporter
GO_MODULES=		github.com/letsencrypt/unbound_exporter

SUB_FILES=		pkg-message
SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

.include <bsd.port.mk>

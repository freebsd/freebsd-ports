# $FreeBSD$

PORTNAME=		varnish_exporter
PORTVERSION=		1.4.1
CATEGORIES=		www

MAINTAINER=		ports@zx23.net
COMMENT=		Prometheus metrics exporter for the Varnish WWW cache

LICENSE=		APACHE20

USES=			go
USE_GITHUB=		yes

GH_ACCOUNT=		jonnenauha
GH_PROJECT=		prometheus_varnish_exporter
GH_TUPLE=		prometheus:client_golang:v0.8.0:client_golang/vendor/github.com/prometheus/client_golang \
			beorn7:perks:3a771d9:perks/vendor/github.com/beorn7/perks \
			golang:protobuf:70b3af3:protobuf/vendor/github.com/golang/protobuf \
			matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			prometheus:client_model:5c3871d:client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:7600349:common/vendor/github.com/prometheus/common \
			prometheus:procfs:ae68e2d:procfs/vendor/github.com/prometheus/procfs

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=		:varnish_exporter

USE_RC_SUBR=		${PORTNAME}

USERS=			varnish
GROUPS=			varnish

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.mk>

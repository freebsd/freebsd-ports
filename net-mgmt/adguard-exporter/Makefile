PORTNAME=		adguard-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=		1.14
PORTREVISION=	29
CATEGORIES=		net-mgmt

MAINTAINER=		christer.edwards@gmail.com
COMMENT=		Prometheus metrics exporter for AdGuard Home DNS
WWW=		https://github.com/ebrianne/adguard-exporter

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			go
USE_GITHUB=		yes

GH_ACCOUNT=		ebrianne
GH_TUPLE=		beorn7:perks:4c0e845:perks/vendor/github.com/beorn7/perks \
			cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
			golang:net:4c5254603344:net/vendor/golang.org/x/net \
			golang:protobuf:2bba060:protobuf/vendor/github.com/golang/protobuf \
			heetch:confita:v0.9.2:confita/vendor/github.com/heetch/confita \
			matttproud:golang_protobuf_extensions:c12348c:extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			mitchellh:mapstructure:v1.1.2:mapstructure/vendor/github.com/mitchellh/mapstructure \
			pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
			prometheus:client_golang:3fb53d:client_golang/vendor/github.com/prometheus/client_golang \
			prometheus:client_model:6f38060:client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:49fee29:common/vendor/github.com/prometheus/common \
			prometheus:procfs:a1dba9c:procfs/vendor/github.com/prometheus/procfs

USE_RC_SUBR=		adguard_exporter

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=			nobody
GROUPS=			nobody

PLIST_FILES=		bin/adguard-exporter

.include <bsd.port.mk>

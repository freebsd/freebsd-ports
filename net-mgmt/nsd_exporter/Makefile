PORTNAME=	nsd_exporter
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	net-mgmt

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Prometheus exporter for nsd metrics
WWW=		https://github.com/optix2000/nsd_exporter

LICENSE=	BSD3CLAUSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	optix2000
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:e047566fdf82:golang_sys/vendor/golang.org/x/sys \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		optix2000:go-nsdctl:v1.0.0:optix2000_go_nsdctl/vendor/github.com/optix2000/go-nsdctl \
		prometheus:client_golang:v1.4.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/nsd_exporter

USE_RC_SUBR=	nsd_exporter

post-patch:
	${REINPLACE_CMD} -e 's|"/etc|"${LOCALBASE}/etc|g' ${WRKSRC_optix2000_go_nsdctl}/nsdctl.go
	${REINPLACE_CMD} -e 's|"/etc|"${LOCALBASE}/etc|g' ${WRKSRC}/nsd_exporter.go

.include <bsd.port.mk>

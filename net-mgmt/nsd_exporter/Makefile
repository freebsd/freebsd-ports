# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nsd_exporter
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Prometheus exporter for nsd metrics

LICENSE=	BSD3CLAUSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	optix2000
GH_TUPLE=	prometheus:client_golang:v0.8.0:client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d:client_model/vendor/github.com/prometheus/client_model \
		prometheus:procfs:ae68e2d:procfs/vendor/github.com/prometheus/procfs \
		prometheus:common:7600349:common/vendor/github.com/prometheus/common \
		beorn7:perks:3a771d9:perks/vendor/github.com/beorn7/perks \
		golang:protobuf:70b3af3:protobuf/vendor/github.com/golang/protobuf \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		optix2000:go-nsdctl:ce14b32:go_nsdctl/vendor/github.com/optix2000/go-nsdctl \
		go-yaml:yaml:7f97868:go_yaml/vendor/gopkg.in/yaml.v2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/nsd_exporter

USE_RC_SUBR=	nsd_exporter

post-patch:
	${REINPLACE_CMD} -e 's|"/etc|"${LOCALBASE}/etc|g' ${WRKSRC_go_nsdctl}/nsdctl.go
	${REINPLACE_CMD} -e 's|"/etc|"${LOCALBASE}/etc|g' ${WRKSRC}/nsd_exporter.go

.include <bsd.port.mk>

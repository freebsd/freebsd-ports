# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nsd_exporter
PORTVERSION=	0.1.0
CATEGORIES=	net-mgmt

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Prometheus exporter for nsd metrics

LICENSE=	BSD3CLAUSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	optix2000
GH_TUPLE=	prometheus:client_golang:v0.8.0:client_golang \
		prometheus:client_model:5c3871d:client_model \
		prometheus:procfs:ae68e2d:procfs \
		prometheus:common:7600349:common \
		beorn7:perks:3a771d9:perks \
		golang:protobuf:70b3af3:protobuf \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions \
		optix2000:go-nsdctl:ce14b32:go_nsdctl \
		go-yaml:yaml:7f97868:go_yaml

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/nsd_exporter

USE_RC_SUBR=	nsd_exporter

post-patch:
	${REINPLACE_CMD} -e 's|"/etc|"${LOCALBASE}/etc|g' ${WRKSRC_go_nsdctl}/nsdctl.go

pre-build:
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/prometheus ${GO_WRKDIR_SRC}/gopkg.in \
		${GO_WRKDIR_SRC}/github.com/beorn7 ${GO_WRKDIR_SRC}/github.com/golang \
		${GO_WRKDIR_SRC}/github.com/matttproud ${GO_WRKDIR_SRC}/github.com/optix2000
	${MV} ${WRKSRC_golang_protobuf_extensions} ${GO_WRKDIR_SRC}/github.com/matttproud/golang_protobuf_extensions
	${MV} ${WRKSRC_go_nsdctl} ${GO_WRKDIR_SRC}/github.com/optix2000/go-nsdctl
	${MV} ${WRKSRC_client_golang} ${GO_WRKDIR_SRC}/github.com/prometheus/client_golang
	${MV} ${WRKSRC_client_model} ${GO_WRKDIR_SRC}/github.com/prometheus/client_model
	${MV} ${WRKSRC_procfs} ${GO_WRKDIR_SRC}/github.com/prometheus/procfs
	${MV} ${WRKSRC_common} ${GO_WRKDIR_SRC}/github.com/prometheus/common
	${MV} ${WRKSRC_protobuf} ${GO_WRKDIR_SRC}/github.com/golang/protobuf
	${MV} ${WRKSRC_go_yaml} ${GO_WRKDIR_SRC}/gopkg.in/yaml.v2
	${MV} ${WRKSRC_perks} ${GO_WRKDIR_SRC}/github.com/beorn7/perks

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/nsd_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

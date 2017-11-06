# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=		unbound_exporter
PORTVERSION=		0.1
PORTREVISION=		1
DISTVERSIONPREFIX=	v
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver

LICENSE=		APACHE20

USES=			go
GH_ACCOUNT=		kumina
USE_GITHUB=		yes
GH_TUPLE=		prometheus:client_golang:08fd2e1:client_golang \
			prometheus:client_model:6f38060:client_model \
			prometheus:common:49fee29:common \
			prometheus:procfs:a1dba9c:procfs \
			beorn7:perks:4c0e845:perks \
			golang:protobuf:2bba060:protobuf \
			matttproud:golang_protobuf_extensions:c12348c:extensions

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=		unbound_exporter

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

pre-build:
	echo ${WRKSRC_client_golang}
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/prometheus
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/beorn7
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/golang
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/matttproud
	${MV} ${WRKSRC_client_golang} ${GO_WRKDIR_SRC}/github.com/prometheus/client_golang
	${MV} ${WRKSRC_client_model} ${GO_WRKDIR_SRC}/github.com/prometheus/client_model
	${MV} ${WRKSRC_common} ${GO_WRKDIR_SRC}/github.com/prometheus/common
	${MV} ${WRKSRC_procfs} ${GO_WRKDIR_SRC}/github.com/prometheus/procfs
	${MV} ${WRKSRC_perks} ${GO_WRKDIR_SRC}/github.com/beorn7/perks
	${MV} ${WRKSRC_protobuf} ${GO_WRKDIR_SRC}/github.com/golang/protobuf
	${MV} ${WRKSRC_extensions} ${GO_WRKDIR_SRC}/github.com/matttproud/golang_protobuf_extensions

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/unbound_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

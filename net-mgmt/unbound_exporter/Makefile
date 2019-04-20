# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=		unbound_exporter
PORTVERSION=		0.1
DISTVERSIONPREFIX=	v
PORTREVISION=		2
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver

LICENSE=		APACHE20

USES=			go
USE_GITHUB=		yes
USE_RC_SUBR=		unbound_exporter

GH_ACCOUNT=		kumina
GH_TAGNAME=		b7e842d893d29200a5108eab717f5ab01d783c0c
GH_TUPLE=		prometheus:client_golang:3fb53d:client_golang \
			prometheus:client_model:6f38060:client_model \
			prometheus:common:49fee29:common \
			prometheus:procfs:a1dba9c:procfs \
			beorn7:perks:4c0e845:perks \
			golang:protobuf:2bba060:protobuf \
			matttproud:golang_protobuf_extensions:c12348c:extensions \
			sirupsen:logrus:91da99d:logrus \
			golang:crypto:3d3f9f41:crypto \
			golang:sys:93218def:sys

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

pre-build:
	${ECHO_CMD} ${WRKSRC_client_golang}
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/prometheus
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/beorn7
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/golang
	${MKDIR} ${GO_WRKDIR_SRC}/golang.org/x
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/matttproud
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/Sirupsen
	${MV} ${WRKSRC_client_golang} ${GO_WRKDIR_SRC}/github.com/prometheus/client_golang
	${MV} ${WRKSRC_client_model} ${GO_WRKDIR_SRC}/github.com/prometheus/client_model
	${MV} ${WRKSRC_common} ${GO_WRKDIR_SRC}/github.com/prometheus/common
	${MV} ${WRKSRC_procfs} ${GO_WRKDIR_SRC}/github.com/prometheus/procfs
	${MV} ${WRKSRC_perks} ${GO_WRKDIR_SRC}/github.com/beorn7/perks
	${MV} ${WRKSRC_protobuf} ${GO_WRKDIR_SRC}/github.com/golang/protobuf
	${MV} ${WRKSRC_extensions} ${GO_WRKDIR_SRC}/github.com/matttproud/golang_protobuf_extensions
	${MV} ${WRKSRC_logrus} ${GO_WRKDIR_SRC}/github.com/Sirupsen/logrus
	${MV} ${WRKSRC_crypto} ${GO_WRKDIR_SRC}/golang.org/x/crypto
	${MV} ${WRKSRC_sys} ${GO_WRKDIR_SRC}/golang.org/x/sys

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/unbound_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

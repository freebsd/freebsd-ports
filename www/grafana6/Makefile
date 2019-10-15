# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	6.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES+=	https://dl.grafana.com/oss/release/:public
PKGNAMESUFFIX=	${PORTVERSION:C/([0-9]).*/\1/1}
DISTFILES=	grafana-${PORTVERSION}.linux-amd64${EXTRACT_SUFX}:public
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hiyorin@gmail.com
COMMENT=	Dashboard and graph editor for multiple data stores

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		go:modules
USE_RC_SUBR=	grafana

USE_GITHUB=	yes
TAG=		9504db8

GO_TARGET=	./pkg/cmd/grafana-server \
		./pkg/cmd/grafana-cli
GO_BUILDFLAGS=	-ldflags="-w -X main.version=${PORTVERSION} -X main.commit=${TAG}"

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=		${GRAFANA_USER}
GROUPS=		${GRAFANA_GROUP}

GRAFANAHOMEDIR=		${PREFIX}/share/grafana
GRAFANADATADIR=		/var/db/${PORTNAME}/
GRAFANALOGDIR=		/var/log/${PORTNAME}/
GRAFANAPIDDIR=		/var/run/${PORTNAME}/
GRAFANAPLUGINDIR=	/var/db/${PORTNAME}/plugins
GRAFANAPROVISIONINGDIR=	/var/db/${PORTNAME}/provisioning

SUB_FILES=	grafana grafana.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANADATADIR=${GRAFANADATADIR} \
		GRAFANALOGDIR=${GRAFANALOGDIR} \
		GRAFANAPIDDIR=${GRAFANAPIDDIR} \
		GRAFANAHOMEDIR=${GRAFANAHOMEDIR} \
		GRAFANAPLUGINDIR=${GRAFANAPLUGINDIR} \
		GRAFANAPROVISIONINGDIR=${GRAFANAPROVISIONINGDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

post-extract:
	@${RM} -r ${WRKSRC}/public
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/grafana-${PORTVERSION}.linux-amd64${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS} grafana-${PORTVERSION}/public)

# unbreak vendored golang.org/x/xerrors with go1.13
# can be removed after vendor/golang.org/x/xerrors is updated to a985d3407aa7 or later
post-patch:
	@${RM} ${WRKSRC}/vendor/golang.org/x/xerrors/adaptor_go1_13.go
	@${RM} ${WRKSRC}/vendor/golang.org/x/xerrors/format_go1_13.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/adaptor_go1_12.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/format_go1_12.go
	@${REINPLACE_CMD} '/build !go1.13/d' ${WRKSRC}/vendor/golang.org/x/xerrors/frame_go1_12.go

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAPLUGINDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAPROVISIONINGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data/log
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini \
		${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana.conf ${STAGEDIR}${PREFIX}/etc/grafana.conf.sample

.include <bsd.port.mk>

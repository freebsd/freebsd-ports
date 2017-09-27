# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beats
PORTVERSION=	5.6.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect logs locally and send to remote logstash

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	elastic

USES=		gmake go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

USE_RC_SUBR=	${GO_TARGETS}

OPTIONS_DEFAULT=FILEBEAT PACKETBEAT METRICBEAT HEARTBEAT
OPTIONS_SUB=	yes

OPTIONS_MULTI=	BEATS
OPTIONS_MULTI_BEATS=${OPTIONS_DEFAULT}

FILEBEAT_DESC=	Filebeat
FILEBEAT_VARS=	GO_TARGETS+=filebeat

PACKETBEAT_DESC=Packetbeat
PACKETBEAT_VARS=GO_TARGETS+=packetbeat

METRICBEAT_DESC=Metricbeat
METRICBEAT_VARS=GO_TARGETS+=metricbeat

HEARTBEAT_DESC=	Heartbeat
HEARTBEAT_VARS=GO_TARGETS+=heartbeat

do-build:
	@for GO_TARGET in libbeat/dashboards ${GO_TARGETS}; do \
		cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} -C $${GO_TARGET} ;\
	done

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} \
		${GO_WRKSRC}/libbeat/dashboards/import_dashboards \
		${STAGEDIR}${DATADIR}
	for GO_TARGET in ${GO_TARGETS}; do \
		${INSTALL_PROGRAM} ${GO_WRKSRC}/$${GO_TARGET}/$${GO_TARGET} \
			${STAGEDIR}${PREFIX}/sbin ;\
		${INSTALL_DATA} ${WRKSRC}/$${GO_TARGET}/$${GO_TARGET}.yml \
			${STAGEDIR}${PREFIX}/etc/$${GO_TARGET}.yml.sample ;\
		${INSTALL_DATA} ${WRKSRC}/$${GO_TARGET}/$${GO_TARGET}.template.json \
			${STAGEDIR}${PREFIX}/etc/$${GO_TARGET}.template.json.sample ;\
		${INSTALL_DATA} ${WRKSRC}/$${GO_TARGET}/$${GO_TARGET}.template-es2x.json \
			${STAGEDIR}${PREFIX}/etc/$${GO_TARGET}.template-es2x.json.sample ;\
		${MKDIR} ${STAGEDIR}/var/db/beats/$${GO_TARGET} ;\
	done

.include <bsd.port.mk>

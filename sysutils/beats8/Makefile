PORTNAME=	beats
DISTVERSIONPREFIX=	v
DISTVERSION=	8.14.3
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
PKGNAMESUFFIX?=	8
DISTFILES=	go.mod:gomod

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Send logs, network, metrics and heartbeat to elasticsearch or logstash
WWW=		https://www.elastic.co/products/beats/

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	elastic

USE_RC_SUBR=	${GO_TARGET:C,\./,,g}

GO_MODULE=	github.com/elastic/beats/v8
CGO_CFLAGS=	-I.
CGO_LDFLAGS=	-L.
MAKE_ENV+=	GOBUILD_FLAGS="-mod=vendor"

CONFLICTS=	beats6 beats7

PORTSCOUT=	limit:^8

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		AUDITBEAT FILEBEAT HEARTBEAT METRICBEAT PACKETBEAT
OPTIONS_DEFAULT=	FILEBEAT HEARTBEAT METRICBEAT
OPTIONS_SUB=		yes

AUDITBEAT_DESC=			Auditbeat
FILEBEAT_DESC=			Filebeat
HEARTBEAT_DESC=			Heartbeat
METRICBEAT_DESC=		Metricbeat
PACKETBEAT_DESC=		Packetbeat
AUDITBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/auditbeat/:auditbeat
AUDITBEAT_DISTFILES=		auditbeat-${DISTVERSION}-darwin-x86_64.tar.gz:auditbeat
AUDITBEAT_VARS=			GO_TARGET+=./auditbeat
FILEBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/filebeat/:filebeat
FILEBEAT_DISTFILES=		filebeat-${DISTVERSION}-darwin-x86_64.tar.gz:filebeat
FILEBEAT_VARS=			GO_TARGET+=./filebeat
HEARTBEAT_MASTER_SITES=		https://artifacts.elastic.co/downloads/beats/heartbeat/:heartbeat
HEARTBEAT_DISTFILES=		heartbeat-${DISTVERSION}-darwin-x86_64.tar.gz:heartbeat
HEARTBEAT_VARS=			GO_TARGET+=./heartbeat
METRICBEAT_MASTER_SITES=	https://artifacts.elastic.co/downloads/beats/metricbeat/:metricbeat
METRICBEAT_DISTFILES=		metricbeat-${DISTVERSION}-darwin-x86_64.tar.gz:metricbeat
METRICBEAT_VARS=		GO_TARGET+=./metricbeat
PACKETBEAT_MASTER_SITES=	https://artifacts.elastic.co/downloads/beats/packetbeat/:packetbeat
PACKETBEAT_DISTFILES=		packetbeat-${DISTVERSION}-darwin-x86_64.tar.gz:packetbeat
PACKETBEAT_VARS=		CGO_CFLAGS+=-I/usr/include \
				CGO_LDFLAGS+=-L/usr/lib \
				GO_TARGET+=./packetbeat

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s|%%BEATSVERSION%%|v${PORTVERSION}|g" ${WRKSRC}/dev-tools/mage/settings.go
.for BEATMOD in ${GO_TARGET:C,\./,,g}
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/${BEATMOD}/*.yml
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for BEATMOD in ${GO_TARGET:C,^\./,,g}
	${MKDIR} ${STAGEDIR}/var/db/beats/${BEATMOD} && \
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${BEATMOD} \
		${STAGEDIR}${PREFIX}/sbin && \
	${INSTALL_DATA} ${WRKSRC}/${BEATMOD}/${BEATMOD}.yml \
		${STAGEDIR}${ETCDIR}/${BEATMOD}.yml.sample && \
	${INSTALL_DATA} ${WRKSRC}/${BEATMOD}/${BEATMOD}.reference.yml \
		${STAGEDIR}${ETCDIR}/${BEATMOD}.yml.reference
	(MODULE_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/module; \
	 if [ -d $${MODULE_SRC} ]; then \
	   MODULE_DEST=${STAGEDIR}${DATADIR}/${BEATMOD}/module && \
	   ${MKDIR} $${MODULE_DEST} && \
	   cd $${MODULE_SRC} && ${COPYTREE_SHARE} . $${MODULE_DEST} && \
	   cd $${MODULE_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${DATADIR_REL}/${BEATMOD}/module,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${DATADIR_REL}/${BEATMOD}/module,' >> ${TMPPLIST}; \
	 fi) && \
	(MODULESD_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/modules.d; \
	 if [ -d $${MODULESD_SRC} ]; then \
	   MODULESD_DEST=${STAGEDIR}${EXAMPLESDIR}/${BEATMOD}.modules.d && \
	   ${MKDIR} $${MODULESD_DEST} && \
	   cd $${MODULESD_SRC} && ${COPYTREE_SHARE} . $${MODULESD_DEST} && \
	   cd $${MODULESD_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${EXAMPLESDIR_REL}/${BEATMOD}.modules.d,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${EXAMPLESDIR_REL}/${BEATMOD}.modules.d,' >> ${TMPPLIST}; \
	   ${MKDIR} ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d && \
	   ${ECHO_CMD} "The modules.d files are now in ${EXAMPLESDIR}/${BEATMOD}.modules.d" > \
	     ${STAGEDIR}${ETCDIR}/${BEATMOD}.modules.d/README; \
	   ${ECHO_CMD} ${ETCDIR_REL}/${BEATMOD}.modules.d/README >> ${TMPPLIST}; \
	 fi) && \
	(MONITORSD_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/monitors.d; \
	 if [ -d $${MONITORSD_SRC} ]; then \
	   MONITORSD_DEST=${STAGEDIR}${EXAMPLESDIR}/${BEATMOD}.monitors.d && \
	   ${MKDIR} $${MONITORSD_DEST} && \
	   cd $${MONITORSD_SRC} && ${COPYTREE_SHARE} . $${MONITORSD_DEST} && \
	   cd $${MONITORSD_DEST} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${EXAMPLESDIR_REL}/${BEATMOD}.monitors.d,' >> ${TMPPLIST} && \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${EXAMPLESDIR_REL}/${BEATMOD}.monitors.d,' >> ${TMPPLIST}; \
	   ${MKDIR} ${STAGEDIR}${ETCDIR}/${BEATMOD}.monitors.d && \
	   ${ECHO_CMD} "The monitors.d files are now in ${EXAMPLESDIR}/${BEATMOD}.monitors.d" > \
	     ${STAGEDIR}${ETCDIR}/${BEATMOD}.monitors.d/README; \
	   ${ECHO_CMD} ${ETCDIR_REL}/${BEATMOD}.monitors.d/README >> ${TMPPLIST}; \
	 fi) && \
	(KIBANA_SRC=${WRKDIR}/${BEATMOD}-${DISTVERSION}-darwin-x86_64/kibana; \
	 if [ -d $${KIBANA_SRC} ]; then \
	   KIBANA_PATH=${STAGEDIR}${DATADIR}/${BEATMOD}/kibana; \
	   ${MKDIR} $${KIBANA_PATH} && \
	   cd $${KIBANA_SRC} && ${COPYTREE_SHARE} . $${KIBANA_PATH}; \
	   cd $${KIBANA_PATH} && \
	   ${FIND} . -type d -empty | ${SORT} | \
	   ${SED} -e 's,^\.,@dir ${DATADIR_REL}/${BEATMOD}/kibana,' >> ${TMPPLIST}; \
	   ${FIND} . -not -type d | ${SORT} | \
	   ${SED} -e 's,^\.,${DATADIR_REL}/${BEATMOD}/kibana,' >> ${TMPPLIST}; \
	 fi)
.endfor

.include <bsd.port.mk>

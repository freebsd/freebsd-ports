PORTNAME=	wazuh
PORTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/${PORTNAME}/:config_samples \
		https://packages.wazuh.com/4.x/filebeat/:wazuh_module \
		https://raw.githubusercontent.com/wazuh/wazuh/v${PORTVERSION}/extensions/elasticsearch/7.x/:indexer_template
PKGNAMESUFFIX=	-server
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Components for analyze the data received from the agents
WWW=		https://wazuh.com/

LICENSE=	GPLv2

USES=		dos2unix	
NO_BUILD=	yes

DOS2UNIX_FILES=	${WRKDIR}/wazuh-template.json

DISTFILES+=	filebeat.yml:config_samples \
		logstash-${PORTNAME}-${PORTVERSION}.conf:config_samples \
		wazuh-filebeat-${WAZUH_MODULE_VER}.tar.gz:wazuh_module \
		wazuh-template.json:indexer_template

SUB_FILES=	pkg-message

ETCDIR=		${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

WAZUH_LOCALBASE=	/var/ossec
WAZUH_MODULE_VER=	0.4

OPTIONS_DEFINE=		FILEBEAT LOGSTASH WAZUH-MANAGER
OPTIONS_DEFAULT=	FILEBEAT LOGSTASH WAZUH-MANAGER
OPTIONS_SUB=		yes

FILEBEAT_DESC=		Install filebeat component
LOGSTASH_DESC=		Install logstash component
WAZUH-MANAGER_DESC=	Install wazuh manager component

FILEBEAT_RUN_DEPENDS=		filebeat:sysutils/beats7
LOGSTASH_RUN_DEPENDS=		${LOCALBASE}/logstash/bin/logstash:sysutils/logstash8
WAZUH-MANAGER_RUN_DEPENDS=	${WAZUH_LOCALBASE}/bin/wazuh-control:security/wazuh-manager

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}-filebeat-${WAZUH_MODULE_VER}.tar.gz ${EXTRACT_AFTER_ARGS}
	${CP} ${_DISTDIR}/filebeat.yml ${WRKDIR}
	${CP} ${_DISTDIR}/logstash-${PORTNAME}-${PORTVERSION}.conf ${WRKDIR}/logstash.conf
	${CP} ${_DISTDIR}/wazuh-template.json ${WRKDIR}

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/filebeat.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}/filebeat.yml
	${INSTALL_DATA} ${WRKDIR}/logstash.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}/logstash.conf
	${INSTALL_DATA} ${WRKDIR}/wazuh-template.json ${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}/wazuh-template.json

do-install-FILEBEAT-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/beats/filebeat/module/
	@cd ${WRKDIR} && ${COPYTREE_SHARE} wazuh ${STAGEDIR}${PREFIX}/share/beats/filebeat/module/
	
.include <bsd.port.mk>

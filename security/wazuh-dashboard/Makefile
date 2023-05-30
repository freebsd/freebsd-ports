PORTNAME=	wazuh
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.3
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/${PORTNAME}/
PKGNAMESUFFIX=  -dashboard
DISTFILES=	${PORTNAME}-kibana-app-${DISTVERSION}-${OPENSEARCH_VERSION}${EXTRACT_SUFX} \
		opensearch_dashboards.yml
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Web user interface for data visualization and analysis
WWW=		https://github.com/wazuh/wazuh-kibana-app

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/www/opensearch-dashboards/bin/opensearch-dashboards:textproc/opensearch-dashboards

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPENSEARCH_VERSION=	2.7.0
ETCDIR=		${PREFIX}/etc/wazuh-dashboard
WRKSRC=		${WRKDIR}/${PORTNAME}-kibana-app-${DISTVERSION}

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}-kibana-app-${DISTVERSION}-${OPENSEARCH_VERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	${CP} ${_DISTDIR}/opensearch_dashboards.yml ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/opensearch-dashboards/plugins/wazuh
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/wazuh-dashboard

	@${INSTALL_DATA} ${WRKDIR}/opensearch_dashboards.yml ${STAGEDIR}${PREFIX}/etc/wazuh-dashboard
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}/${PREFIX}/www/opensearch-dashboards/plugins/wazuh)

.include <bsd.port.mk>

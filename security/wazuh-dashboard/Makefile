PORTNAME=	wazuh
DISTVERSIONPREFIX=	v
DISTVERSION=	4.12.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/${PORTNAME}/
PKGNAMESUFFIX=  -dashboard
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-plugins-${DISTVERSION}-${OPENSEARCH_VERSION}${EXTRACT_SUFX} \
		opensearch_dashboards.yml
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Web user interface for data visualization and analysis
WWW=		https://github.com/wazuh/wazuh-dashboard-plugins

LICENSE=	GPLv2

DEPRECATED=	Depends on expiring textproc/opensearch-dashboards219
EXPIRATION_DATE=2025-09-01

RUN_DEPENDS=	${LOCALBASE}/www/opensearch-dashboards/bin/opensearch-dashboards:textproc/opensearch-dashboards219

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPENSEARCH_VERSION=	2.19.1
ETCDIR=		${PREFIX}/etc/wazuh-dashboard
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-plugins

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}${PKGNAMESUFFIX}-plugins-${DISTVERSION}-${OPENSEARCH_VERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	${CP} ${_DISTDIR}/opensearch_dashboards.yml ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/opensearch-dashboards/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/wazuh-dashboard

	@${INSTALL_DATA} ${WRKDIR}/opensearch_dashboards.yml ${STAGEDIR}${PREFIX}/etc/wazuh-dashboard
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}/${PREFIX}/www/opensearch-dashboards/plugins/)

.include <bsd.port.mk>

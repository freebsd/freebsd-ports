PORTNAME=	opensearch-dashboards
DISTVERSION?=	2.11.1
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.opensearch.org/releases/bundle/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	opensearch@FreeBSD.org
COMMENT?=	Visualization dashboards for OpenSearch
WWW=		https://opensearch.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS?=	opensearch-dashboards210

BUILD_DEPENDS=	npm-node18>0:www/npm-node18

USES=		nodejs:18,build,run python:build
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-deinstall
SUB_LIST=	PORTNAME="${PORTNAME}" \
		PKGNAMESUFFIX="${PKGNAMESUFFIX}" \
		WWWDIR=${WWWDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NODE_VER=	18.18.0
NO_BUILD=	yes

_DEVDIR=	${WRKDIR}/.devdir

post-patch:
	@${REINPLACE_CMD} -e 's|14.20.1|${NODE_VER}|g' ${WRKSRC}/package.json
	${RM} \
		${WRKSRC}/bin/*.orig \
		${WRKSRC}/bin/*.bak \
		${WRKSRC}/package.json.bak
	${RM} -r ${WRKSRC}/plugins/reportsDashboards/.chromium

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/opensearch_dashboards.yml ${STAGEDIR}${ETCDIR}/opensearch_dashboards.yml.sample
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "data node_modules package.json plugins src" ${STAGEDIR}${WWWDIR} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR})

post-install:
	${ECHO} "@sample ${ETCDIR}/opensearch_dashboards.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(www,www) ${WWWDIR}/data" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/legacy" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/fixed" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/dynamic" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/examples/fixed" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/examples/dynamic" >> ${TMPPLIST}

.include <bsd.port.mk>

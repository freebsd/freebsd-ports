PORTNAME=	opensearch-dashboards
DISTVERSION=	2.8.0
DISTVERSIONSUFFIX=	-linux-x64
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.opensearch.org/releases/bundle/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	opensearch@FreeBSD.org
COMMENT=	Visualization dashboards for OpenSearch
WWW=		https://opensearch.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	npm-node16>0:www/npm-node16

USES=		nodejs:16,build,run python:build
USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	CHROME

CHROME_DESC=	Add dependency on www/chromium (required for PDF reports)
CHROME_RUN_DEPENDS=chrome:www/chromium

NODE_VER=	16.20.0

_DEVDIR=	${WRKDIR}/.devdir

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' -e 's|%%LOCALBASE%%|${LOCALBASE}|' -e 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/node_modules/re2/binding.gyp
	@${REINPLACE_CMD} -e 's|14.20.1|${NODE_VER}|g' ${WRKSRC}/package.json
	${RM} \
		${WRKSRC}/bin/*.orig \
		${WRKSRC}/bin/*.bak \
		${WRKSRC}/node_modules/re2/binding.gyp.orig \
		${WRKSRC}/node_modules/re2/binding.gyp.bak \
		${WRKSRC}/package.json.bak
	${RM} -r ${WRKSRC}/plugins/reportsDashboards/.chromium

do-configure:
	(cd ${WRKSRC}/node_modules/re2 && \
		${SETENV} HOME=${WRKDIR} PYTHONDONTWRITEBYTECODE=1 \
		${LOCALBASE}/lib/node_modules/npm/node_modules/.bin/node-gyp configure \
		--python=${PYTHON_CMD} \
		--nodedir ${LOCALBASE} \
		--devdir=${_DEVDIR})

do-build:
	(cd ${WRKSRC}/node_modules/re2 && \
		${SETENV} HOME=${WRKDIR} PYTHONDONTWRITEBYTECODE=1 \
		${LOCALBASE}/lib/node_modules/npm/node_modules/.bin/node-gyp build \
		--devdir=${_DEVDIR})
	${RM} -r ${WRKSRC}/node_modules/re2/build/Release/.deps \
		${WRKSRC}/node_modules/re2/build/Release/obj.target

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/opensearch_dashboards.yml ${STAGEDIR}${ETCDIR}/opensearch_dashboards.yml.sample
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "data node_modules package.json plugins src" ${STAGEDIR}${WWWDIR} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR})
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/node_modules/re2/build/Release/re2.node

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

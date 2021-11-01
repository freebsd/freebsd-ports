PORTNAME=	kibana
PORTVERSION=	6.8.16
PORTREVISION=	1
DISTVERSIONSUFFIX=	-darwin-x86_64
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.elastic.co/downloads/kibana/ \
		http://artifacts.elastic.co/downloads/kibana/
PKGNAMESUFFIX?=	6

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

DEPRECATED=	Uses EOL Python 2.7 via www/node10
EXPIRATION_DATE=	2021-06-23

USES=		cpe nodejs:run,10
CPE_VENDOR=	elastic
USE_RC_SUBR=	${PORTNAME}

CONFLICTS=	kibana7* kibana[3-5]*

WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}

NO_BUILD=	yes
SUB_FILES=	pkg-deinstall
SUB_LIST+=	PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		PORTNAME=${PORTNAME}

post-patch:
	${FIND} -s ${WRKSRC}/node_modules -type d -empty -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/kibana.yml ${STAGEDIR}${ETCDIR}/kibana.yml.sample
	(cd ${WRKSRC} && \
		${RM} -r config node optimize && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR})
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${WWWDIR}/config

post-install:
	${ECHO} "@sample ${ETCDIR}/kibana.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(www,www) ${WWWDIR}/data" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins" >> ${TMPPLIST}

.include <bsd.port.mk>

# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	6.8.6
DISTVERSIONSUFFIX=	-darwin-x86_64
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.elastic.co/downloads/kibana/ \
		http://artifacts.elastic.co/downloads/kibana/
PKGNAMESUFFIX?=	6

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node10>=10.15.2:www/node10

CONFLICTS=	kibana[3-5]*

NO_BUILD=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-deinstall
SUB_LIST+=	PORTNAME=${PORTNAME} PKGNAMESUFFIX=${PKGNAMESUFFIX}

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

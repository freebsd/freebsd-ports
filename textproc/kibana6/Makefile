# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	6.5.4
DISTVERSIONSUFFIX=	-linux-x86_64
PORTREVISION=	2
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.elastic.co/downloads/kibana/ \
		http://artifacts.elastic.co/downloads/kibana/
PKGNAMESUFFIX?=	6

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node8>=8.11.3:www/node8

CONFLICTS=	kibana[3-5]*

NO_BUILD=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-deinstall

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
	${ECHO} "@dir ${WWWDIR}/src/ui/public/factories" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/src/core/public/injected_metadata/__fixtures__/frozen_object_mutation" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/src/server/http/integration_tests" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/src/type_definitions" >> ${TMPPLIST}

.include <bsd.port.mk>

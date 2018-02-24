# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	5.6.8
DISTVERSIONSUFFIX=	-linux-x86
PORTREVISION=	0
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.elastic.co/downloads/kibana/ \
		http://artifacts.elastic.co/downloads/kibana/
PKGNAMESUFFIX?=	5

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node>=0.8.0:www/node

CONFLICTS=	kibana[3-4]*

NO_BUILD=	yes
NO_ARCH=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-deinstall

do-install:
	${CP} ${WRKSRC}/config/kibana.yml ${STAGEDIR}${PREFIX}/etc/kibana.yml.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && \
		${RM} -r bin config node && \
		${RM} -r optimize && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	${ECHO} "@sample etc/kibana.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(www,www) ${WWWDIR}/data" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/src/ui/public/factories" >> ${TMPPLIST}

.include <bsd.port.mk>

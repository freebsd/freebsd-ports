# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x-pack
PORTVERSION=	5.6.8
CATEGORIES=	textproc java
MASTER_SITES=	https://artifacts.elastic.co/downloads/packs/x-pack/
PKGNAMEPREFIX=	elasticsearch5-

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Elasticsearch X-Pack plugins

RUN_DEPENDS:=	elasticsearch5>=5.6.8:textproc/elasticsearch5

NO_BUILD=	yes

USES+=		zip

do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${PORTNAME}-${PORTVERSION} \
	      ${_DISTDIR}${DISTFILES} )

do-install:
	@cd ${WRKSRC}/elasticsearch && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/x-pack

post-install:
	@${FIND} -s ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/x-pack -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>

# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x-pack
PORTVERSION=	5.6.8
CATEGORIES=	textproc java
MASTER_SITES=	https://artifacts.elastic.co/downloads/packs/x-pack/
PKGNAMEPREFIX=	kibana5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Kibana 5.0 X-Pack plugins

RUN_DEPENDS:=	kibana5>=5.6.8:textproc/kibana5

NO_BUILD=	yes

USES+=		zip

do-extract:
	${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${PORTNAME}-${PORTVERSION} \
	      ${_DISTDIR}${DISTFILES} )

do-install:
	cd ${WRKSRC}/kibana && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/kibana5/plugins

post-install:
	@${FIND} -s ${STAGEDIR}${PREFIX}/www/kibana5/plugins/x-pack -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>

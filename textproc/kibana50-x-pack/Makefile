# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x-pack
PORTVERSION=	5.0.2
CATEGORIES=	textproc java
MASTER_SITES=	https://artifacts.elastic.co/downloads/packs/x-pack/
PKGNAMEPREFIX=	kibana50-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Kibana 5.0 X-Pack plugins


RUN_DEPENDS:=	kibana50>=5.0.0:textproc/kibana50

NO_BUILD=	yes

USES+=		zip

do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${PORTNAME}-${PORTVERSION} \
	      ${_DISTDIR}${DISTFILES} )

do-install:
	@cd ${WRKSRC}/kibana && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/kibana50/plugins/x-pack

.include <bsd.port.mk>

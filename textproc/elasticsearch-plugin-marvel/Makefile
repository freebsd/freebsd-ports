# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	marvel
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://download.elasticsearch.org/elasticsearch/marvel/
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	ElasticSearch Mavel Monitoring Plugin

LICENSE=	COMMERCIAL
LICENSE_NAME=	Free for development; license required for production use
LICENSE_TEXT=	License available from Elasticsearch for production use.
LICENSE_TEXT+=	See http://www.elasticsearch.com/marvel/ for more details.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell no-auto-accept

RUN_DEPENDS:=	elasticsearch>=0.90.9:${PORTSDIR}/textproc/elasticsearch

NO_BUILD=	yes
LEGAL_TEXT=	${LICENSE_NAME_COMMERCIAL}

do-extract:
	${MKDIR} ${WRKSRC}
	( cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS} )

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/marvel
	@cd ${WRKSRC} && ${COPYTREE_SHARE} _site ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/marvel
	@cd ${WRKSRC} && ${INSTALL_DATA} marvel-${PORTVERSION}.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/marvel

.include <bsd.port.mk>

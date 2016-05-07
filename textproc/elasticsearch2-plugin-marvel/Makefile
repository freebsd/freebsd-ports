# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	marvel
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://download.elastic.co/elasticsearch/release/org/elasticsearch/plugin/license/${PORTVERSION}/:source1 \
		http://download.elastic.co/elasticsearch/release/org/elasticsearch/plugin/marvel-agent/${PORTVERSION}/:source2
PKGNAMEPREFIX=	elasticsearch2-plugin-
DISTFILES=	license-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}:source1 \
		marvel-agent-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}:source2

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	ElasticSearch Marvel Monitoring Plugin

LICENSE=	COMMERCIAL
LICENSE_NAME=	Free for development; license required for production use
LICENSE_TEXT=	License available from Elasticsearch for production use.
LICENSE_TEXT+=	See http://www.elasticsearch.com/marvel/ for more details.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell no-auto-accept

RUN_DEPENDS:=	elasticsearch2>2.0.0:textproc/elasticsearch2

NO_BUILD=	yes
LEGAL_TEXT=	${LICENSE_NAME_COMMERCIAL}
PLIST_SUB=	VERSION=${PORTVERSION}

USES+=		zip

ZIP_FILES=	license \
	marvel-agent

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${ZIP_FILES}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${file}-${PORTVERSION} \
	      ${_DISTDIR}/${file}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX} )
.endfor

do-install:
	# while installing, rename marvel-agent to marvel, which is what the plugin expects when running
	@cd ${WRKDIR}/license-${PORTVERSION} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/license
	@cd ${WRKDIR}/marvel-agent-${PORTVERSION} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/marvel
.include <bsd.port.mk>

# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	apache-solr
PORTVERSION=	4.6.0
CATEGORIES=	textproc java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	lucene/solr/${PORTVERSION}
DISTNAME=	solr-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gaod@hychen.org
COMMENT=	High performance search server built using Lucene Java

LICENSE=	APACHE20

CONFLICT=	apache-solr-3.6.*

JAVA_VERSION=	1.6+
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes
PORTEXAMPLES=	*
LATEST_LINK=	apache-solr

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} \* ${JAVAJARDIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

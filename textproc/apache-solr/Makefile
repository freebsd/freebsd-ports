# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	apache-solr
PORTVERSION=	4.8.1
CATEGORIES=	textproc java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	lucene/solr/${PORTVERSION}
DISTNAME=	solr-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gaod@hychen.org
COMMENT=	High performance search server built using Lucene Java

LICENSE=	APACHE20

CONFLICT=	apache-solr-3.6.*

USES=	shebangfix
SHEBANG_FILES=	example/etc/create-solrtest.keystore.sh
JAVA_VERSION=	1.7+
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes
PORTEXAMPLES=	*
LATEST_LINK=	apache-solr

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

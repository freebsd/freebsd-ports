# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	apache-solr
PORTVERSION=	4.10.1
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/lucene/solr/${PORTVERSION}
DISTNAME=	solr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance search server built using Lucene Java

LICENSE=	APACHE20

CONFLICT=	apache-solr-3.6.*

USES=		cpe shebangfix tar:tgz
SHEBANG_FILES=	example/etc/create-solrtest.keystore.sh
JAVA_VERSION=	1.7+
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes
PORTEXAMPLES=	*
LATEST_LINK=	apache-solr
USE_RC_SUBR=	solr

CPE_PRODUCT=	solr
CPE_VENDOR=	apache

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

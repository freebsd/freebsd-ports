# New ports collection makefile for:	apache-solr
# Date created:		2009-03-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	apache-solr
PORTVERSION=	1.4.1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%,lucene/solr/${PORTVERSION},}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	High performance search server built using Lucene Java

JAVA_VERSION=	1.5+
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes

.include <bsd.port.pre.mk>

do-install:
	${CP} -R ${WRKSRC}/dist/ ${JAVAJARDIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

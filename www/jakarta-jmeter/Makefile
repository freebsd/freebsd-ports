# New ports collection makefile for:	jakarta-jmeter
# Date created:		12 August 2002
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmeter
PORTVERSION=	2.3.2
CATEGORIES=	www benchmarks java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	jmeter/binaries
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Functional behaviour load and performance test application

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jmeter.sh
DATAFILES=	bin extras lib

.if !defined(NOPORTDOCS)
PORTDOCS=	docs printable_docs README LICENSE
.endif

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC} -type f \( -name \*.bat -o -name \*.orig -o -name \*.exe -o -name \*.bak \) -delete

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/jmeter.sh ${PREFIX}/bin/jmeter

.include <bsd.port.post.mk>

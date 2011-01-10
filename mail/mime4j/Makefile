# Ports collection makefile for:	mime4j
# Date created:			3 Sep 2008
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mime4j
PORTVERSION=	0.6.1
CATEGORIES=	mail java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	james/${PORTNAME}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java parser for e-mail message streams

RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/apache-${PORTNAME}.jar

PORTDOCS=	*

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/apache-${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/apache-${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/apache-${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${DOCSDIR}
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>

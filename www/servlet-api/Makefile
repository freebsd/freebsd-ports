# New ports collection makefile for:	Servlet API
# Date created:				October 13, 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	servlet-api
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	www java
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/maven2/javax/servlet/servlet-api/2.5/ \
		http://repo1.maven.org/maven2/javax/servlet/servlet-api/2.5/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Servlet API

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>

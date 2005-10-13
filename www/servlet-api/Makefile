# New ports collection makefile for:	Servlet API
# Date created:				October 13, 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	servlet-api
PORTVERSION=	2.4
CATEGORIES=	www java
MASTER_SITES=	http://www.ibiblio.org/maven/servletapi/jars/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	hq@FreeBSD.org
COMMENT=	The Servlet API

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>

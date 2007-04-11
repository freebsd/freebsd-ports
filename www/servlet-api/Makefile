# New ports collection makefile for:	Servlet API
# Date created:				October 13, 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	servlet-api
PORTVERSION=	2.5
CATEGORIES=	www java
MASTER_SITES=	http://fisheye5.cenqua.com/browse/~raw,r=1.1.1.3/glassfish/repo/javax.servlet/jars/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	nemoliu@gmail.com
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

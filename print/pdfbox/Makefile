# New ports collection makefile for:	pdfbox
# Date created:				03 July, 2011
# Whom:					Pedro Giffuni <giffunip@tutopia.com>
#
# $FreeBSD$
#

PORTNAME=	pdfbox
PORTVERSION=	1.6.0
CATEGORIES=	print textproc java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%,pdfbox/${PORTVERSION},}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-app-${PORTVERSION}.jar	\
		fontbox-${PORTVERSION}.jar jempbox-${PORTVERSION}.jar

MAINTAINER=	giffunip@tutopia.com
COMMENT=	Java PDF Library

RUN_DEPENDS=	${JAVAJARDIR}/bcmail.jar:${PORTSDIR}/java/bouncycastle	\
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging

LICENSE=	AL2

USE_JAVA=	yes
JAVA_VERSION=	1.5+

DIST_SUBDIR=	${PORTNAME}
NO_EXTRACT=	yes
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/fontbox-${PORTVERSION}.jar	\
		%%JAVAJARDIR%%/jempbox-${PORTVERSION}.jar	\
		%%JAVAJARDIR%%/${PORTNAME}-app-${PORTVERSION}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*-${PORTVERSION}.jar \
	 ${JAVAJARDIR}
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>

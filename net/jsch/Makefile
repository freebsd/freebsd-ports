# New ports collection makefile for:	jsch
# Date created:		Thu Dec 30 22:16:57 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jsch
PORTVERSION=	0.1.18
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A pure Java implementation of SSH2

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

JAR_FILE=	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${INSTALL_DATA} ${JAR_FILE} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>

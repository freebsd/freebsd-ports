# New ports collection makefile for:	jsch
# Date created:		Thu Dec 30 22:16:57 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jsch
PORTVERSION=	0.1.42
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A pure Java implementation of SSH2

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>

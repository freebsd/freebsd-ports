# New ports collection makefile for:	jsch
# Date created:		Thu Dec 30 22:16:57 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jsch
PORTVERSION=	0.1.18
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A pure Java implementation of SSH2

USE_JAVA=	1.4+
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	share/java/jar/${PORTNAME}/

JAR_FILE=	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

PLIST_FILES+=	${JAR_DIR}/${DISTNAME}${EXTRACT_SUFX}
PLIST_DIRS+=	${JAR_DIR}

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${JAR_FILE} ${PREFIX}/${JAR_DIR}

.include <bsd.port.mk>

# New ports collection makefile for:	jce_policy14
# Date created:				2005/10/23
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jce_policy
PORTVERSION=	1.4.2
CATEGORIES=	security java
MASTER_SITES=	#http://java.sun.com/products/jce/index-14.html
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	JCE Unlimited Strength Jurisdiction Policy Files

USE_ZIP=	yes
USE_JAVA=	1.4

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jce
PLIST_FILES=	${JAVA_HOME:S,${PREFIX}/,,}/lib/security/local_policy.jar \
		${JAVA_HOME:S,${PREFIX}/,,}/lib/security/US_export_policy.jar \
		"@unexec rmdir ${JAVA_HOME}/lib/security 2>/dev/null || true"

.if !exists(${DISTDIR}/${EXTRACT_ONLY}) && !defined(PACKAGE_BUILDING)
IGNORE=		Please get jce_policy-1_4_2.zip from http://java.sun.com/products/jce/index-14.html
.endif

do-install:
	@[ -d ${JAVA_HOME}/lib/security ] || ${MKDIR} ${JAVA_HOME}/lib/security
	${INSTALL_DATA} ${WRKSRC}/local_policy.jar ${JAVA_HOME}/lib/security
	${INSTALL_DATA} ${WRKSRC}/US_export_policy.jar ${JAVA_HOME}/lib/security

.include <bsd.port.mk>

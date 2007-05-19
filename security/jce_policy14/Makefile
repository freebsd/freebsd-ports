# New ports collection makefile for:	jce_policy14
# Date created:				2005/10/23
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jce_policy
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	security java
MASTER_SITES=	#http://java.sun.com/products/jce/index-14.html
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	JCE Unlimited Strength Jurisdiction Policy Files

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jce
PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S,${PREFIX}/,,}

.include <bsd.port.pre.mk>
.if  !exists(${DISTDIR}/${DISTNAME}.zip)
IGNORE=		: Please get jce_policy-1_4_2.zip from
IGNORE+=	http://java.sun.com/products/jce/index-14.html
.endif

do-install:
	@${MV}	${JAVA_HOME}/jre/lib/security/local_policy.jar \
		${JAVA_HOME}/jre/lib/security/local_policy.jar.orig
	@${MV}	${JAVA_HOME}/jre/lib/security/US_export_policy.jar \
		${JAVA_HOME}/jre/lib/security/US_export_policy.jar.orig
	@${TOUCH} ${JAVA_HOME}/jre/lib/security/.jce_policy14
	@${INSTALL_DATA} ${WRKSRC}/local_policy.jar     ${JAVA_HOME}/jre/lib/security
	@${INSTALL_DATA} ${WRKSRC}/US_export_policy.jar ${JAVA_HOME}/jre/lib/security

.include <bsd.port.post.mk>

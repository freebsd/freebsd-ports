# New ports collection makefile for:	Jakarta POI API
# Date created:				Wed Mar  2 22:01:02 EET 2005
# Whom:					Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	poi
PORTVERSION=	2.5.1
CATEGORIES=	textproc devel java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/release/src
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-final-20040804

MAINTAINER=	toha@toha.org.ua
COMMENT=	Java API To Access Microsoft Format Files

BUILD_DEPENDS=	${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_JIKES=	no

NO_WRKSUBDIR=	yes

DSTAMP=		`date +%Y%m%d`

USE_ANT=	yes
MAKE_ENV+=	ANT_INCLUDE_SHARED_JARS=YES
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
ALL_TARGET=	jar
JARFILE=	${PORTNAME}-${PORTVERSION}-final-${DSTAMP}.jar
DESTJARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/build/dist/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/docs/apidocs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	AXIS
# Date created:				6 JUNE 2003
# Whom:					Kensaku MASUDA <greg@greg.rim.or.jp>
#
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.1
CATEGORIES=		www java
MASTER_SITES=		http://ws.apache.org/axis/dist/1_1rc2/
MASTER_SITE_SUBDIR=	znerd
DISTNAME=		axis-1_1rc2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SOAP implementation by APACHE project

#
# Change webapp directory by TOMCAT version
#
.if exists(${LOCALBASE}/jakarta-tomcat4.1/webapps)
WEBAPPDIR=	${LOCALBASE}/jakarta-tomcat4.1/webapps
BUILD_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/jakarta-tomcat41
RUN_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/jakarta-tomcat41
.elif exists(${LOCALBASE}/jakarta-tomcat4.0.6/webapps)
WEBAPPDIR=	${LOCALBASE}/jakarta-tomcat4.0.6/webapps
BUILD_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.0.6:${PORTSDIR}/www/jakarta-tomcat4
RUN_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.0.6:${PORTSDIR}/www/jakarta-tomcat4
.else
WEBAPPDIR=	${LOCALBASE}/jakarta-tomcat4.1/webapps
BUILD_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/jakarta-tomcat41
RUN_DEPENDS+=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/jakarta-tomcat41
.endif

NO_BUILD=	YES
USE_JAVA=	1.4+
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/axis-1_1RC2
USER=		www
GROUP=		www

.include <bsd.port.pre.mk>
#
# Change install directory by JDK version
#
.if defined(JAVA_VER) && (${JAVA_VER} == 1.4.1)
JAR_INSTALL_DEST_DIR=	${JAVA_HOME}/jre/lib/endorsed
.else
JAR_INSTALL_DEST_DIR=	${JAVA_HOME}/jre/lib/ext
.endif

#
# Install procedure
#
SYSTEM_JARS=	jaxrpc.jar saaj.jar

do-install:
.if !exists(${JAR_INSTALL_DEST_DIR})
	${MKDIR} ${JAR_INSTALL_DEST_DIR}
.endif
.for i in ${SYSTEM_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAR_INSTALL_DEST_DIR}
.endfor
	(cd ${WRKSRC}/webapps ; tar cf - axis) | (cd ${WEBAPPDIR} ; tar xvf - )
	${CHOWN} -R ${USER} ${WEBAPPDIR}/axis
	${CHGRP} -R ${GROUP} ${WEBAPPDIR}/axis
.if !exists(${PREFIX}/share/doc/axis)
	${MKDIR} ${PREFIX}/share/doc/axis
.endif
	(cd ${WRKSRC}/docs ; tar cf - *) | (cd ${PREFIX}/share/doc/axis ; tar xvf -)
	${SED} -e 's@PREFIX@${PREFIX}@g' -e s'@WEBAPPS@${WEBAPPDIR}@g' -e 's@JDK_HOME@${JAVA_HOME}/jre@g' < pkg-plist > ${WRKDIR}/pkg-plist

.include <bsd.port.post.mk>

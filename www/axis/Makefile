# New ports collection makefile for:	AXIS
# Date created:				6 JUNE 2003
# Whom:					Kensaku MASUDA <greg@greg.rim.or.jp>
#
# Most of pkg-plist can be created with:
# # make PREFIX=`pwd`/install install
# # (echo @cwd %%WEBAPPS%% ; /usr/ports/Tools/scripts/plist -d -m /etc/mtree/BSD.local.dist /usr/local/jakarta-tomcat4.1/webapps/axis/ | sed -E 's,^([^@]),axis/\1,g ; s,^(@.+ ),\1axis/,g' ; echo @dirrm axis) > temp-pkg-plist
# # (echo @cwd %%PREFIX%% ; /usr/ports/Tools/scripts/plist -d -m /etc/mtree/BSD.local.dist `pwd`/install|sed -E 's,^.+share/nls/.+$,,g'|tr -s '\n') >> temp-pkg-plist
#
# $FreeBSD$

PORTNAME=		axis
PORTVERSION=		1.1
PORTREVISION=		2
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/axis/${PORTVERSION:S,.,_,g}
DISTNAME=		axis-${PORTVERSION:S,.,_,g}

MAINTAINER=	rui@ruilopes.com
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
USER=		www
GROUP=		www

.include <bsd.port.pre.mk>
#
# Change install directory by JDK version
#
.if defined(JAVA_PORT_VERSION) && (${JAVA_PORT_VERSION} == "1.4.1")
LIB_SUBDIR=		endorsed
.else
LIB_SUBDIR=		ext
.endif
JAR_INSTALL_DEST_DIR=	${JAVA_HOME}/jre/lib/${LIB_SUBDIR}

#
# Install procedure
#
SYSTEM_JARS=	jaxrpc.jar saaj.jar
PLIST_SUB=	PREFIX=${PREFIX} WEBAPPS=${WEBAPPDIR} JRE_HOME="${JAVA_HOME}/jre" \
		LIB_SUBDIR=${LIB_SUBDIR} USER=${USER} GROUP=${GROUP}

.if !defined(NOPORTDOCS)
SAMPLECLASSES=''
.else
SAMPLECLASSES=classes
.endif

do-install:
	${MKDIR} ${JAR_INSTALL_DEST_DIR}
.for i in ${SYSTEM_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAR_INSTALL_DEST_DIR}
.endfor
	(cd ${WRKSRC}/webapps ; tar cf - --exclude "${SAMPLECLASSES}" axis) | (cd ${WEBAPPDIR} ; tar xvf -)
	${CHOWN} -R ${USER}:${GROUP} ${WEBAPPDIR}/axis
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/axis
	(cd ${WRKSRC}/docs ; tar cf - *) | (cd ${PREFIX}/share/doc/axis ; tar xvf -)
	${MKDIR} ${PREFIX}/share/examples/axis
	(cd ${WRKSRC}/samples ; tar cf - --exclude '*.class' *) | (cd ${PREFIX}/share/examples/axis ; tar xvf -)
.endif

.include <bsd.port.post.mk>

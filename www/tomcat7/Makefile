# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat
PORTVERSION=	7.0.92
PORTREVISION=	0
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-7/v${PORTVERSION}/bin
PKGNAMESUFFIX=	7
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 7.x branch

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	${PKGBASE}

TOMCAT_SUBDIR?=	${DISTNAME:R}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}
PLIST_SUB=	T=${TOMCAT_SUBDIR} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=		HOST_MANAGER MANAGER DOCS EXAMPLES ROOT
OPTIONS_DEFAULT=	HOST_MANAGER MANAGER ROOT
OPTIONS_SUB=		yes

DOCS_DESC=		Install Documentation web application
EXAMPLES_DESC=		Install Examples web application
HOST_MANAGER_DESC=	Install Host Manager application
MANAGER_DESC=		Install Manager web application
ROOT_DESC=		Install default ROOT web application

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${TOMCAT_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/endorsed
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMCAT_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${STAGEDIR}${TOMCAT_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${RM} ${STAGEDIR}${TOMCAT_HOME}/bin/*.bat
	(cd ${STAGEDIR}${TOMCAT_HOME}/conf &&\
		for f in $$(find . -type f); do ${MV} $$f $$f.sample; done)

post-install-HOST_MANAGER-on:
	(cd ${STAGEDIR}${TOMCAT_HOME}/webapps &&\
		for f in host-manager/META-INF/context.xml host-manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

post-install-HOST_MANAGER-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/host-manager

post-install-MANAGER-on:
	(cd ${STAGEDIR}${TOMCAT_HOME}/webapps &&\
		for f in manager/META-INF/context.xml manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

post-install-MANAGER-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/manager

post-install-DOCS-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/docs

post-install-EXAMPLES-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/examples

post-install-ROOT-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/ROOT

.include <bsd.port.post.mk>

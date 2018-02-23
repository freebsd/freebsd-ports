# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat
PORTVERSION=	9.0.5
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/([0-9])(.*)/\1/}/v${PORTVERSION}/bin
PKGNAMESUFFIX=	9
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vvd@unislabs.com
COMMENT=	Open-source Java web server by Apache, 9.0.x branch

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/jakarta-commons-daemon

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	${PKGBASE:C/-/_/}

TOMCAT_SUBDIR?=	${DISTNAME:C/([0-9])\.([0-9])(.*)/\1.\2/}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}
TOMCAT_CONF_FILES=	\
		catalina.policy catalina.properties context.xml logging.properties \
		server.xml tomcat-users.xml tomcat-users.xsd web.xml \
		jaspic-providers.xml jaspic-providers.xsd

OPTIONS_DEFINE= HOST_MANAGER MANAGER DOCS EXAMPLES ROOT
HOST_MANAGER_DESC= Install Host Manager application
MANAGER_DESC= Install Manager web application
DOCS_DESC= Install Documentation web application
EXAMPLES_DESC= Install Examples web application
ROOT_DESC= Install default ROOT web application
OPTIONS_DEFAULT= HOST_MANAGER MANAGER DOCS EXAMPLES ROOT
OPTIONS_SUB= yes

PLIST_SUB=	T=${TOMCAT_SUBDIR} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${TOMCAT_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

post-patch:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
.for f in ${TOMCAT_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.sample
.endfor

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/endorsed
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMCAT_HOME}
.if !${PORT_OPTIONS:MHOST_MANAGER}
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/host-manager
.endif
.if !${PORT_OPTIONS:MMANAGER}
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/manager
.endif
.if !${PORT_OPTIONS:MDOCS}
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/docs
.endif
.if !${PORT_OPTIONS:MEXAMPLES}
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/examples
.endif
.if !${PORT_OPTIONS:MROOT}
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/ROOT
.endif
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${STAGEDIR}${TOMCAT_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>

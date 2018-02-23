# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat
PORTVERSION=	8.5.28
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-8/v${PORTVERSION}/bin
PKGNAMESUFFIX=	85
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vvd@unislabs.com
COMMENT=	Open-source Java web server by Apache, 8.5.x branch

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/jakarta-commons-daemon

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_RC_SUBR=	${PKGBASE}

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	T=${TOMCAT_SUBDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=		HOST_MANAGER MANAGER DOCS EXAMPLES ROOT
OPTIONS_DEFAULT=	HOST_MANAGER MANAGER DOCS EXAMPLES ROOT
OPTIONS_SUB=		yes

DOCS_DESC=		Install Documentation web application
EXAMPLES_DESC=		Install Examples web application
HOST_MANAGER_DESC=	Install Host Manager application
MANAGER_DESC=		Install Manager web application
ROOT_DESC=		Install default ROOT web application

TOMCAT_SUBDIR?=	${DISTNAME:R}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/endorsed
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMCAT_HOME}

post-install:
	@${RM} ${STAGEDIR}${TOMCAT_HOME}/bin/*.bat
	(cd ${STAGEDIR}${TOMCAT_HOME}/conf &&\
		for f in $$(find . -type f); do ${MV} $$f $$f.sample; done)

post-install-HOST_MANAGER-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/host-manager

post-install-MANAGER-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/manager

post-install-DOCS-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/docs

post-install-EXAMPLES-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/examples

post-install-ROOT-off:
	@${RM} -R ${STAGEDIR}${TOMCAT_HOME}/webapps/ROOT

.include <bsd.port.mk>

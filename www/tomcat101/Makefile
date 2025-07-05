PORTNAME=	tomcat
DISTVERSION=	10.1.43
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${DISTVERSION:C/([0-9]+)(.*)/\1/}/v${DISTVERSION}/bin
PKGNAMESUFFIX=	101
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 10.1.x branch
WWW=		https://tomcat.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe java
CPE_VENDOR=	apache
JAVA_VERSION=	11+
USE_RC_SUBR=	${PKGBASE:C/-/_/}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}
PLIST_SUB=	T=${TOMCAT_SUBDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		HOST_MANAGER MANAGER DOCS EXAMPLES ROOT NLS
OPTIONS_DEFAULT=	HOST_MANAGER MANAGER ROOT
OPTIONS_SUB=		yes

DOCS_DESC=		Install Documentation web application
EXAMPLES_DESC=		Install Examples web application
HOST_MANAGER_DESC=	Install Host Manager application
MANAGER_DESC=		Install Manager web application
ROOT_DESC=		Install default ROOT web application

TOMCAT_SUBDIR?=	${DISTNAME:R}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}

post-patch:
	@${RM} ${WRKSRC}/bin/commons-daemon-native.tar.gz ${WRKSRC}/bin/commons-daemon.jar ${WRKSRC}/bin/tomcat-native.tar.gz
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; s|%%JAVAJARDIR%%|${JAVAJARDIR}|g' ${WRKSRC}/bin/daemon.sh
	@${FIND} ${WRKSRC} -name '*.bak' -delete -o -name '*.orig' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/endorsed
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMCAT_HOME}

post-install:
	@${RM} ${STAGEDIR}${TOMCAT_HOME}/bin/*.bat
	@(cd ${STAGEDIR}${TOMCAT_HOME}/conf &&\
		for f in $$(find . -type f -not -name '*.xsd'); do ${MV} $$f $$f.sample; done)

post-install-HOST_MANAGER-on:
	@(cd ${STAGEDIR}${TOMCAT_HOME}/webapps &&\
		for f in host-manager/META-INF/context.xml host-manager/WEB-INF/manager.xml host-manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

post-install-MANAGER-on:
	@(cd ${STAGEDIR}${TOMCAT_HOME}/webapps &&\
		for f in manager/META-INF/context.xml manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

.include <bsd.port.mk>

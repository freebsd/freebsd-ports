PORTNAME=	tomcat
DISTVERSION=	9.0.109
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${DISTVERSION:C/([0-9])(.*)/\1/}/v${DISTVERSION}/bin
PKGNAMESUFFIX=	9
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Open-source Java web server by Apache, 9.0.x branch
WWW=		https://tomcat.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe java
CPE_VENDOR=	apache
USE_RC_SUBR=	${PKGBASE:C/-/_/}

EXTRACT_AFTER_ARGS=	--exclude commons-daemon-native.tar.gz \
			--exclude commons-daemon.jar \
			--exclude tomcat-native.tar.gz \
			--exclude *.bat \
			--no-same-owner --no-same-permissions

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
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; s|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
		${WRKSRC}/bin/daemon.sh
	${FIND} ${WRKSRC} -name '*.bak' -delete -o -name '*.orig' -delete

do-install:
	${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs \
		 ${STAGEDIR}${TOMCAT_HOME}/endorsed
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${TOMCAT_HOME} "! -name *\.sh" && \
		${COPYTREE_BIN} bin ${STAGEDIR}${TOMCAT_HOME} "-name *\.sh")

post-install:
	${FIND} ${STAGEDIR}${TOMCAT_HOME}/conf -type f -not -name '*.xsd' -exec ${MV} {} {}.sample \;

post-install-HOST_MANAGER-on:
	(cd ${STAGEDIR}${TOMCAT_HOME}/webapps/host-manager && \
		for f in META-INF/context.xml WEB-INF/manager.xml WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

post-install-MANAGER-on:
	(cd ${STAGEDIR}${TOMCAT_HOME}/webapps/manager && \
		for f in META-INF/context.xml WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	jetty
PORTVERSION=	9.4.26
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-distribution/${PORTVERSION}.${JDVDATE}/
PKGNAMESUFFIX=	9
DISTNAME=	jetty-distribution-${PORTVERSION}.${JDVDATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured web server implemented entirely in Java

LICENSE=	APACHE20 EPL
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/license-eplv10-aslv20.html

RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	jetty-8.*

JDVDATE=	v20200117
USE_JAVA=	yes
NO_ARCH=	yes
USES=		shebangfix
SHEBANG_FILES=	bin/jetty.sh
NO_BUILD=	yes
JAVA_VERSION=	1.8+
JAVA_VENDOR=	openjdk
ONLY_FOR_ARCHS=	i386 amd64
USE_RC_SUBR=	${PORTNAME}

APP_NAME=	${PORTNAME}
APP_HOME=	${PREFIX}/${PORTNAME}

USERS=		www
GROUPS=		www

SUB_LIST=	\
		APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA} \
		WWWDIR=${WWWDIR}

SUB_FILES=	\
		${APP_NAME} \
		pkg-message \
		jetty.sample

PLIST_SUB=	\
		APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		WWWDIR=${WWWDIR} \
		PORTVERSION=${PORTVERSION} \
		JDVDATE=${JDVDATE}

do-install:
		${MKDIR} ${STAGEDIR}${APP_HOME}
		${MKDIR} ${STAGEDIR}${WWWDIR}
		${RM} ${WRKSRC}/lib/setuid/libsetuid-linux.so
		${RM} ${WRKSRC}/lib/setuid/libsetuid-osx.so
		(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
		${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/demo-base ${STAGEDIR}${WWWDIR}
		${MKDIR} ${STAGEDIR}${WWWDIR}/demo-base/logs
		${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin

		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>

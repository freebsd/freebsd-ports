PORTNAME=	jetty
PORTVERSION=	12.0.23
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-home/${PORTVERSION}/
PKGNAMESUFFIX=	12
DISTNAME=	jetty-home-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Full-featured web server implemented entirely in Java
WWW=		https://www.eclipse.org/jetty/

LICENSE=	APACHE20 EPL
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

USES=		cpe java shebangfix

CONFLICTS=	jetty8.* jetty9.* jetty10.* jetty11.*

NO_ARCH=	yes
CPE_VENDOR=	eclipse
SHEBANG_FILES=	bin/jetty.sh
NO_BUILD=	yes
JAVA_VERSION=	17+
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	${PORTNAME}
ASMVER=		9.8

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
		ASMVER=${ASMVER}

do-install:
		${MKDIR} ${STAGEDIR}${APP_HOME} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
		${RM} ${WRKSRC}/lib/setuid/libsetuid-linux.so ${WRKSRC}/lib/setuid/libsetuid-osx.so
		(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
		${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin

		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>

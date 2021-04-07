PORTNAME=		bastillion
DISTVERSIONPREFIX=	jetty-v
DISTVERSION=		3.10_00
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${PORTNAME}-upgrade-3.08.00.jar
PORTREVISION=		0
CATEGORIES=		security www java
MASTER_SITES=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${PORTVERSION}/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Web-based SSH console

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
USE_JAVA=	yes
USE_GITHUB=	nodefault

SHEBANG_FILES=	jetty_bastillion/bin/jetty.sh
GH_ACCOUNT=	bastillion-io
GH_PROJECT=	Bastillion

NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	11+
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/Bastillion-jetty

APP_NAME=	${PORTNAME}
WWWDIR=		www/${PORTNAME}

USERS=		www
GROUPS=		www

SUB_LIST=	\
		APP_NAME=${APP_NAME} \
		JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA} \
		WWWDIR=${WWWDIR}

SUB_FILES=	\
		${APP_NAME} \
		bastillion.sample \
		pkg-message

PLIST_SUB=	APP_NAME=${APP_NAME} \
		WWWDIR=${WWWDIR}

post-extract:
	${RM} ${WRKSRC}/*.bat ${WRKSRC}/startBastillion.sh
	${MV} ${WRKSRC}/jetty ${WRKSRC}/jetty_bastillion
	${MV} ${WRKSRC}/jetty_bastillion/bastillion/WEB-INF/classes/BastillionConfig.properties ${WRKSRC}/jetty_bastillion/bastillion/WEB-INF/classes/BastillionConfig.properties.sample
	${MV} ${WRKSRC}/jetty_bastillion/start.ini ${WRKSRC}/
	${MV} ${WRKSRC}/jetty_bastillion/webapps ${WRKSRC}/
	${MV} ${WRKSRC}/jetty_bastillion/etc ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${WWWDIR}/work
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	cd ${WRKSRC}; ${COPYTREE_BIN} jetty_bastillion ${STAGEDIR}${PREFIX} "! -name *\.orig"
	${MKDIR} ${STAGEDIR}${PREFIX}/jetty_bastillion/upgrade
	cd ${WRKSRC}; ${COPYTREE_SHARE} webapps ${STAGEDIR}${PREFIX}/${WWWDIR} "! -name *\.orig"
	cd ${WRKSRC}; ${COPYTREE_SHARE} etc ${STAGEDIR}${PREFIX}/${WWWDIR} "! -name *\.orig"
	${RLN} ${STAGEDIR}${PREFIX}/${WWWDIR}/etc ${STAGEDIR}${PREFIX}/jetty_bastillion/etc
	${INSTALL_DATA} ${WRKSRC}/start.ini ${STAGEDIR}${PREFIX}/${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${PREFIX}/${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${DISTDIR}/bastillion-upgrade-3.08.00.jar ${STAGEDIR}${PREFIX}/jetty_bastillion/upgrade/

gen-plist:
	${ECHO} '@sample %%ETCDIR%%/%%APP_NAME%%.sample' >${PLIST}.new
	${ECHO} '@sample(www,www,644) jetty_bastillion/bastillion/WEB-INF/classes/BastillionConfig.properties.sample' >> ${PLIST}.new
	${ECHO} '@dir(www,www,755) /var/log/%%APP_NAME%%' >> ${PLIST}.new
	${ECHO} '@dir(www,www,755) /var/run/%%APP_NAME%%' >> ${PLIST}.new
	${FIND} ${STAGEDIR}${PREFIX}/jetty_bastillion -type f -a ! -name \*.orig -a ! -name \*.sample | ${SED} -e "s:${STAGEDIR}${PREFIX}/::g" | ${SORT} >> ${PLIST}.new
	${ECHO} '@dir(www,www,755) jetty_bastillion/bastillion/WEB-INF/classes' >> ${PLIST}.new
	${ECHO} '@dir(www,www,755) %%WWWDIR%%' >> ${PLIST}.new
	${ECHO} '@dir(www,www,755) %%WWWDIR%%/work' >> ${PLIST}.new
	${ECHO} '%%WWWDIR%%/start.ini' >> ${PLIST}.new
	${ECHO} '%%WWWDIR%%/3rdPartyLicenses.md' >> ${PLIST}.new
	${ECHO} '%%WWWDIR%%/LICENSE.md' >> ${PLIST}.new
	${ECHO} '%%WWWDIR%%/README.md' >> ${PLIST}.new
	${FIND} ${STAGEDIR}${PREFIX}/${WWWDIR}/webapps -type f -a ! -name \*.orig | ${SED} -e "s:${STAGEDIR}${PREFIX}/${WWWDIR}:%%WWWDIR%%:g" | ${SORT} >> ${PLIST}.new
	${FIND} ${STAGEDIR}${PREFIX}/${WWWDIR}/etc -type f -a ! -name \*.orig | ${SED} -e "s:${STAGEDIR}${PREFIX}/${WWWDIR}:%%WWWDIR%%:g" | ${SORT} >> ${PLIST}.new
	${ECHO} 'jetty_bastillion/etc' >> ${PLIST}.new

.include <bsd.port.mk>

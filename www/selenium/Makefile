PORTNAME=	selenium
DISTVERSION=	4.34.0
CATEGORIES=	www devel java
MASTER_SITES=	https://github.com/SeleniumHQ/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/
DISTNAME=	selenium-server-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	daniel@blodan.se
COMMENT=	Selenium Standalone Server, allows browser testing
WWW=		https://www.seleniumhq.org

LICENSE=	APACHE20

USES=		cpe java
CPE_VENDOR=	jenkins
JAVA_VERSION=	11+

USE_RC_SUBR=	selenium

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		SELENIUM_VERSION=${DISTVERSION}

SELENIUM_HOME=	${PREFIX}/selenium

USERS=		selenium
GROUPS=		selenium

PLIST_FILES=	\@dir\(${USERS},${GROUPS},\)\ selenium \
		${DATADIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${SELENIUM_HOME}
	${INSTALL_DATA} ${DISTDIR}${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

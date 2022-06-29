PORTNAME=	selenium
PORTVERSION=	4.1.3	
PORTREVISION=	1
CATEGORIES=	www devel java
MASTER_SITES=	https://github.com/SeleniumHQ/selenium/releases/download/selenium-4.1.0/
DISTNAME=	selenium-server-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	daniel@blodan.se
COMMENT=	Selenium Standalone Server, allows browser testing

LICENSE=	APACHE20

USES=		cpe
CPE_VENDOR=	jenkins

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_RUN=	yes

USE_RC_SUBR=	selenium

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		SELENIUM_VERSION=${PORTVERSION}

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

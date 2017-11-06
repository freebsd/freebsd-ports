# $FreeBSD$

PORTNAME=	selenium
PORTVERSION=	3.5.3
CATEGORIES=	www devel java
MASTER_SITES=	http://selenium-release.storage.googleapis.com/3.5/
DISTNAME=	selenium-server-standalone-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	daniel@blodan.se
COMMENT=	Selenium Standalone Server, allows browser testing

LICENSE=	APACHE20

NO_ARCH=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_RUN=	yes

NO_BUILD=	yes

USE_RC_SUBR=	selenium

SELENIUM_HOME=	${PREFIX}/selenium

USERS=		selenium
GROUPS=		selenium

SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		SELENIUM_VERSION=${PORTVERSION}

PLIST_FILES=	\@dir\(${USERS},${GROUPS},\)\ selenium \
		%%DATADIR%%/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${SELENIUM_HOME}
	${INSTALL_DATA} ${DISTDIR}${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

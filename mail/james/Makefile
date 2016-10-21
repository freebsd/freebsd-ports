# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	james
PORTVERSION=	2.3.2.1
CATEGORIES=	mail java
MASTER_SITES=	APACHE/${PORTNAME}/server/
DISTNAME=	${PORTNAME}-binary-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java SMTP and POP3 Mail server and NNTP News server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	james

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PID_FILE=	/var/run/${PORTNAME}.pid
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		PID_FILE=${PID_FILE} \
		JAMES_HOME=${APP_HOME}

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${APP_HOME}
	@${MKDIR} ${STAGEDIR}${APP_HOME}/logs
	@${MKDIR} ${STAGEDIR}${APP_HOME}/apps
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${STAGEDIR}${APP_HOME}/lib/tools.jar
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} "${PORTNAME} ${PORTVERSION} has been installed in ${APP_HOME}."

.include <bsd.port.mk>

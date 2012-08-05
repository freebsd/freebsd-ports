# New ports collection makefile for:	geronimo
# Date created:		30 May 2007
# Whom:			Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	james
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	mail java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/server/binaries
DISTNAME=	${PORTNAME}-binary-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java SMTP and POP3 Mail server and NNTP News server

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	YES

USE_RC_SUBR=	james

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		PID_FILE=${PID_FILE} \
		JAMES_HOME=${APP_HOME} \
		JAMES_VERSION=${PORTVERSION:S/.//g}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${MKDIR} ${APP_HOME}/logs
	@${MKDIR} ${APP_HOME}/apps
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Creating symlink to tools.jar..."
	@${LN} -sf ${JAVA_HOME}/lib/tools.jar ${APP_HOME}/lib/tools.jar
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${ECHO_MSG} "${PORTNAME} ${PORTVERSION} has been installed in ${APP_HOME}."

.include <bsd.port.post.mk>

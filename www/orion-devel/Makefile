# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	4
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		${MASTER_SITE_LOCAL} \
		http://www.jollem.com/ \
		http://www.sebster.com/~elvis/
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/linux-jdk13

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB+=	TARGET_PREFIX=${TARGET_PREFIX:S/^${PREFIX}\///}
ORION_HOME=	${PREFIX}/${DISTNAME}
PORTTITLE=	Orion Server
ORIONCTL_NAME=	orionctl
ORIONCTL_DEST=	${PREFIX}/bin/${ORIONCTL_NAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh
JAVA_HOME?=	${LOCALBASE}/linux-jdk1.3.0
TARGET_PREFIX?=	${PREFIX}/${PKGBASE}${PORTVERSION}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${ORION_HOME}
	@${CP} -R ${WRKSRC}/* ${ORION_HOME}
	@${CHMOD} 755 `find ${ORION_HOME} -type d`
	@${CAT} ${FILESDIR}/${ORIONCTL_NAME} \
	| ${SED} "/%%PORTNAME%%/s//${PORTNAME}/" \
	| ${SED} "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	| ${SED} "/%%ORION_HOME%%/s//${ORION_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%RC_SCRIPT_NAME%%/s//${PORTNAME}.sh/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	> ${ORIONCTL_DEST}
	@${CHMOD} 755 ${ORIONCTL_DEST}
	@${LN} -sf ${ORIONCTL_DEST} ${RC_SCRIPT}
	@${MKDIR} ${ORION_HOME}/application-deployments
	@${LN} -sf ${JAVA_HOME}/jre/tools.jar ${ORION_HOME}/tools.jar

post-install:
	@echo "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_HOME}."

.include <bsd.port.post.mk>

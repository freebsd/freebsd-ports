# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	6
CATEGORIES=	www java
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
PLIST_SUB+=	T=${ORION_HOME:S/^${PREFIX}\///}
ORION_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PORTTITLE=	Orion Server
ORIONCTL_NAME=	orionctl
ORIONCTL_DEST=	${PREFIX}/bin/${ORIONCTL_NAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh
JAVA_HOME?=	${LOCALBASE}/linux-jdk1.3.1

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${ORION_HOME}
	${CP} -R ${WRKSRC}/* ${ORION_HOME}
	${CHMOD} 755 `find ${ORION_HOME} -type d`
	${CAT} ${FILESDIR}/${ORIONCTL_NAME} \
	| ${SED} "/%%PORTNAME%%/s//${PORTNAME}/" \
	| ${SED} "/%%PORTVERSION%%/s//${PORTVERSION}/" \
	| ${SED} "/%%ORION_HOME%%/s//${ORION_HOME:S/\//\\\//g}/" \
	| ${SED} "/%%RC_SCRIPT_NAME%%/s//${PORTNAME}.sh/" \
	| ${SED} "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/" \
	> ${ORIONCTL_DEST}
	${CAT} ${FILESDIR}/${ORIONCTL_NAME}.1 \
	| ${SED} "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/" \
	> ${WRKDIR}/${ORIONCTL_NAME}.1
	${CHMOD} 755 ${ORIONCTL_DEST}
	${LN} -sf ${ORIONCTL_DEST} ${RC_SCRIPT}
	${MKDIR} ${ORION_HOME}/application-deployments
	${LN} -sf ${JAVA_HOME}/lib/tools.jar ${ORION_HOME}/tools.jar
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKDIR}/orionctl.1 ${MANPREFIX}/man/man1
.endif

post-install:
	@${ECHO} "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_HOME}."
.if !defined(NOPORTDOCS)
	@${ECHO} "Use 'man orionctl' for information about starting and stopping Orion."
.endif

.include <bsd.port.post.mk>

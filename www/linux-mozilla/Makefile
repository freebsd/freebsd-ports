# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.7.13
DISTVERSIONPREFIX=	i686-pc-linux-gnu-
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}${PORTVERSION}
PKGNAMEPREFIX=	linux-

MAINTAINER=	infofarmer@gmail.com
COMMENT=	The open source, standards compliant web browser

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
APP_NAME=	${UNIQUENAME}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
FDIR=		${PREFIX}/lib/${APP_NAME}

PLIST_SUB+=	APP_NAME=${APP_NAME}
SUB_LIST+=	APP_NAME=${APP_NAME}
SUB_FILES=	linkfarm pkg-message linux-mozilla.desktop
PKGMESSAGE=	${WRKDIR}/pkg-message
PREFS_FILE=	${WRKSRC}/defaults/pref/browser-prefs.js

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO} 'pref("general.useragent.vendor", "'${OPSYS}'");' >> ${PREFS_FILE}
	@${ECHO} 'pref("general.useragent.vendorSub", "'${ARCH}'");' >> ${PREFS_FILE}

do-install:
	${INSTALL} -d ${FDIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${APP_NAME}.desktop ${PREFIX}/share/applications
	${CP} -pR ${WRKSRC}/ ${FDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${FDIR}/
	${INSTALL_SCRIPT} ${FILESDIR}/run ${PREFIX}/bin/${APP_NAME}
	${ECHO} 'cd ${PREFIX} && exec ${FDIR}/${PORTNAME}' >> ${PREFIX}/bin/${APP_NAME}

post-install:
	@${SH} ${FDIR}/linkfarm
	@${CAT} ${PKGMESSAGE}

# Maintainer section
create-plist:
	${ECHO_CMD} bin/%%APP_NAME%% > ${PLIST}
	${ECHO_CMD} share/applications/%%APP_NAME%%.desktop >> ${PLIST}
	cd ${WRKDIR} && ${FIND} ${PORTNAME} -type f -or -type l | \
		${SED} -e "s#^${PORTNAME}#lib/%%APP_NAME%%#" | ${SORT} >> ${PLIST}
	${ECHO_CMD} lib/%%APP_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @exec %%PREFIX%%/lib/%%APP_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @unexec ${FIND} %%PREFIX%%/lib/%%APP_NAME%%/plugins \
		-type l -delete >> ${PLIST}
	cd ${WRKDIR} && ${FIND} -d ${PORTNAME} -type d | \
	${SED} -e "s#^${PORTNAME}#@dirrm lib/%%APP_NAME%%#" >> ${PLIST}
	${ECHO_CMD} @dirrmtry share/applications >> ${PLIST}

.include <bsd.port.post.mk>

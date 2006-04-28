# New ports collection makefile for:	linux-thunderbird
# Date created:		17 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	thunderbird
PORTVERSION=	1.5.0.2
CATEGORIES=	mail linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR?=	${PORTNAME}/releases/${PORTVERSION}/linux-i686/en-US
PKGNAMEPREFIX=	linux-

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

RUN_DEPENDS?=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
		${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/share/icons/hicolor/index.theme:${PORTSDIR}/x11-themes/linux-hicolor-icon-theme

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
APP_NAME=	${UNIQUENAME}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
FDIR=		${PREFIX}/lib/${APP_NAME}

PLIST_SUB+=	APP_NAME=${APP_NAME}
SUB_LIST+=	APP_NAME=${APP_NAME}
SUB_FILES=	${APP_NAME}.desktop
PKGMESSAGE=	${WRKDIR}/pkg-message
PREFS_FILE=	${WRKSRC}/defaults/pref/${PORTNAME}.js

.include <bsd.port.pre.mk>

do-install:
	${INSTALL} -d ${FDIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${APP_NAME}.desktop ${PREFIX}/share/applications
	${CP} -pR ${WRKSRC}/ ${FDIR}/
	${INSTALL_SCRIPT} ${FILESDIR}/run ${PREFIX}/bin/${APP_NAME}
	${ECHO} 'cd ${PREFIX} && exec ${FDIR}/${PORTNAME}' >> ${PREFIX}/bin/${APP_NAME}

# Maintainer section
create-plist:
	${ECHO_CMD} bin/%%APP_NAME%% > ${PLIST}
	${ECHO_CMD} share/applications/%%APP_NAME%%.desktop >> ${PLIST}
	cd ${WRKDIR} && ${FIND} ${PORTNAME} -type f -or -type l | \
		${SED} -e "s#^${PORTNAME}#lib/%%APP_NAME%%#" | ${SORT} >> ${PLIST}
	cd ${WRKDIR} && ${FIND} -d ${PORTNAME} -type d | \
		${SED} -e "s#^${PORTNAME}#@dirrm lib/%%APP_NAME%%#" >> ${PLIST}
	${ECHO_CMD} @dirrmtry share/applications >> ${PLIST}

.include <bsd.port.post.mk>

# New ports collection makefile for:	linux-firefox
# Date created:				2004-09-17
# Whom:					voisine
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.5.0.3
CATEGORIES?=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR?=	firefox/releases/${PORTVERSION}/linux-i686/en-US
PKGNAMEPREFIX?=	linux-

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Web browser based on the browser portion of Mozilla

RUN_DEPENDS?=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
		${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/share/icons/hicolor/index.theme:${PORTSDIR}/x11-themes/linux-hicolor-icon-theme

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
BROWSER_NAME=	${UNIQUENAME}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
FDIR=		${PREFIX}/lib/${BROWSER_NAME}

PLIST_SUB+=	BROWSER_NAME=${BROWSER_NAME}
SUB_LIST+=	BROWSER_NAME=${BROWSER_NAME}
SUB_FILES=	linkfarm pkg-message linux-firefox.desktop
PKGMESSAGE=	${WRKDIR}/pkg-message
PREFS_FILE=	${WRKSRC}/defaults/pref/firefox.js

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO} 'pref("general.useragent.vendor", "'${OPSYS}'");' >> ${PREFS_FILE}
	@${ECHO} 'pref("general.useragent.vendorSub", "'${ARCH}'");' >> ${PREFS_FILE}

do-install:
	${INSTALL} -d ${FDIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/linux-firefox.desktop ${PREFIX}/share/applications
	${CP} -pR ${WRKSRC}/ ${FDIR}/
	${CHOWN} -R ${BINOWN}:${BINGRP} ${FDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${FDIR}/
	${INSTALL_SCRIPT} ${FILESDIR}/run ${PREFIX}/bin/${BROWSER_NAME}
	${ECHO} 'cd ${PREFIX} && exec ${FDIR}/${PORTNAME} "$$@"' >> ${PREFIX}/bin/${BROWSER_NAME}

post-install:
	@${SH} ${FDIR}/linkfarm
	@${CAT} ${PKGMESSAGE}

# Maintainer section
create-plist:
	${ECHO_CMD} bin/%%BROWSER_NAME%% > ${PLIST}
	${ECHO_CMD} share/applications/%%BROWSER_NAME%%.desktop >> ${PLIST}
	cd ${WRKDIR} && ${FIND} ${PORTNAME} -type f -or -type l | \
		${SED} -e "s#^${PORTNAME}#lib/%%BROWSER_NAME%%#" | ${SORT} >> ${PLIST}
	${ECHO_CMD} lib/%%BROWSER_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @exec %%PREFIX%%/lib/%%BROWSER_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @unexec ${FIND} %%PREFIX%%/lib/%%BROWSER_NAME%%/plugins \
		-type l -delete >> ${PLIST}
	cd ${WRKDIR} && ${FIND} -d ${PORTNAME} -type d | \
		${SED} -e "s#^${PORTNAME}#@dirrm lib/%%BROWSER_NAME%%#" >> ${PLIST}
	${ECHO_CMD} @dirrmtry share/applications >> ${PLIST}

.include <bsd.port.post.mk>

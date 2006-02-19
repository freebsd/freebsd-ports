# New ports collection makefile for:   linux-firefox
# Date created:                                2004-09-17
# Whom:                                        voisine
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.5
PORTREVISION=	2
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
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
FIREFOX_NAME=	${PKGNAMEPREFIX}${PORTNAME}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
FDIR=		${PREFIX}/lib/${FIREFOX_NAME}

PLIST_SUB+=	FIREFOX_NAME=${FIREFOX_NAME}
SUB_LIST+=	FIREFOX_NAME=${FIREFOX_NAME}
SUB_FILES=	linkfarm pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${INSTALL} -d ${FDIR}
	${CP} -R ${WRKSRC}/ ${FDIR}
	${LN} -sf ${FDIR}/firefox ${PREFIX}/bin/${FIREFOX_NAME}
	${LN} -sf ${FDIR}/firefox-bin ${FDIR}/${FIREFOX_NAME}-bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${FDIR}

post-install:
	@${SH} ${FDIR}/linkfarm
	@${CAT} ${PKGMESSAGE}

# Maintainer section
create-plist:
	${ECHO_CMD} bin/%%FIREFOX_NAME%% > ${PLIST}
	${ECHO_CMD} lib/%%FIREFOX_NAME%%/%%FIREFOX_NAME%%-bin >> ${PLIST}
	cd ${WRKDIR} && ${FIND} ${PORTNAME} -type f -or -type l | \
		${SED} -e "s#^${PORTNAME}#lib/%%FIREFOX_NAME%%#" | ${SORT} >> ${PLIST}
	${ECHO_CMD} lib/%%FIREFOX_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @exec %%PREFIX%%/lib/%%FIREFOX_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @unexec ${FIND} %%PREFIX%%/lib/%%FIREFOX_NAME%%/plugins \
		-type l -delete >> ${PLIST}
	cd ${WRKDIR} && ${FIND} -d ${PORTNAME} -type d | \
		${SED} -e "s#^${PORTNAME}#@dirrm lib/%%FIREFOX_NAME%%#" >> ${PLIST}

.include <bsd.port.mk>

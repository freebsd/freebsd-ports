# New ports collection makefile for:   linux-seamonkey
# Date created:		1 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	seamonkey
PORTVERSION=	1.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION}
PKGNAMEPREFIX=		linux-

MAINTAINER=	infofarmer@gmail.com
COMMENT=	The open source, standards compliant web browser

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
		${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
BROWSER_NAME=	${PKGNAMEPREFIX}${PORTNAME}
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
FDIR=		${PREFIX}/lib/${BROWSER_NAME}

PLIST_SUB+=	BROWSER_NAME=${BROWSER_NAME}
SUB_LIST+=	BROWSER_NAME=${BROWSER_NAME}
SUB_FILES=	linkfarm pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${INSTALL} -d ${FDIR}
	${CP} -pR ${WRKSRC}/ ${FDIR}/
	${LN} -sf ${FDIR}/${PORTNAME} ${PREFIX}/bin/${BROWSER_NAME}
	${LN} -sf ${FDIR}/${PORTNAME}-bin ${FDIR}/${BROWSER_NAME}-bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${FDIR}/

post-install:
	@${SH} ${FDIR}/linkfarm
	@${CAT} ${PKGMESSAGE}

# Maintainer section
create-plist:
	${ECHO_CMD} bin/%%BROWSER_NAME%% > ${PLIST}
	${ECHO_CMD} lib/%%BROWSER_NAME%%/%%BROWSER_NAME%%-bin >> ${PLIST}
	cd ${WRKDIR} && ${FIND} ${PORTNAME} -type f -or -type l | \
		${SED} -e "s#^${PORTNAME}#lib/%%BROWSER_NAME%%#" | ${SORT} >> ${PLIST}
	${ECHO_CMD} lib/%%BROWSER_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @exec %%PREFIX%%/lib/%%BROWSER_NAME%%/linkfarm >> ${PLIST}
	${ECHO_CMD} @unexec ${FIND} %%PREFIX%%/lib/%%BROWSER_NAME%%/plugins \
		-type l -delete >> ${PLIST}
	cd ${WRKDIR} && ${FIND} -d ${PORTNAME} -type d | \
		${SED} -e "s#^${PORTNAME}#@dirrm lib/%%BROWSER_NAME%%#" >> ${PLIST}

.include <bsd.port.mk>

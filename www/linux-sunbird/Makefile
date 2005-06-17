# New ports collection makefile for:   linux-sunbird
# Date created:                                2004-09-17
# Whom:                                        voisine
#
# $FreeBSD$
#

PORTNAME=      sunbird
PORTVERSION=   0.2
PORTREVISION=  1
CATEGORIES?=   www linux
MASTER_SITES=  ${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR?=calendar/sunbird/releases/${PORTVERSION}
PKGNAMEPREFIX?=linux-
DISTNAME?=     sunbird-${PORTVERSION}-i686-linux-gtk2+xft

MAINTAINER=    voisine@gmail.com
COMMENT=       Calendaring application branched from Mozilla

RUN_DEPENDS?=  \
${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

NO_BUILD=      yes
ONLY_FOR_ARCHS=i386
SUNBIRD_NAME=  ${PKGNAMEPREFIX}${PORTNAME}
DESCR=         ${.CURDIR}/pkg-descr
MD5_FILE=      ${.CURDIR}/distinfo
PLIST=         ${WRKDIR}/pkg-plist
USE_LINUX=     yes
USE_X_PREFIX=  yes
WRKSRC=        ${WRKDIR}/sunbird

pre-install:
	${ECHO_CMD} bin/${SUNBIRD_NAME} > ${PLIST}
	${ECHO_CMD} lib/${SUNBIRD_NAME}/${SUNBIRD_NAME}-bin >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${SUNBIRD_NAME}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/${SUNBIRD_NAME}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${SUNBIRD_NAME} >> ${PLIST}

# XXX: This is missing a "${BRANDELF\ -t Linux <executables>".

do-install:
	${MKDIR} ${PREFIX}/lib/${SUNBIRD_NAME}
	${CHMOD} 755 ${PREFIX}/lib/${SUNBIRD_NAME}
	cd ${WRKSRC} && ${FIND} * | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/lib/${SUNBIRD_NAME}
	${LN} -sf ${PREFIX}/lib/${SUNBIRD_NAME}/sunbird \
		${PREFIX}/bin/${SUNBIRD_NAME}
	${LN} -sf ${PREFIX}/lib/${SUNBIRD_NAME}/sunbird-bin \
		${PREFIX}/lib/${SUNBIRD_NAME}/${SUNBIRD_NAME}-bin

.include <bsd.port.mk>

# New ports collection makefile for:   linux-firefox
# Date created:                                2004-09-17
# Whom:                                        voisine
#
# $FreeBSD$
#

PORTNAME=      firefox
PORTVERSION=   1.0
CATEGORIES?=   www linux
MASTER_SITES=  ${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR?=firefox/releases/${PORTVERSION}/linux-i686/en-US
PKGNAMEPREFIX?=linux-
DISTNAME?=     firefox-${PORTVERSION}

MAINTAINER=    voisine@gmail.com
COMMENT=       Web browser branched from Mozilla

RUN_DEPENDS?=  \
${LINUXBASE}/usr/lib/libstdc++.so.5:${PORTSDIR}/emulators/linux_base-8 \
${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
${LINUXBASE}/usr/lib/libpangoxft-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango\
${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
${LINUXBASE}${X11BASE}/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

NO_BUILD=      yes
NO_FILTER_SHLIBS=yes
ONLY_FOR_ARCHS=i386 amd64
FIREFOX_NAME=  ${PKGNAMEPREFIX}${PORTNAME}
DESCR=         ${.CURDIR}/pkg-descr
MD5_FILE=      ${.CURDIR}/distinfo
PKGMESSAGE=    ${WRKDIR}/pkg-message
PLIST=         ${WRKDIR}/pkg-plist
USE_LINUX=     yes
USE_XLIB=      yes
USE_X_PREFIX=  yes
WRKSRC=        ${WRKDIR}/firefox

do-patch:
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/linkfarm
	${ECHO_CMD} \
	"# Run this after installing Beonex, Mozilla or Netscape plugins." \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/${FIREFOX_NAME}/plugins" \
		>>${WRKDIR}/linkfarm
.for ii in \
	lib/linux-beonex/plugins \
	lib/netscape-linux/plugins \
	lib/flash \
	lib/linux-mozilla/plugins \
	lib/linux-netscape*/plugins \
	lib/linux-flashplugin6 \
	linux-blackdown-jdk1.3.1/jre/plugin/i386/mozilla \
	linux-blackdown-jdk1.4.1/jre/plugin/i386/mozilla
	${ECHO_CMD} -n "${FIND} ${LOCALBASE}/${ii}/*" \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
		>>${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/${FIREFOX_NAME} > ${PLIST}
	${ECHO_CMD} lib/${FIREFOX_NAME}/${FIREFOX_NAME}-bin >> ${PLIST}
	${ECHO_CMD} \
		"@unexec ${FIND} ${PREFIX}/lib/${FIREFOX_NAME}/plugins \
		-type l -exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${FIREFOX_NAME}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/${FIREFOX_NAME}/:' >> ${PLIST}
	${ECHO_CMD} lib/${FIREFOX_NAME}/linkfarm >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${FIREFOX_NAME} >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/${FIREFOX_NAME}/linkfarm" \
		>> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${FIREFOX_NAME}
	${CHMOD} 755 ${PREFIX}/lib/${FIREFOX_NAME}
	cd ${WRKSRC} && ${FIND} * | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/lib/${FIREFOX_NAME}
	${LN} -sf ${PREFIX}/lib/${FIREFOX_NAME}/firefox \
		${PREFIX}/bin/${FIREFOX_NAME}
	${LN} -sf ${PREFIX}/lib/${FIREFOX_NAME}/firefox-bin \
		${PREFIX}/lib/${FIREFOX_NAME}/${FIREFOX_NAME}-bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm \
	${PREFIX}/lib/${FIREFOX_NAME}

post-install:
	@${ECHO_CMD} \*\* After adding plugins to \(Linux\) Beonex,
	@${ECHO_CMD} \*\* Mozilla or Netscape, run\
		> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* ${PREFIX}/lib/${FIREFOX_NAME}/linkfarm as root \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* to make them available to ${FIREFOX_NAME}. \
		>> ${PKGMESSAGE}
	@- ${SH} ${PREFIX}/lib/${FIREFOX_NAME}/linkfarm || true
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

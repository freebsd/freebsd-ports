# New ports collection makefile for:	linux-mozillafirebird
# Date created:				2003-06-03
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mozillafirebird
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES?=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR?=	firebird/releases/${PORTVERSION}
PKGNAMEPREFIX?=	linux-
DISTNAME?=	MozillaFirebird-${PORTVERSION}-i686-pc-linux-gnu

MAINTAINER=	voisine@yahoo.com
COMMENT?=	Web browser branched from Mozilla

RUN_DEPENDS?=	\
	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

BROKEN=		Incorrect pkg-plist

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes
ONLY_FOR_ARCHS=	i386
FIREBIRD_NAME=	${PKGNAMEPREFIX}${PORTNAME}
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
PREFIX?=	${X11BASE}
WRKSRC=		${WRKDIR}/MozillaFirebird

do-patch:
	${ECHO_CMD} "#!/bin/sh"		> ${WRKDIR}/linkfarm
	${ECHO_CMD} \
	"# Run this after installing Beonex, Mozilla or Netscape plugins." \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/${FIREBIRD_NAME}/plugins" \
		>>${WRKDIR}/linkfarm
.for ii in lib/linux-beonex/plugins lib/netscape-linux/plugins lib/flash \
	lib/linux-mozilla/plugins lib/linux-netscape*/plugins \
	lib/linux-flashplugin6 \
linux-blackdown-jdk1.3.1/jre/plugin/i386/mozilla \
linux-blackdown-jdk1.4.1/jre/plugin/i386/mozilla
		${ECHO_CMD} -n "${FIND} ${LOCALBASE}/${ii}/*" \
			>>${WRKDIR}/linkfarm
		${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
			>>${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/${FIREBIRD_NAME} > ${PLIST}
	${ECHO_CMD} \
		"@unexec ${FIND} ${PREFIX}/lib/${FIREBIRD_NAME}/plugins \
		-type l -exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${FIREBIRD_NAME}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/${FIREBIRD_NAME}/:' >> ${PLIST}
	${ECHO_CMD} lib/${FIREBIRD_NAME}/linkfarm >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${FIREBIRD_NAME} >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/${FIREBIRD_NAME}/linkfarm" \
		>> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${FIREBIRD_NAME}
	${CHMOD} 755 ${PREFIX}/lib/${FIREBIRD_NAME}
	cd ${WRKSRC} && ${FIND} * | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/lib/${FIREBIRD_NAME}
	${LN} -sf ${PREFIX}/lib/${FIREBIRD_NAME}/MozillaFirebird \
		${PREFIX}/bin/${FIREBIRD_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm \
		${PREFIX}/lib/${FIREBIRD_NAME}

NEW_LIBSTDCXX=	${LINUXBASE}/usr/lib/libstdc++-libc6.2-2.so.3
OLD_LIBSTDCXX=	libstdc++-libc6.1-1.so.2

post-install:
	if [ ! -e ${NEW_LIBSTDCXX} ]; then \
		${LN} -s ${OLD_LIBSTDCXX} ${NEW_LIBSTDCXX}; \
	fi
	${ECHO_CMD} "@exec if [ ! -e ${NEW_LIBSTDCXX} ]; then ${LN} -s ${OLD_LIBSTDCXX} ${NEW_LIBSTDCXX}; fi" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec if [ -L ${NEW_LIBSTDCXX} ]; then ${RM} -f ${NEW_LIBSTDCXX}; fi" >> ${TMPPLIST}
	@${ECHO_CMD} \*\* After adding plugins to \(Linux\) Beonex,
	@${ECHO_CMD} \*\* Mozilla or Netscape, run\
		> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* ${PREFIX}/lib/${FIREBIRD_NAME}/linkfarm as root \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* to make them available to ${FIREBIRD_NAME}. \
		>> ${PKGMESSAGE}
	@- ${SH} ${PREFIX}/lib/${FIREBIRD_NAME}/linkfarm || true
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

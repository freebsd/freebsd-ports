# New ports collection makefile for:	linux-mozilla-devel
# Date created:				2003-05-23
# Whom:					trevor
# based on ports/www/linux-mozilla
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.8a5
PORTREVISION=	2
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/mozilla${PORTVERSION}/linux-xpi

PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	linux-mozilla/${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=Browser, HTML editor, MUA, news, and IRC client for Linux (unstable)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

FORBIDDEN=	"multiple suspected security bugs"

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=	${WRKDIR}/xpi
INSTALL_DIR=	linux-mozilla-devel
FULL_INSTALL_DIR=	${PREFIX}/lib/linux-mozilla-devel
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	linux-mozilla-devel

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

pre-everything::
	${MKDIR} ${WRKSRC}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
.endif
DISTFILES=	browser.xpi \
		chatzilla.xpi \
		deflenus.xpi \
		inspector.xpi \
		langenus.xpi \
		mail.xpi \
		psm.xpi \
		regus.xpi \
		spellcheck.xpi \
		venkman.xpi \
		xpcom.xpi
.if exists(${WRKDIRPREFIX}${.CURDIR}/work/xpi/components.conf)
DISTFILES!=	${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/xpi/components.conf
.endif

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
	${CHMOD} -R o-w ${WRKSRC}
.endfor

do-configure:
	${ECHO_CMD} "#!/bin/sh"		>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} -n "cd "		>>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} ${FULL_INSTALL_DIR}		>>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} 'exec ./mozilla $$@'	>>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} "#!/bin/sh"					>${WRKDIR}/linkfarm
	${ECHO_CMD} "# Run this after installing Netscape plugins."	>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-mozilla-devel/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../netscape-linux/plugins/*"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-mozilla/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-flashplugin6"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-netscape*/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-beonex/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm

do-build:
	${BRANDELF} -t ${WRKSRC}/bin/mozilla

pre-install:
	${ECHO_CMD} bin/${STARTUP_CMD} > ${PLIST}
	${ECHO_CMD} "@unexec ${FIND} ${FULL_INSTALL_DIR}/plugins \
		-type l -exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC}/bin; for i in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} lib/${INSTALL_DIR}/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm lib/${INSTALL_DIR}/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} lib/${INSTALL_DIR}/linkfarm >> ${PLIST}
	${ECHO_CMD} "@exec ${FULL_INSTALL_DIR}/linkfarm" >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${INSTALL_DIR} >> ${PLIST}

do-install:
	${MKDIR} ${FULL_INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${FULL_INSTALL_DIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${FULL_INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${FULL_INSTALL_DIR}/

post-install:
	${SED} -e 's:PREFIX:${PREFIX}:g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	- ${FULL_INSTALL_DIR}/linkfarm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

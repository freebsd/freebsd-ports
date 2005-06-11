# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
# based on ports/www/linux-netscape6
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.7.8
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/mozilla${PORTVERSION}/linux-xpi

PKGNAMEPREFIX=	linux-
DIST_SUBDIR=	linux-mozilla/${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=Browser, HTML editor, MUA and newsreader for use with Linux plugins

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
PREFIX?=	${X11BASE}
USE_ZIP=	yes
WRKSRC=	${WRKDIR}/xpi
INSTALL_DIR=	${PREFIX}/lib/linux-mozilla
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	linux-mozilla

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
	${ECHO_CMD} ${INSTALL_DIR}		>>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} 'exec ./mozilla $$@'	>>${WRKDIR}/${STARTUP_CMD}
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/linkfarm
	${ECHO_CMD} "# Run this after installing Netscape plugins." \
		>> ${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-mozilla/plugins" \
		>> ${WRKDIR}/linkfarm

.for ii in lib/linux-beonex/plugins lib/netscape-linux/plugins lib/flash \
	lib/linux-mozilla/plugins lib/linux-netscape*/plugins \
	lib/linux-flashplugin6 \
	linux-blackdown-jdk1.3.1/jre/plugin/i386/mozilla \
	linux-blackdown-jdk1.4.1/jre/plugin/i386/mozilla
	${ECHO_CMD} -n "${FIND} ${LOCALBASE}/${ii}/*" \
		>> ${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
		>> ${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/${STARTUP_CMD} > ${PLIST}
	${ECHO_CMD} "@unexec ${FIND} ${PREFIX}/lib/linux-mozilla/plugins -type l \
		-exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC}/bin; for i in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} lib/linux-mozilla/linkfarm >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/linux-mozilla/linkfarm" >> ${PLIST}
	${ECHO_CMD} @dirrm lib/linux-mozilla >> ${PLIST}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${INSTALL_DIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${PREFIX}/lib/linux-mozilla/

post-install:
	${SED} -e 's:PREFIX:${PREFIX}:g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	- ${PREFIX}/lib/linux-mozilla/linkfarm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

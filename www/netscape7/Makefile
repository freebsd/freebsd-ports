# New ports collection makefile for:		netscape7
# Date created:					2002-05-22
# Whom:						trevor
# based on the www/linux-netscape6 port by sada and others
#
# $FreeBSD$
#

PORTNAME=	netscape7
PORTVERSION?=	7.2
PORTREVISION?=	1
CATEGORIES?=	www linux
MASTER_SITES=	${MASTER_SITE_NETSCAPE}
DIST_SUBDIR=	${MAJ}/${NETSCAPE_LANG}/${VER}
MASTER_SITE_SUBDIR?=${DIST_SUBDIR}/unix/linux/bfkprv
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	${PKGNAMEPREFIX}${MAJ}-${VER}-generated-files.tar.bz2

MAINTAINER?=	trevor@FreeBSD.org
COMMENT=	Linux Netscape suite

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

BROKEN=		Incomplete distinfo file

LATEST_LINK=	linux-${MAJ}
MAJ?=		netscape7
NETSCAPE_LANG?=english
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"no redistribution"
NO_CDROM=	${RESTRICTED}
PREFIX?=	${X11BASE}
USE_ZIP=	yes
VER?=		${PORTVERSION}
WRKSRC=	${WRKDIR}/netscape-installer/xpi
INSTALL_DIR=	lib/linux-${MAJ}-${NETSCAPE_LANG}
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	${WRKDIR}/${MAJ}${NETSCAPE_LANG}

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

pre-everything::
	${MKDIR} ${WRKSRC}/bin/plugins ${WRKSRC}/bin/chrome \
		${WRKSRC}/plugins
.if !exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
.endif
DISTFILES?=	browser.xpi \
		deflenus.xpi \
		flash.xpi \
		inspector.xpi \
		langenus.xpi \
		mail.xpi \
		psm.xpi \
		regus.xpi \
		spellchecker.xpi \
		talkback.xpi \
		venkman.xpi \
		xpcom.xpi

.if exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
DISTFILES!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf
.endif

do-extract:
.for ii in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
	${CHMOD} -R go-w ${WRKDIR}
.endfor

do-patch:
	${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} | \
		${TAR} -C ${WRKSRC}/bin -xf -

do-configure:
#	- kldload linux
#	${SETENV} $DISPLAY="NONE" ${WRKSRC}/bin/netscape file:///dev/null
#	@${ECHO} \"Factory not found\" and \"cannot open display\" errors here are normal.
	${ECHO_CMD}	"#!/bin/sh"		>  ${STARTUP_CMD}
	${ECHO_CMD} -n	"cd "			>> ${STARTUP_CMD}
	${ECHO_CMD}	${PREFIX}/${INSTALL_DIR}		>> ${STARTUP_CMD}
	${ECHO_CMD}	'exec ./netscape $$*'	>> ${STARTUP_CMD}

pre-install:
	${ECHO_CMD} bin/${MAJ}${NETSCAPE_LANG} > ${PLIST}
	cd ${WRKSRC}/bin; for ii in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} ${INSTALL_DIR}/$${ii} >> ${PLIST}; \
	done
	cd ${WRKSRC}/plugins; for ii in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} ${INSTALL_DIR}/plugins/$${ii} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for ii in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm ${INSTALL_DIR}/$${ii} >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm ${INSTALL_DIR} >> ${PLIST}

pre-package:
	@${ECHO_MSG} "*** WARNING ***"
	@${ECHO_MSG} "* Do not distribute packages outside your organization."
	@${ECHO_MSG} "* It is prohibited by the licensing."

do-install:
	${MKDIR} ${PREFIX}/${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${WRKSRC}/plugins ${PREFIX}/${INSTALL_DIR}
	${INSTALL_SCRIPT} ${STARTUP_CMD} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

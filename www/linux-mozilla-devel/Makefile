# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
# based on ports/www/linux-netscape6
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.7
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/mozilla${PORTVERSION}/linux-xpi/
PKGNAMEPREFIX=	linux-
DISTFILES=	browser.xpi \
		chatzilla.xpi \
		deflenus.xpi \
		langenus.xpi \
		mail.xpi \
		psm.xpi \
		regus.xpi \
		talkback.xpi \
		venkman.xpi \
		xpcom.xpi
DIST_SUBDIR=	linux-mozilla/${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-mozilla-${PORTVERSION}-generated-files.tar.gz

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUX_BASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libgtk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk

LINUX_BASE=	/compat/linux
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
WRKSRC=	${WRKDIR}/xpi
INSTALL_DIR=	${PREFIX}/lib/linux-mozilla
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	linux-mozilla

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
.endfor

do-patch:
	${TAR} -C ${WRKSRC}/bin -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}

do-configure:
#	- kldload linux
#	${SETENV} $DISPLAY="NONE" ${WRKSRC}/bin/mozilla file:///dev/null
	${ECHO} "#!/bin/sh"		>${WRKDIR}/${STARTUP_CMD}
	${ECHO} -n "cd "		>>${WRKDIR}/${STARTUP_CMD}
	${ECHO} ${INSTALL_DIR}		>>${WRKDIR}/${STARTUP_CMD}
	${ECHO} "exec ./mozilla"	>>${WRKDIR}/${STARTUP_CMD}

pre-install:
	${ECHO} bin/${STARTUP_CMD} > ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO} lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	${ECHO} lib/linux-mozilla/plugins/libflashplayer.so >> ${PLIST}
	${ECHO} lib/linux-mozilla/plugins/ShockwaveFlash.class >> ${PLIST}
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO} @dirrm lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm lib/linux-mozilla >> ${PLIST}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${INSTALL_DIR}
# These links are broken if the linux-flashplugin package is not installed.
	cd ${PREFIX}/lib/linux-mozilla/plugins \
	&& ${LN} -s ../../netscape-linux/plugins/libflashplayer.so \
	&& ${LN} -s ../../netscape-linux/plugins/ShockwaveFlash.class
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
# based on ports/www/linux-netscape6
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.7
PORTREVISION=	1
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
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
USE_LINUX=	yes
WRKSRC=	${WRKDIR}/xpi
INSTALL_DIR=	${PREFIX}/lib/linux-mozilla
PKGMESSAGE=	${WRKDIR}/pkg-message
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
	${ECHO} "#!/bin/sh"					>${WRKDIR}/linkfarm
	${ECHO} "# Run this after installing Netscape plugins."	>>${WRKDIR}/linkfarm
	${ECHO} "cd ${PREFIX}/lib/linux-mozilla/plugins"	>>${WRKDIR}/linkfarm
	${ECHO} -n "${FIND} ../../netscape-linux/plugins/*"	>>${WRKDIR}/linkfarm
	${ECHO} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO} -n "${FIND} ../../linux-netscape6/plugins"	>>${WRKDIR}/linkfarm
	${ECHO} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm

pre-install:
	${ECHO} bin/${STARTUP_CMD} > ${PLIST}
	${ECHO} "@unexec ${FIND} ${PREFIX}/lib/linux-mozilla/plugins -type l \
		-exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO} lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO} @dirrm lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	${ECHO} lib/linux-mozilla/linkfarm >> ${PLIST}
	${ECHO} "@exec ${PREFIX}/lib/linux-mozilla/linkfarm" >> ${PLIST}
	${ECHO} @dirrm lib/linux-mozilla >> ${PLIST}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${PREFIX}/lib/linux-mozilla/

post-install:
	${SED} -e 's:PREFIX:${PREFIX}:g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	- ${PREFIX}/lib/linux-mozilla/linkfarm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

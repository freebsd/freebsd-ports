# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
# based on ports/www/linux-netscape6
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.5
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/mozilla${PORTVERSION}/linux-xpi

FORBIDDEN=	"http://vuxml.freebsd.org/c1d97a8b-05ed-11d9-b45d-000c41e2cdad.html (security)"

PKGNAMEPREFIX=	linux-
DIST_SUBDIR=	linux-mozilla/${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-mozilla-${PORTVERSION}-generated-files.tar.bz2

MAINTAINER=	trevor@FreeBSD.org
COMMENT=Browser, HTML editor, MUA and newsreader for use with Linux plugins

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
USE_ZIP=	yes
USE_LINUX=	yes
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
		deflenus.xpi \
		inspector.xpi \
		langenus.xpi \
		mail.xpi \
		psm.xpi \
		regus.xpi \
		talkback.xpi \
		venkman.xpi \
		xpcom.xpi
.if exists(${WRKDIRPREFIX}${.CURDIR}/work/xpi/components.conf)
DISTFILES!=	${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/xpi/components.conf
.endif

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
.endfor

do-patch:
	${MKDIR} ${WRKSRC}/tmp
	${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} | \
		${TAR} -C ${WRKSRC}/bin -xf -
	${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} | \
		${TAR} -C ${WRKSRC}/tmp -xf -
	for j in chatzilla cookie inspector messenger pippki venkman; do \
		if [ ! -e ${WRKSRC}/bin/chrome/$$j.jar ]; then \
			for i in communicator editor messenger navigator; do \
				${GREP} -v $$j ${WRKSRC}/tmp/chrome/overlayinfo/$$i/content/overlays.rdf > \
					${WRKSRC}/bin/chrome/overlayinfo/$$i/content/overlays.rdf; \
				${CP} ${WRKSRC}/bin/chrome/overlayinfo/$$i/content/overlays.rdf \
					${WRKSRC}/tmp/chrome/overlayinfo/$$i/content/overlays.rdf; \
			done; \
			${RM} -f ${WRKSRC}/bin/chrome/overlayinfo/$$j/content/overlays.rdf; \
		fi; \
	done;

do-configure:
#	- kldload linux
#	${SETENV} $DISPLAY="NONE" ${WRKSRC}/bin/mozilla file:///dev/null
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
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${PREFIX}/lib/linux-mozilla/

post-install:
	${SED} -e 's:PREFIX:${PREFIX}:g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	- ${PREFIX}/lib/linux-mozilla/linkfarm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

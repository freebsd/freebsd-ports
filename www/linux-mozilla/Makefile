# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
# based on ports/www/linux-netscape6
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.2
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	mozilla/releases/mozilla${PORTVERSION}b/linux-xpi

PKGNAMEPREFIX=	linux-
DIST_SUBDIR=	linux-mozilla/${PORTVERSION}b

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-mozilla-${PORTVERSION}b-generated-files.tar.gz

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

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

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

pre-everything::
	${MKDIR} ${WRKSRC}
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
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

checksum:
.if !defined(REAL_EXTRACT)
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch
.endif
	@if [ ! -f ${MD5_FILE} ]; then \
		${ECHO_MSG} ">> No MD5 checksum file."; \
	else \
		(cd ${DISTDIR}; OK="true"; \
		  for file in ${_CKSUMFILES}; do \
			if [ -r $$file ]; then \
				CKSUM=`${MD5} < $$file`; \
				CKSUM2=`${GREP} "^MD5 ($$file)" ${MD5_FILE} | ${AWK} '{print $$4}'`; \
				if [ "$$CKSUM2" = "" ]; then \
					${ECHO_MSG} ">> No checksum recorded for $$file."; \
					OK="false"; \
				elif ${EXPR} "$$CKSUM2" : ".*$$CKSUM" > /dev/null; then \
					${ECHO_MSG} ">> Checksum OK for $$file."; \
			else \
					${ECHO_MSG} ">> Checksum mismatch for $$file."; \
					OK="false"; \
				fi; \
			fi; \
		  done; \
		  if [ "$$OK" != "true" ]; then \
			${ECHO_MSG} "Make sure the Makefile and distinfo file (${MD5_FILE})"; \
			${ECHO_MSG} "are up to date.  If you are absolutely sure you want to override this"; \
			${ECHO_MSG} "check, type \"make NO_CHECKSUM=yes [other args]\"."; \
			exit 1; \
		  fi) ; \
	fi

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
.endfor

do-patch:
	${MKDIR} ${WRKSRC}/tmp
	${TAR} -C ${WRKSRC}/tmp -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}
	${TAR} -C ${WRKSRC}/bin -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}
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
	${ECHO_CMD} "#!/bin/sh"					>${WRKDIR}/linkfarm
	${ECHO_CMD} "# Run this after installing Netscape plugins."	>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-mozilla/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../netscape-linux/plugins/*"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-netscape*/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} -n "${FIND} ../../linux-beonex/plugins"	>>${WRKDIR}/linkfarm
	${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null"	>>${WRKDIR}/linkfarm

pre-install:
	${ECHO_CMD} bin/${STARTUP_CMD} > ${PLIST}
	${ECHO_CMD} "@unexec ${FIND} ${PREFIX}/lib/linux-mozilla/plugins -type l \
		-exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO_CMD} lib/linux-mozilla/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
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

# New ports collection makefile for:		netscape7
# Date created:					2002-05-22
# Whom:						trevor
# based on www/linux-netscape6 port by sada and others
#
# $FreeBSD$
#

PORTNAME=	netscape7
PORTVERSION=	7.0
CATEGORIES?=	www linux
MASTER_SITES=	${MASTER_SITE_NETSCAPE}
DIST_SUBDIR=	${MAJ}/${NETSCAPE_LANG}/${VER}
MASTER_SITE_SUBDIR?=${DIST_SUBDIR}/unix/linux22/ewc9e

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	${PKGNAMEPREFIX}linux-${MAJ}-${VER}-generated-files.tar.gz

MAINTAINER?=	trevor@FreeBSD.org

FORBIDDEN=	"security bug--see <URL:http://wp.netscape.com/eng/mozilla/ns7/relnotes/7.html\#psm> and <URL:http://www.xwt.org/sop.txt>"

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

LATEST_LINK=	linux-${MAJ}
MAJ?=		netscape7
NETSCAPE_LANG?=english
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License for Java plugin allows internal use only.  Also see license for Netscape itself"
NO_CDROM=	${RESTRICTED}
USE_LINUX=	yes
USE_XLIB=	yes
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
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
DISTFILES?=	browser.xpi \
		deflenus.xpi \
		flash.xpi \
		jre.xpi \
		langenus.xpi \
		mail.xpi \
		psm.xpi \
		regca.xpi \
		regus.xpi \
		spellchecker.xpi \
		talkback.xpi \
		xpcom.xpi
.if exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
DISTFILES!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf
.endif

XXXchecksum:
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
.for ii in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
.endfor
	- ${MV} ${WRKSRC}/jre-image-i386 ${WRKSRC}/bin/plugins/java2
	- ${MV} ${WRKSRC}/jre1.3.1_02 ${WRKSRC}/bin/plugins/java2
	cd ${WRKSRC}/bin/plugins && ${LN} -s java2/plugin/i386/ns600/libjavaplugin_oji.so;

do-patch:
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/bin/chrome/user-skins.rdf ${WRKSRC}/bin/chrome/user-locales.rdf
	${CP} -p ${FILESDIR}/*rdf ${WRKSRC}/bin/chrome
	${TAR} -C ${WRKSRC}/bin -xzf ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES}

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
	cd ${WRKSRC}/bin; for ii in `find * \! -type d | sort`; do \
		${ECHO_CMD} ${INSTALL_DIR}/$${ii} >> ${PLIST}; \
	done
	cd ${WRKSRC}/plugins; for ii in `find * \! -type d | sort`; do \
		${ECHO_CMD} ${INSTALL_DIR}/plugins/$${ii} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for ii in `find -d * -type d`; do \
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

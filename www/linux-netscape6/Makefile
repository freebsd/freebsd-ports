# New ports collection makefile for: netscape-linux-6
# Date created:			8 April 2000
# Whom:				sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION?=	6.2.3
PORTREVISION?=	0
CATEGORIES?=	www linux
MASTER_SITES=	\
ftp://ftp.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.cica.es/pub6/netscape/${FTPDIR}/ \
ftp://ftp.ciril.fr/pub2/netscape/${FTPDIR}/ \
ftp://ftp.cs.tu-berlin.de/pub/net/www/netscape/${FTPDIR}/ \
ftp://ftp.cuhk.edu.hk/.3/netscape/${FTPDIR}/ \
ftp://ftp.darenet.dk/mirrors/ftp2.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.dei.uc.pt/.raid0/netscape/${FTPDIR}/ \
ftp://ftp.fu-berlin.de/unix/network/www/netscape/${FTPDIR}/ \
ftp://ftp.hu-berlin.de/pub/www/netscape/${FTPDIR}/ \
ftp://ftp.informatik.uni-hamburg.de/pub/soft/infosystems/www/clients/netscape/${FTPDIR}/ \
ftp://ftp.jaist.ac.jp/net/Netscape/${FTPDIR}/ \
ftp://ftp.nsysu.edu.tw/Netscape/${FTPDIR}/ \
ftp://ftp.ruhr-uni-bochum.de/mirrors/ftp.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.sunet.se/pub/www/Netscape/${FTPDIR}/ \
ftp://ftp.uit.no/pub/www/Netscape/${FTPDIR}/ \
ftp://ftp.uni-bielefeld.de/pub/netscape/${FTPDIR}/ \
ftp://ftp.uni-c.dk/mirrors/ftp2.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.netscape.com/${FTPDIR}/ \
ftp://ftp.uniovi.es/pub/netscape/${FTPDIR}/ \
ftp://ftp.unipi.it/pub/mirror/netscape/${FTPDIR}/ \
ftp://ftp.uniroma2.it/%7bC/Netscape/${FTPDIR}/ \
ftp://ftp.ut.ee/pub/WWW/netscape/${FTPDIR}/ \
ftp://sunsite.cnlab-switch.ch/mirror/netscape/${FTPDIR}/ \
ftp://sunsite.tus.ac.jp/pub/archives/WWW/netscape/${FTPDIR}/ \
ftp://ftp.mirror.ac.uk/sites/ftp.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.ntua.gr/pub/www/Netscape/${FTPDIR}/ \
ftp://ftp.fct.unl.pt/.1/Netscape/${FTPDIR}/ \
ftp://ftp.sunsite.auc.dk/disk3/netscape/${FTPDIR}/ \
ftp://ftp.skynet.be/mirror2/netscape/${FTPDIR}/ \
ftp://ftp.etse.urv.es/netscape/${FTPDIR}/ \
ftp://sunsite.tut.fi/pub/Mirror/mirrorsite.netscape.com/pub/${FTPDIR}/ \
ftp://sunfreeware.unam.mx/pub/Netscape/${FTPDIR}/ \
ftp://ftp.fh-wolfenbuettel.de/pub/www/netscape/${FTPDIR}/ \
ftp://ftp.tu-darmstadt.de/pub/networking/www/netscape/${FTPDIR}/ \
ftp://ftp.uni-bremen.de/pub/mirrors/ftp.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.netscape.com/pub/${FTPDIR}/ \
ftp://ftp.cyf-kr.edu.pl/pub/mirror/netscape/${FTPDIR}/ \
ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.netscape.com/pub/${FTPDIR}/
DIST_SUBDIR=	${MAJ}/${NETSCAPE6_LANG}/${VER}
FTPDIR?=		${DIST_SUBDIR}/unix/linux22/xpi

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-${MAJ}-${VER}-generated-files.tar.gz

MAINTAINER?=	trevor@FreeBSD.org


BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

LATEST_LINK=	linux-${MAJ}
MAJ?=		netscape6
NETSCAPE6_LANG?=english
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License for Java plugin allows internal use only.  Also see license for Netscape itself"
NO_CDROM=	${RESTRICTED}
USE_LINUX=	yes
USE_XLIB=	yes
VER?=		${PORTVERSION}
WRKSRC=	${WRKDIR}/netscape-installer/xpi
INSTALL_DIR=	lib/linux-${MAJ}-${NETSCAPE6_LANG}
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	${WRKDIR}/${MAJ}${NETSCAPE6_LANG}

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(UNFORBIDDEN)
FORBIDDEN=	"see <URL:ftp://ftp.FreeBSD.org/pub/FreeBSD/CERT/advisories/FreeBSD-SN-02:05.asc>"
.endif

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
		reges.xpi \
		reggb.xpi \
		regus.xpi \
		spellchecker.xpi \
		talkback.xpi \
		xpcom.xpi
.if exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
DISTFILES!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf
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
.for i in ${DISTFILES}
	unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${i} -d ${WRKSRC}
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
	${ECHO_CMD} bin/${MAJ}${NETSCAPE6_LANG} > ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO_CMD} ${INSTALL_DIR}/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/plugins; for i in `find * \! -type d | sort`; do \
		${ECHO_CMD} ${INSTALL_DIR}/plugins/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO_CMD} @dirrm ${INSTALL_DIR}/$${i} >> ${PLIST}; \
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

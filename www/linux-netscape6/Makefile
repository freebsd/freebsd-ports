# New ports collection makefile for: netscape-linux-6
# Date created:			8 April 2000
# Whom:				sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION=	6.2.1
PORTREVISION=	1
CATEGORIES?=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.bu.edu/pub/mirrors/ftp.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cica.es/pub6/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ciril.fr/pub2/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/www/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.cuhk.edu.hk/.3/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.darenet.dk/mirrors/ftp2.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.dei.uc.pt/.raid0/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.fh-brandenburg.de/pub/Infosystems/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.fu-berlin.de/unix/network/www/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.hu-berlin.de/pub/www/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/soft/infosystems/www/clients/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.jaist.ac.jp/net/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.kmitl.ac.th/pub/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.loxinfo.co.th/netscape/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.nsysu.edu.tw/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ruhr-uni-bochum.de/mirrors/ftp.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.spin.ad.jp/pub/WWW/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.sunet.se/pub/www/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uit.no/pub/www/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-bielefeld.de/pub/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-c.dk/mirrors/ftp2.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.netscape.com/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uni-tuebingen.de/pub/mirrors/ftp.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uniovi.es/pub/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.unipi.it/pub/mirror/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.uniroma2.it/%7bC/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.upc.es/mirror/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.upc.es/pub/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ut.ee/pub/WWW/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://sunsite.cnlab-switch.ch/mirror/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://sunsite.sut.ac.jp/pub/archives/WWW/netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.netscape.com/pub/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/ \
		ftp://ftp.ntua.gr/pub/www/Netscape/netscape6/${NETSCAPE6_LANG}/${PORTVERSION}/unix/linux22/xpi/
DIST_SUBDIR=	netscape6/${NETSCAPE6_LANG}/${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	trevor
PATCHFILES=	linux-netscape6-${PORTVERSION}-generated-files.tar.gz

MAINTAINER?=	trevor@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

LATEST_LINK=	linux-netscape6
NETSCAPE6_LANG?=english
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License for Java plugin allows internal use only.  Also see license for Netscape itself"
NO_CDROM=	${RESTRICTED}
USE_LINUX=	yes
USE_XLIB=	yes
WRKSRC=	${WRKDIR}/netscape-installer/xpi
INSTALL_DIR=	${PREFIX}/lib/linux-netscape6
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	${WRKDIR}/netscape6

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
		reges.xpi \
		reggb.xpi \
		regus.xpi \
		spellchecker.xpi \
		talkback.xpi \
		xpcom.xpi
.if exists(${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf)
DISTFILES!= ${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/netscape-installer/xpi/components.conf
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
	${ECHO_CMD}	${INSTALL_DIR}		>> ${STARTUP_CMD}
	${ECHO_CMD}	"exec ./netscape"	>> ${STARTUP_CMD}

pre-install:
	${ECHO_CMD} bin/netscape6 > ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO_CMD} lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/plugins; for i in `find * \! -type d | sort`; do \
		${ECHO_CMD} lib/linux-netscape6/plugins/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO_CMD} @dirrm lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm lib/linux-netscape6 >> ${PLIST}

pre-package:
	@${ECHO_MSG} "*** WARNING ***"
	@${ECHO_MSG} "* Do not distribute packages outside your organization."
	@${ECHO_MSG} "* It is prohibited by the licensing."

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${WRKSRC}/plugins ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${STARTUP_CMD} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

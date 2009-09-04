# New ports collection makefile for:		opera-linuxplugins
# Date created:					December 17th 2006
# Whom:						Arjan van Leeuwen <freebsd-maintainer@opera.com>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www linux
MASTER_SITES=	ftp://opera.inode.at/${MASTER_SITES_VER_PATH} \
		http://gd.tuwien.ac.at/infosys/browsers/opera/${MASTER_SITES_VER_PATH} \
		http://ftp.ucr.ac.cr/WWW/opera/${MASTER_SITES_VER_PATH} \
		http://www.microrpm.ca/pub/opera/${MASTER_SITES_VER_PATH} \
		http://www.opera.mirroarrr.de/${MASTER_SITES_VER_PATH} \
		http://opera.eurenet.net/${MASTER_SITES_VER_PATH} \
		ftp://opera.ftp.fu-berlin.de/${MASTER_SITES_VER_PATH} \
		http://ftp.ntua.gr/pub/www/Opera/${MASTER_SITES_VER_PATH} \
		ftp://ftp.wayne.edu/opera/${MASTER_SITES_VER_PATH} \
		http://mirrors.dedipower.com/opera/${MASTER_SITES_VER_PATH} \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/${MASTER_SITES_VER_PATH} \
		http://opera.nedmirror.nl/${MASTER_SITES_VER_PATH} \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/${MASTER_SITES_VER_PATH} \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/${MASTER_SITES_VER_PATH}&,} \
		ftp://ftp.opera.com/pub/opera/${MASTER_SITES_VER_PATH}
PKGNAMESUFFIX=	-linuxplugins
DISTNAME=	${PORTNAME}-${OPERA_VER}.gcc3-shared-qt3.i386

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Linux plugin support for the native Opera browser

RUN_DEPENDS=	${PREFIX}/share/opera/bin/operapluginwrapper:${PORTSDIR}/www/opera

OPERA_VER=	10.00
OPERA_MINVER=
OPERA_REL=	final
OPERA_DATE=	20090830
OPERA_BUILD=	4585
MASTER_SITES_VER_PATH=	linux/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/i386/shared/
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.gcc3-shared-qt3.i386

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes

PLIST_FILES=	share/opera/bin/operapluginwrapper.linux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/lib/opera/operapluginwrapper ${PREFIX}/share/opera/bin/operapluginwrapper.linux

.include <bsd.port.mk>

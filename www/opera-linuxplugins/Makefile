# New ports collection makefile for:		opera-linuxplugins
# Date created:					December 17th 2006
# Whom:						Arjan van Leeuwen <freebsd-maintainer@opera.com>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://opera.inode.at/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.opera.com/pub/opera/${MASTER_SITES_VER_PATH}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://opera.ftp.fu-berlin.de/${MASTER_SITES_VER_PATH}/ \
		http://ftp.ntua.gr/pub/www/Opera/${MASTER_SITES_VER_PATH}/ \
		http://mirrors.dedipower.com/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/${MASTER_SITES_VER_PATH}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/${MASTER_SITES_VER_PATH}&,}/
PKGNAMESUFFIX=	-linuxplugins
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.i386.linux

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Linux plugin support for the native Opera browser

RUN_DEPENDS=	${LOCALBASE}/lib/opera/pluginwrapper/operapluginwrapper:${PORTSDIR}/${PKGCATEGORY}/opera

OPERA_VER?=	12.01
OPERA_BUILD?=	1532
MASTER_SITES_VER_PATH=	linux/${OPERA_VER:S/.//}/

USE_XZ=		yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
EXPLICIT_PACKAGE_DEPENDS=	yes

PLIST_FILES=	lib/opera/pluginwrapper/operapluginwrapper-ia32-linux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/opera/pluginwrapper/operapluginwrapper-native \
		${PREFIX}/lib/opera/pluginwrapper/operapluginwrapper-ia32-linux

.include <bsd.port.mk>

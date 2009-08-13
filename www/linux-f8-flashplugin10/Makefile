# New ports collection makefile for:	linux-f8-flashplugin10
# Date created:				8 Apr 2009
# Whom:					Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	10.0r32
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/current/:plugin \
		http://tijl.ulyssis.be/mirror/:suplib
PKGNAMEPREFIX=	linux-f8-
DISTFILES=	install_flash_player_10_linux.tar.gz:plugin \
		linux-f8-flashsupport-9.0.1.i386.tar.gz:suplib
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_LINUX_APPS=	openssl curl libssh2 libidn nspr nss

RESTRICTED=	Redistribution not allowed
RESTRICTED_FILES=	${DISTFILES:Nlinux-f8-flashsupport*:C/:[^:]+$//}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
LATEST_LINK=	flash10

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so

CONFLICTS=	linux-flashplugin-7* linux-flashplugin-9*

post-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/libflashsupport.so ${LINUXBASE}/usr/lib

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.post.mk>

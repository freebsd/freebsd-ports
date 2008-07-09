# New ports collection makefile for:	linux-flashplugin9
# Date created:				28 May 2004
# Whom:					Jamie Jones <jamie@bishopston.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	9.0r124
PORTREVISION=	1
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/current/:plugin \
		LOCAL/lofi:suplib
PKGNAMEPREFIX=	linux-
DISTFILES=	install_flash_player_9_linux.tar.gz:plugin \
		libflashsupport.so:suplib
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	install_flash_player_9_linux.tar.gz

MAINTAINER=	jamie@bishopston.net
COMMENT=	Adobe Flash Player NPAPI Plugin

RUN_DEPENDS=	${LINUXBASE}/lib/libssl.so.5:${PORTSDIR}/security/linux-openssl

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes

BROKEN=		Unstable, no sound, generally unusable state
RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/install_flash_player_9_linux
LATEST_LINK=	flash9

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so

CONFLICTS=	linux-flashplugin-7*

post-install:
	@${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/libflashsupport.so ${LINUXBASE}/usr/lib

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.post.mk>

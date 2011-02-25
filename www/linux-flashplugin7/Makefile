# New ports collection makefile for:	linux-flashplugin7
# Date created:				28 May 2004
# Whom:					Jamie Jones <jamie@bishopston.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	7.0r73
PORTREVISION=	4
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/installers/archive/
PKGNAMEPREFIX=	linux-
DISTNAME=	install_flash_player_7_linux
DISTNAME=	fp7_archive
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_ZIP=	yes

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fp7_archive/r73/install_flash_player_7_linux

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so flashplayer.xpt

CONFLICTS=	linux-flashplugin-9*

OPTIONS=	NSPLUG "Install nspluginwrapper (for native browser use)" on

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"

.if defined (WITH_NSPLUG)
RUN_DEPENDS+=	nspluginwrapper:${PORTSDIR}/www/nspluginwrapper
.endif

post-patch:
	(cd ${WRKDIR}/fp7_archive/r73 && ${TAR} -xzf install_flash_player_7_linux_r73.tar.gz)

.include <bsd.port.post.mk>

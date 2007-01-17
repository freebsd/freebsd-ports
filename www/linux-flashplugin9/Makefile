# New ports collection makefile for:	linux-flashplugin9
# Date created:				28 May 2004
# Whom:					Jamie Jones <jamie@bishopston.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	9.0r31
PORTREVISION=	0
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/current/
PKGNAMEPREFIX=	linux-
DISTNAME=	install_flash_player_9_linux
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jamie@bishopston.net
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes

RESTRICTED=	Redistribution not allowed

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/install_flash_player_9_linux
LATEST_LINK=	flash9
PORTDOCS=	Readme.txt

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so flashplayer.xpt

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.post.mk>

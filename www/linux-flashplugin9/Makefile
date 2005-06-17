# New ports collection makefile for:	linux-flashplugin7
# Date created:				28 May 2004
# Whom:					Jamie Jones <jamie@bishopston.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	7.0r25
PORTREVISION=	2
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	install_flash_player_7_linux
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jamie@bishopston.net
COMMENT=	The official Macromedia Flash Player for Linux Mozilla and Netscape 6+

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_X_PREFIX=	yes

RESTRICTED=	"Redistribution not allowed"

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/install_flash_player_7_linux
LATEST_LINK=	flash7

LIBFILES=	libflashplayer.so flashplayer.xpt

DOCSDIR?=	${PREFIX}/share/doc/${UNIQUENAME}

do-install:
	@${MKDIR} ${PREFIX}/lib/linux-flashplugin7
.for f in ${LIBFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/linux-flashplugin7
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Readme.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>

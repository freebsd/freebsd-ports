# New ports collection makefile for:	linux-flashplugin6
# Date created:				23 February 2003
# Whom:				Brandon D. Valentine <ports@geekpunk.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	6.0r79
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	install_flash_player_6_linux
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@geekpunk.net
COMMENT=	The official Macromedia Flash Player for Linux Mozilla and Netscape 6+

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/install_flash_player_6_linux

PLUGINSDIR=	lib/linux-mozilla/plugins
LIBFILES=	libflashplayer.so flashplayer.xpt

PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

do-install:
	@${MKDIR} ${PREFIX}/lib/linux-flashplugin6
	@${MKDIR} ${PREFIX}/share/doc/linux-flashplugin6
	@${MKDIR} ${PREFIX}/${PLUGINSDIR}
.for f in ${LIBFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/linux-flashplugin6/
	@${LN} -sf ${PREFIX}/lib/linux-flashplugin6/${f} ${PREFIX}/${PLUGINSDIR}/
.endfor
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/linux-flashplugin6/
	@${INSTALL_DATA} ${WRKSRC}/readme.htm ${PREFIX}/share/doc/linux-flashplugin6/
.endif

.include <bsd.port.mk>

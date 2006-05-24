# New ports collection makefile for:	linux-flashplugin6
# Date created:				23 February 2003
# Whom:				Brandon D. Valentine <ports@brandon.dvalentine.com>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	6.0r79
PORTREVISION=	3
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	install_flash_player_6_linux
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@brandon.dvalentine.com
COMMENT=	The official Macromedia Flash Player for Linux Mozilla and Netscape 6+

FORBIDDEN=	http://vuxml.FreeBSD.org/83421018-b3ef-11da-a32d-000c6ec775d9.html
DEPRECATED=	"This port has known security flaws that are not likely to be fixed"
EXPIRATION_DATE=2006-06-07

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_X_PREFIX=	yes

RESTRICTED=	"Redistribution not allowed"

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/install_flash_player_6_linux
LATEST_LINK=	flash6

PLUGINSDIR=	lib/linux-mozilla/plugins
LIBFILES=	libflashplayer.so flashplayer.xpt

DOCSDIR?=	${PREFIX}/share/doc/${UNIQUENAME}

PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

do-install:
	@${MKDIR} ${PREFIX}/lib/linux-flashplugin6
.for f in ${LIBFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/linux-flashplugin6
.if exists(${PLUGINSDIR})
	@${LN} -sf ${PREFIX}/lib/linux-flashplugin6/${f} ${PREFIX}/${PLUGINSDIR}
.endif
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>

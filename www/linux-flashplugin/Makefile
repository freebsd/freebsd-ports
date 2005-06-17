# New ports collection makefile for:	linux-flashplugin
# Date created:		13 Feburary 2000
# Whom:			Matt Heckaman <matt@LUCIDA.QC.CA>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	5.0r51
PORTREVISION=	3
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	flash_linux
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@brandon.dvalentine.com
COMMENT=	The official Macromedia Flash Player for Linux Netscape and Opera

ONLY_FOR_ARCHS=	i386

RESTRICTED=	"Redistribution not allowed"

NO_BUILD=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/flash_linux
LATEST_LINK=	flash5

PLUGINSDIR=	lib/netscape-linux/plugins
LIBFILES=	libflashplayer.so ShockwaveFlash.class

DOCSDIR?=	${PREFIX}/share/doc/${UNIQUENAME}

PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

do-install:
	@${MKDIR} ${PREFIX}/lib/flash
.for f in ${LIBFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/flash
.if exists(${PLUGINSDIR})
	@${LN} -sf ${PREFIX}/lib/flash/${f} ${PREFIX}/${PLUGINSDIR}
.endif
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ReadMe.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	linux-flashplugin
# Date created:		13 Feburary 2000
# Whom:			Matt Heckaman <matt@LUCIDA.QC.CA>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	5.0r47
CATEGORIES=	www graphics linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	flash_linux
DIST_SUBDIR=	flashplugin/5.0r47

MAINTAINER=	pat@databits.net

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/flash_linux

PLUGINSDIR=	lib/netscape-linux/plugins
LIBFILES=	libflashplayer.so \
		ShockwaveFlash.class

PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

do-install:
	${MKDIR} ${PREFIX}/lib/flash
	${MKDIR} ${PREFIX}/share/doc/flash
	${MKDIR} ${PREFIX}/${PLUGINSDIR}
.for f in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/flash/
	${LN} -sf ${PREFIX}/lib/flash/${f} ${PREFIX}/${PLUGINSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/flash/
	${INSTALL_DATA} ${WRKSRC}/ReadMe.htm ${PREFIX}/share/doc/flash/
.include <bsd.port.mk>

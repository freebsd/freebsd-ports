# New ports collection makefile for:	linux-flashplugin
# Version required:	4.0r12
# Date created:		13 Feburary 2000
# Whom:			Matt Heckaman <matt@LUCIDA.QC.CA>
#
# $FreeBSD$
#

DISTNAME=	flash_linux
PKGNAME=	linux-flashplugin-4.0r12
CATEGORIES=	www graphics linux
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/4.0r12/

MAINTAINER=	matt@LUCIDA.QC.CA

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Linux

PLUGINSDIR=	lib/netscape-linux/plugins
LIBFILES=	libflashplayer.so \
		ShockwaveFlash.class

PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

do-install:
	${MKDIR} ${PREFIX}/lib/flash
	${MKDIR} ${PREFIX}/share/doc/flash
.for f in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/flash/
	${LN} -sf ${PREFIX}/lib/flash/${f} ${PREFIX}/${PLUGINSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.Linux ${PREFIX}/share/doc/flash/

.include <bsd.port.mk>

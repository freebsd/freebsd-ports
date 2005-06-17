# New ports collection makefile for:	flashpluginwrapper
# Date Created:				13 November 2002
# Whom:					Pete Fritchman <petef@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flashpluginwrapper
PORTVERSION=	0.20021113
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://absolutbsd.org/~petef/
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	brandon@dvalentine.com
COMMENT=	A wrapper allowing use of linux-flashplugin with native mozilla
DEPRECATED=	"Please use www/linuxpluginwrapper.  This port should be obsoleted.  But, I know many people which cannot upgrade by any reason.  So I won't remove this."

RUN_DEPENDS=	${X11BASE}/lib/flash/libflashplayer.so:${PORTSDIR}/www/linux-flashplugin

USE_XLIB=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS=	linuxpluginwrapper-*

PLIST_FILES=	lib/libflashplayer.so.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},' \
		-e 's,/usr/local,${PREFIX},' ${WRKSRC}/Makefile

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

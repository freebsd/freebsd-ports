# New ports collection makefile for: xcyrBGR
# Date created:		18 Feb 2001
# Whom:			vess /Veselin Slavov/ <vess@btc.net>
#
# $FreeBSD$
#

PORTNAME=	xcyrBGR
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	russian
MASTER_SITES=	ftp://ftp.slavof.net/pub/FreeBSD/X11/cyrillic/ \
		ftp://mail.partners-bg.org/pub/FreeBSD/X11/cyrillic/ \
		ftp://80.72.71.229/pub/FreeBSD/X11/cyrillic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bulgarian Cyrillic keyboard layout manager for X11

PLIST_FILES=	bin/xcyrBGR
USE_XORG=	x11 xpm
NO_INSTALL_MANPAGES=	yes
MAKE_ENV=	COPT="${CXXFLAGS} -fpermissive"

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcyrBGR ${PREFIX}/bin/xcyrBGR

.include <bsd.port.mk>

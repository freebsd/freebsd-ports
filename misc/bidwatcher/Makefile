# New ports collection makefile for:	bidwatcher
# Version required:	0.9.9-2
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	bidwatcher-0.9.9-2
PKGNAME=	bidwatcher-0.9.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.low-fi.com/bw/download/ \
		http://www.psn.net/~andrews/dist/
MASTER_SITE_SUBDIR=	apps/misc

MAINTAINER=	andrews@technologist.com

USE_GMAKE=	YES
USE_QT=		YES
MAKE_ENV=	QTDIR=${X11BASE}/include/X11/qt \
		SYSCONF_LFLAGS_QT=${X11BASE}/lib \
		SYSCONF_MOC=${X11BASE}/bin/moc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bidwatcher ${PREFIX}/bin/bidwatcher

.include <bsd.port.mk>

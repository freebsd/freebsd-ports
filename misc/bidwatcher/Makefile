# New ports collection makefile for:	bidwatcher
# Version required:	0.9.9-3
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	bidwatcher-0.9.9-3
PKGNAME=	bidwatcher-0.9.9.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.low-fi.com/bw/download/
MASTER_SITE_SUBDIR=	apps/misc

MAINTAINER=	andrews@technologist.com

USE_GMAKE=	YES
USE_QT=		YES
MAKE_ENV=	QTDIR=${X11BASE}/include/X11/qt \
		SYSCONF_LFLAGS_QT=${X11BASE}/lib \
		SYSCONF_MOC=${X11BASE}/bin/moc

do-install:
	@${MKDIR} ${PREFIX}/share/bidwatcher
	@${INSTALL_PROGRAM} ${WRKSRC}/bidwatcher ${PREFIX}/bin/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/bidwatcher

.include <bsd.port.mk>

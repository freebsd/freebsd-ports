# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	bidwatcher
PORTVERSION=	1.1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.midwestcs.com/bidwatcher/download/

MAINTAINER=	mph@FreeBSD.org

USE_GMAKE=	YES
USE_QT_VER=	1
MAKE_ENV=	QTDIR=${X11BASE}/include/X11/qt \
		SYSCONF_LFLAGS_QT=${X11BASE}/lib \
		SYSCONF_MOC=${X11BASE}/bin/moc
MAKEFILE=	Makefile.FreeBSD
CFLAGS+=	-DHAVE_GMTIME

do-install:
	@${MKDIR} ${PREFIX}/share/doc/bidwatcher
	@${INSTALL_PROGRAM} ${WRKSRC}/bidwatcher ${PREFIX}/bin/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/bidwatcher

.include <bsd.port.mk>

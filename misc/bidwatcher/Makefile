# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	bidwatcher
PORTVERSION=	1.0.3b
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://people.FreeBSD.org/~mph/distfiles/
MASTER_SITE_SUBDIR=	apps/misc

MAINTAINER=	will@FreeBSD.org

USE_GMAKE=	YES
USE_QT=		YES
MAKE_ENV=	QTDIR=${X11BASE}/include/X11/qt \
		SYSCONF_LFLAGS_QT=${X11BASE}/lib \
		SYSCONF_MOC=${X11BASE}/bin/moc
MAKEFILE=	Makefile.FreeBSD

do-install:
	@${MKDIR} ${PREFIX}/share/bidwatcher
	@${INSTALL_PROGRAM} ${WRKSRC}/bidwatcher ${PREFIX}/bin/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/bidwatcher
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/bidwatcher

.include <bsd.port.mk>

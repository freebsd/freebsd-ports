# New ports collection makefile for:	gaim
# Version required:		0.1
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.2 1999/04/20 02:31:21 mharo Exp $
#

DISTNAME=	gaim-19990311
PKGNAME=	gaim-0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/ \
		http://www.freebsd.org/~mharo/distfiles/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} logo.xpm.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	gaim
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-patch:
	${CP} ${DISTDIR}/logo.xpm.gz ${WRKSRC}/pixmaps
	${GUNZIP_CMD} ${WRKSRC}/pixmaps/logo.xpm.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gaim ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/gaim/pixmaps && chmod a+rx ${PREFIX}/share/gaim/pixmaps
	@ ${ECHO} "===>   Installing pixmaps"
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/gaim/pixmaps

.include <bsd.port.mk>

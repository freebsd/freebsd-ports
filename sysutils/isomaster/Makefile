# New ports collection makefile for:	isomaster
# Date created:		2006-12-11
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	isomaster
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://littlesvr.ca/isomaster/releases/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	GTK2 (bootable) CD ISO Image editor

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	gtk20 pkgconfig intlhack gnomehier
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICON=	yes
ALL_TARGET=	${PORTNAME}

MAKE_ENV=	PREFIX=${PREFIX}
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS:S/"//g} \
		-D_FILE_OFFSET_BITS=64 \
		`pkg-config --cflags gtk+-2.0`

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/isomaster.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/isomaster.png ${PREFIX}/share/pixmaps/isomaster.png

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	isomaster
# Date created:		2006-12-11
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	isomaster
PORTVERSION=	0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://littlesvr.ca/isomaster/releases/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	GTK2 (bootable) CD ISO Image editor

USE_BZIP2=	yes
USE_GNOME=	gtk20 pkgconfig intlhack gnomehier
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICON=	yes

MAKE_ENV=	PREFIX=${PREFIX}
MAKE_ARGS=	CFLAGS="${CFLAGS}"
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS:S/"//g} \
		`pkg-config --cflags gtk+-2.0` \
		-DICONPATH=\\\"${DATADIR}/icons\\\"
.if !defined(WITHOUT_NLS)
CFLAGS+=	-DLOCALEDIR=\\\"${PREFIX}/share/locale\\\"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/isomaster.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/isomaster.png ${PREFIX}/share/pixmaps/isomaster.png

.include <bsd.port.mk>

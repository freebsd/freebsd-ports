# New ports collection makefile for:	isomaster
# Date created:		2006-12-11
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	isomaster
PORTVERSION=	1.3.7
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://littlesvr.ca/isomaster/releases/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GTK2 (bootable) CD ISO Image editor

USE_BZIP2=	yes
USE_GNOME=	gtk20 pkgconfig intlhack gnomehier desktopfileutils
USE_GMAKE=	yes

MAKE_ENV=	DESKTOPPATH=${DESKTOPDIR}
MAKE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-std=c99 ${PTHREAD_CFLAGS} ${PTHREAD_LIBS:S/"//g} \
		`pkg-config --cflags gtk+-2.0` \
		-DICONPATH=\\\"${DATADIR}/icons\\\"
LDFLAGS+=	${PTHREAD_LIBS} -lcompat

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CFLAGS+=	-DLOCALEDIR=\\\"${PREFIX}/share/locale\\\" -DENABLE_NLS
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif
PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

MAN1=	isomaster.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isomaster ${PREFIX}/bin
	${MKDIR} ${DATADIR}/icons
.for i in isomaster.png go-back-kearone.png folder-new-kearone.png add2-kearone.png extract2-kearone.png delete-kearone.png
	${INSTALL_DATA} ${WRKSRC}/icons/${i} ${DATADIR}/icons
.endfor
.if !defined(WITHOUT_NLS)
.for i in ar be@latin bg ca cs da de el es et fi fo fr he hr hu id it lv nb nl nn pl pt pt_BR ro ru sk sl sq sr sr@Latn sr@latin sv tr uk zh_CN zh_TW
	test -d ${PREFIX}/share/locale/${i} || ${MKDIR} ${PREFIX}/share/locale/${i}
	test -d ${PREFIX}/share/locale/${i}/LC_MESSAGES ||  ${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.mo ${PREFIX}/share/locale/${i}/LC_MESSAGES/isomaster.mo
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/isomaster.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/isomaster.desktop ${DESKTOPDIR}

post-install:
	@-update-desktop-database

.include <bsd.port.mk>

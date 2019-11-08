# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	isomaster
PORTVERSION=	1.3.14
CATEGORIES=	sysutils
MASTER_SITES=	http://littlesvr.ca/isomaster/releases/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	GTK2 (bootable) CD ISO Image editor

LICENSE=	GPLv2

LIB_DEPENDS=	libiniparser.so:devel/iniparser \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext gmake gnome pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKE_ENV=	DEFAULT_VIEWER="xdg-open" USE_SYSTEM_INIPARSER=1

CPPFLAGS+=	-I${LOCALBASE}/include -Diniparser_setstr=iniparser_set
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e \
		's|<time.h>|<sys/time.h>|' ${WRKSRC}/bk/bkMisc.c
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@$$(CC)|$$(CC)|'

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} isomaster \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} isomaster.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
.for i in add2-kearone.png delete-kearone.png extract2-kearone.png \
	folder-new-kearone.png go-back-kearone.png isomaster.png
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DATADIR}/icons)
.endfor
.for i in ar be@latin bg bn_IN ca cs da de el es et fi fo fr gl he hr hu \
	id it ja lt lv nb nl nn pl pt pt_BR ro ru sk sl sq sr sr@Latn \
	sr@latin sv tr uk ur_PK zh_CN zh_TW
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/isomaster.mo)
.endfor
	${INSTALL_DATA} ${WRKSRC}/isomaster.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>

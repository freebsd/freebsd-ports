# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	isomaster
PORTVERSION=	1.3.9
CATEGORIES=	sysutils
MASTER_SITES=	http://littlesvr.ca/isomaster/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 (bootable) CD ISO Image editor

LICENSE=	GPLv2

LIB_DEPENDS=	iniparser:${PORTSDIR}/devel/iniparser
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GNOME=	intlhack gnomehier gtk20
USES=		desktop-file-utils gettext
USE_GMAKE=	yes
MAKE_ENV=	DEFAULT_VIEWER="xdg-open" USE_SYSTEM_INIPARSER=1
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -Diniparser_setstr=iniparser_set
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

PLIST_SUB=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

MAN1=		isomaster.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@$$(CC)|$$(CC)|'

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} isomaster ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} isomaster.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${DATADIR}/icons
.for i in add2-kearone.png delete-kearone.png extract2-kearone.png \
	folder-new-kearone.png go-back-kearone.png isomaster.png
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} ${i} ${DATADIR}/icons)
.endfor
.for i in ar be@latin bg ca cs da de el es et fi fo fr he hr hu id it ja \
	lt lv nb nl nn pl pt pt_BR ro ru sk sl sq sr sr@Latn sr@latin sv \
	tr uk ur_PK zh_CN zh_TW
	@${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${i}.mo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/isomaster.mo)
.endfor
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} isomaster.desktop ${DESKTOPDIR})

.include <bsd.port.mk>

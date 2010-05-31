# New ports collection makefile for:	pdmenu
# Date created:		14 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

PORTNAME=	pdmenu
PORTVERSION=	1.2.98
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple console menu program

LIB_DEPENDS=   slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SLANG_H_LOC="${LOCALBASE}/include/slang.h" \
		SLANG_LIB_LOC="${LOCALBASE}/lib" \
		LIBS="-lcurses -lintl"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAN1=		pdmenu.1
MAN5=		pdmenurc.5
PLIST_FILES=	bin/pdmenu \
		etc/pdmenurc \
		share/locale/fr/LC_MESSAGES/pdmenu.mo \
		%%DATADIR%%/editdir.pl \
		%%DATADIR%%/showdir.pl
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdmenu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/pdmenurc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenu.man ${MANPREFIX}/man/man1/pdmenu.1
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenurc.man ${MAN5PREFIX}/man/man5/pdmenurc.5
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pl ${DATADIR}
.for lang in fr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/pdmenu.mo
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pdmenu

.include <bsd.port.mk>

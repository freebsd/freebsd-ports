# New ports collection makefile for:	pdmenu
# Date created:		14 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

PORTNAME=	pdmenu
PORTVERSION=	1.3.0
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple console menu program

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SLANG_H_LOC="${LOCALBASE}/include/slang.h" \
		SLANG_LIB_LOC="${LOCALBASE}/lib" \
		LIBS="-lcurses -lintl"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

MAN1=		pdmenu.1
MAN5=		pdmenurc.5
PLIST_FILES=	bin/pdmenu \
		etc/pdmenurc \
		share/locale/da/LC_MESSAGES/pdmenu.mo \
		share/locale/es/LC_MESSAGES/pdmenu.mo \
		share/locale/fr/LC_MESSAGES/pdmenu.mo \
		share/locale/ru/LC_MESSAGES/pdmenu.mo \
		%%DATADIR%%/editdir.pl \
		%%DATADIR%%/showdir.pl
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LANGS/s|=.*$$|= da es fr ru|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdmenu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/pdmenurc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenu.man ${MANPREFIX}/man/man1/pdmenu.1
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenurc.man ${MAN5PREFIX}/man/man5/pdmenurc.5
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pl ${DATADIR}
.for lang in da es fr ru
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/pdmenu.mo
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pdmenu

.include <bsd.port.mk>

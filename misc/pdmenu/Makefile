# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	pdmenu
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple console menu program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SLANG_H_LOC="${LOCALBASE}/include/slang.h" \
		SLANG_LIB_LOC="${LOCALBASE}/lib" \
		LIBS="-lcurses -lintl"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	bin/pdmenu \
		etc/pdmenurc \
		share/locale/da/LC_MESSAGES/pdmenu.mo \
		share/locale/es/LC_MESSAGES/pdmenu.mo \
		share/locale/fr/LC_MESSAGES/pdmenu.mo \
		share/locale/ru/LC_MESSAGES/pdmenu.mo \
		man/man1/pdmenu.1.gz \
		man/man5/pdmenurc.5.gz \
		%%DATADIR%%/editdir.pl \
		%%DATADIR%%/showdir.pl
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LANGS/s|=.*$$|= da es fr ru|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdmenu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/pdmenurc ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenu.man ${STAGEDIR}${MANPREFIX}/man/man1/pdmenu.1
	${INSTALL_MAN} ${WRKSRC}/doc/pdmenurc.man ${STAGEDIR}${MANPREFIX}/man/man5/pdmenurc.5
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pl ${STAGEDIR}${DATADIR}
.for lang in da es fr ru
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/pdmenu.mo
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdmenu

.include <bsd.port.mk>

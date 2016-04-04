# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	pdmenu
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple console menu program

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext gmake ncurses shebangfix
SHEBANG_FILES=	examples/showdir.pl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SLANG_H_LOC="${LOCALBASE}/include/slang.h" \
		SLANG_LIB_LOC="${LOCALBASE}/lib"
MAKE_ENV=	INSTALL_PREFIX="${STAGEDIR}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lncurses -lintl

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LANGS/s|=.*$$|= da es fr ru| ; \
		 /^LOCALEDIR/s|/usr/share|$$(DATADIR)| ; \
		 s|\($$(CC)\) \(-MM\)|\1 $$(CFLAGS) \2| ; \
		 /INSTALL/s| -m 0644|| ; \
		 /INSTALL/s|\(pdmenurc\)$$|\1.sample| ; \
		 s|install -m 644|$$(INSTALL)|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|$${INSTALL}|@INSTALL_PROGRAM@|' \
		${WRKSRC}/autoconf/makeinfo.in

.include <bsd.port.mk>

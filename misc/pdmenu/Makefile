PORTNAME=	pdmenu
DISTVERSION=	1.3.6
CATEGORIES=	misc
MASTER_SITES=	https://git.kitenet.net/index.cgi/pdmenu.git/snapshot/

MAINTAINER=	fuz@fuz.su
COMMENT=	Simple console menu program

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2

USES=		gettext gmake ncurses shebangfix
SHEBANG_FILES=	examples/showdir.pl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SLANG_H_LOC="${LOCALBASE}/include/slang.h" \
		SLANG_LIB_LOC="${LOCALBASE}/lib"
MAKE_ENV=	INSTALL_PREFIX="${STAGEDIR}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lncurses -lintl

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

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

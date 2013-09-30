# Created by: Kai Wang <kaiw27@gmail.com>
# $FreeBSD$

PORTNAME=	fish
PORTVERSION=	2.0.0
CATEGORIES=	shells
MASTER_SITES=	http://fishshell.com/files/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User friendly command line shell

OPTIONS_DEFINE=	DOCS NLS

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		iconv
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--docdir=${WRKDIR}/tmproot

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread ${ICONV_LIB}

MAN1=		fish.1 fish_indent.1 fish_pager.1 fishd.1 mimedb.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ENV+=	ac_cv_func_gettext=yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^all:/s|user_doc|| ; \
		 s| "$$(HAVE_GETTEXT)" = 1| x$$(HAVE_GETTEXT) = x1| ; \
		 s| $$(HAVE_GETTEXT) = 1| x$$(HAVE_GETTEXT) = x1| ; \
		 /fish\/man\/man1/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-rdynamic|-Wl,--export-dynamic| ; \
		 /pthread_create/d ; \
		 s|ncurses curses|curses| ; \
		 s|ncurses.h||' ${WRKSRC}/configure.ac

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/tmproot && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.for i in fish fish_indent fish_pager fishd mimedb
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
	if ${GREP} -q '${PREFIX}/bin/${PORTNAME}' /etc/shells; then \
		${TRUE}; \
	else \
		${ECHO_CMD} '${PREFIX}/bin/${PORTNAME}' >> /etc/shells; \
	fi

.include <bsd.port.mk>

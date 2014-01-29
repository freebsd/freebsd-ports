# Created by: Kai Wang <kaiw27@gmail.com>
# $FreeBSD$

PORTNAME=	fish
PORTVERSION=	2.1.0
CATEGORIES=	shells
MASTER_SITES=	http://fishshell.com/files/${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	User friendly command line shell

LICENSE=	GPLv2

USES=		gmake iconv
USE_AUTOTOOLS=	autoconf

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread ${ICONV_LIB}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENV=	ac_cv_func_gettext=yes
NLS_CONFIGURE_OFF=	--without-gettext

.include <bsd.port.options.mk> 

post-patch:
	@${REINPLACE_CMD} -e \
		'/^all:/s|user_doc|| ; \
		 s| "$$(HAVE_GETTEXT)" = 1| x$$(HAVE_GETTEXT) = x1| ; \
		 s| $$(HAVE_GETTEXT) = 1| x$$(HAVE_GETTEXT) = x1| ; \
		 s|$$(DESTDIR)$$(bindir)/fish|$$(bindir)/fish|g ; \
		 /fish\/man\/man1/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-rdynamic|-Wl,--export-dynamic| ; \
		 /pthread_create/d ; \
		 s|ncurses curses|curses| ; \
		 s|ncurses.h||' ${WRKSRC}/configure.ac

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=${FILESDIR}/extra-patch-Makefile.in
.endif

post-install:
.for i in fish fish_indent fish_pager fishd mimedb
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>

# Ports collection makefile for:	ekg2
# Date created:				27 Dec 2005
# Whom:					Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	0.3.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	http://pl.ekg2.org/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu, Jabber, and IRC client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		expat.6:${PORTSDIR}/textproc/expat2

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--with-expat \
			--without-sqlite \
			--without-gpm-mouse \
			--with-libgadu \
			--without-libgnutls \
			--without-gif \
			--without-libjpeg \
			--without-libidn

LDFLAGS+=		-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}
CFLAGS+=		-I${LOCALBASE}/include

OPTIONS_DEFINE=	ASPELL GPG GSM GTK2 PERL PYTHON SQLITE UNICODE XOSD

ASPELL_DESC=	Enable spell checking support
GPG_DESC=	Enable gpg plugin
GSM_DESC=	Enable gsm audio plugin
GTK2_DESC=	Enable gtk plugin
PERL_DESC=	Enable perl plugin
PYTHON_DESC=	Enable python plugin
SQLITE_DESC=	Enable sqlite plugin
UNICODE_DESC=	Enable unicode (experimental)
XOSD_DESC=	Enable xosd plugin

OPTIONS_DEFAULT=ASPELL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=		${LOCALBASE}/share/aspell/pl.rws:${PORTSDIR}/polish/aspell
CONFIGURE_ARGS+=	--with-aspell
.else
CONFIGURE_ARGS+=	--without-aspell
.endif

.if ${PORT_OPTIONS:MGPG}
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme \
			gpg-error:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST_SUB+=		GPG_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-gpg
PLIST_SUB+=		GPG_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MGSM}
LIB_DEPENDS+=		gsm:${PORTSDIR}/audio/gsm
CONFIGURE_ARGS+=	--with-libgsm
PLIST_SUB+=		GSM_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-libgsm
PLIST_SUB+=		GSM_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=		GTK2_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUB+=		GTK2_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		PERL_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		PYTHON_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		SQLITE_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		SQLITE_PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MUNICODE}
CONFIGURE_ARGS+=	--enable-unicode
.endif

.if ${PORT_OPTIONS:MXOSD}
LIB_DEPENDS+=		xosd:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-libxosd
PLIST_SUB+=		XOSD_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-libxosd
PLIST_SUB+=		XOSD_PLUGIN="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MPYTHON}
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/contrib/python/notify-bubble.py
.endif

.if ${PORT_OPTIONS:MUNICODE}
	@${REINPLACE_CMD} -e 's|ncursesw/||' ${WRKSRC}/configure \
		${WRKSRC}/plugins/ncurses/ecurses.h
.endif

.include <bsd.port.mk>

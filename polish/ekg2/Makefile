# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	0.3.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	http://pl.ekg2.org/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu, Jabber, and IRC client

LIB_DEPENDS=	libgadu.so:${PORTSDIR}/polish/libgadu \
		libexpat.so:${PORTSDIR}/textproc/expat2

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig

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

LDFLAGS+=		-L${LOCALBASE}/lib -lintl -pthread
CFLAGS+=		-I${LOCALBASE}/include

OPTIONS_DEFINE=	ASPELL GPG GSM GTK2 NLS PERL PYTHON SQLITE UNICODE XOSD
OPTIONS_SUB=	yes

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

ASPELL_CONFIGURE_ON=	--with-aspell
ASPELL_CONFIGURE_OFF=	--without-aspell
ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_RUN_DEPENDS=	${LOCALBASE}/share/aspell/pl.rws:${PORTSDIR}/polish/aspell

GPG_CONFIGURE_ON=	--with-gpg
GPG_CONFIGURE_OFF=	--without-gpg
GPG_LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
			libgpg-error.so:${PORTSDIR}/security/libgpg-error
GPG_RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

GSM_CONFIGURE_ON=	--with-libgsm
GSM_CONFIGURE_OFF=	--without-libgsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

GTK2_CONFIGURE_ON=	--with-gtk
GTK2_CONFIGURE_OFF=	--without-gtk

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

PERL_CONFIGURE_ON=	--with-perl
PERL_CONFIGURE_OFF=	--without-perl
PERL_USES=		perl5

PYTHON_CONFIGURE_ON=	--with-python
PYTHON_CONFIGURE_OFF=	--without-python

SQLITE_CONFIGURE_ON=	--with-sqlite3
SQLITE_CONFIGURE_OFF=	--without-sqlite3
SQLITE_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

UNICODE_CONFIGURE_ON=	--enable-unicode

XOSD_CONFIGURE_ON=	--with-libxosd
XOSD_CONFIGURE_OFF=	--without-libxosd
XOSD_LIB_DEPENDS=	libxosd.so:${PORTSDIR}/misc/xosd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
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

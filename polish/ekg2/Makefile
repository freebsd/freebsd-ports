# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	0.3.1
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	http://pl.ekg2.org/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu, Jabber, and IRC client

LIB_DEPENDS=	libgadu.so:${PORTSDIR}/polish/libgadu \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libexpat.so:${PORTSDIR}/textproc/expat2

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool pathfix pkgconfig readline

CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--with-expat \
			--without-sqlite \
			--without-gpm-mouse \
			--with-libgadu \
			--without-gif \
			--without-libjpeg \
			--without-libidn
INSTALL_TARGET=	install-strip

LDFLAGS+=		-L${LOCALBASE}/lib -lintl -pthread
CFLAGS+=		-I${LOCALBASE}/include

OPTIONS_DEFINE=	ASPELL GPG GSM GTK2 NLS PERL PYTHON SQLITE UNICODE XOSD
OPTIONS_DEFAULT=ASPELL
OPTIONS_SUB=	yes

GPG_DESC=	GPG plugin
GSM_DESC=	GSM audio plugin
GTK2_DESC=	GTK+ 2 plugin
PERL_DESC=	Perl plugin
PYTHON_DESC=	Python plugin
SQLITE_DESC=	SQLite plugin
UNICODE_DESC=	Unicode support (experimental)
XOSD_DESC=	Xosd plugin

ASPELL_CONFIGURE_WITH=	aspell
ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_RUN_DEPENDS=	${LOCALBASE}/share/aspell/pl.rws:${PORTSDIR}/polish/aspell

GPG_CONFIGURE_WITH=	gpg
GPG_LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
			libgpg-error.so:${PORTSDIR}/security/libgpg-error
GPG_RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

GSM_CONFIGURE_WITH=	libgsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

GTK2_CONFIGURE_WITH=	gtk
GTK2_USE=		GNOME=gtk2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

PERL_CONFIGURE_WITH=	perl
PERL_USES=		perl5

PYTHON_CONFIGURE_WITH=	python
PYTHON_USE=		PYTHON=yes

SQLITE_CONFIGURE_WITH=	sqlite3
SQLITE_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

UNICODE_CONFIGURE_ENABLE=	unicode

XOSD_CONFIGURE_WITH=	libxosd
XOSD_LIB_DEPENDS=	libxosd.so:${PORTSDIR}/misc/xosd

.include <bsd.port.options.mk>

post-patch:
# needs newer headers for O_NOFOLLOW flag
	@${REINPLACE_CMD} '/_XOPEN_SOURCE/ s|600|700|' \
		${WRKSRC}/plugins/xmsg/xmsg.c
.if ${PORT_OPTIONS:MPYTHON}
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/contrib/python/notify-bubble.py
.endif

.if ${PORT_OPTIONS:MUNICODE}
	@${REINPLACE_CMD} -e 's|ncursesw/||' ${WRKSRC}/configure \
		${WRKSRC}/plugins/ncurses/ecurses.h
.endif

.include <bsd.port.mk>

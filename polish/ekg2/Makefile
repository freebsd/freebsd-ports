# Ports collection makefile for:	ekg2
# Date created:				27 Dec 2005
# Whom:					Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	0.3.0
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	http://pl.ekg2.org/

MAINTAINER=	c0rn@o2.pl
COMMENT=	Text-mode Gadu-Gadu, Jabber and IRC client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		expat.6:${PORTSDIR}/textproc/expat2

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	ASPELL		"Enable spell checking support"	on \
		GPG		"Enable gpg plugin"		off \
		GSM		"Enable gsm audio plugin"	off \
		GTK2		"Enable gtk plugin"		off \
		PERL		"Enable perl plugin"		off \
		PYTHON		"Enable python plugin"		off \
		SQLITE		"Enable sqlite plugin"		off \
		XOSD		"Enable xosd plugin"		off

CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--with-expat \
			--without-sqlite \
			--without-gpm-mouse \
			--with-libgadu \
			--without-libgnutls \
			--without-gif \
			--without-libjpeg

CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lintl"
CFLAGS+=		-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=		${LOCALBASE}/share/aspell/pl.rws:${PORTSDIR}/polish/aspell
CONFIGURE_ARGS+=	--with-aspell
.else
CONFIGURE_ARGS+=	--without-aspell
.endif

.if defined(WITH_GPG)
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme \
			gpg-error:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST_SUB+=		GPG_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-gpg
PLIST_SUB+=		GPG_PLUGIN="@comment "
.endif

.if defined(WITH_GSM)
LIB_DEPENDS+=		gsm:${PORTSDIR}/audio/gsm
CONFIGURE_ARGS+=	--with-libgsm
PLIST_SUB+=		GSM_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-libgsm
PLIST_SUB+=		GSM_PLUGIN="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=		GTK2_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUB+=		GTK2_PLUGIN="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		PERL_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		PERL_PLUGIN="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		PYTHON_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON_PLUGIN="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		SQLITE_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		SQLITE_PLUGIN="@comment "
.endif

.if defined(WITH_XOSD)
LIB_DEPENDS+=		xosd:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-libxosd
PLIST_SUB+=		XOSD_PLUGIN=""
.else
CONFIGURE_ARGS+=	--without-libxosd
PLIST_SUB+=		XOSD_PLUGIN="@comment "
.endif

post-patch:
.if defined(WITH_PYTHON)
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/contrib/python/notify-bubble.py
.endif

.include <bsd.port.post.mk>

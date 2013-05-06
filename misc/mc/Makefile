# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	mc
PORTVERSION=	4.8.1.7
PORTREVISION=	0
CATEGORIES=	misc shells
MASTER_SITES=	http://www.midnight-commander.org/downloads/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LICENSE=	GPLv3

CONFLICTS=	mc-light-4*

BROKEN=	does not fetch

USES=		pkgconfig
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_PERL5=	yes
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${UNZIP_CMD} UNZIP=${UNZIP_CMD}
USE_AUTOTOOLS=	libtool

OPTIONS=	SLANG		"Build with SLang library" on \
		ICONV		"Build with iconv recoding" on \
		NLS		"Build with NLS support" on \
		EDIT		"Build with internal editor" on \
		X11		"Build with X11 library" off \
		SUBSHELL	"Build with subshell support" on \
		SAMBA		"Build with Samba support" on

post-patch:
	${REINPLACE_CMD} -e 's/SUBDIRS = intl/SUBDIRS =/' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/saved_CPPFLAGS="-ltermcap/saved_CPPFLAGS="/' ${WRKSRC}/configure

.include <bsd.port.options.mk>

.if defined(WITH_SAMBA) || !(defined(WITHOUT_SAMBA) || defined(MINIMAL))
CONFIGURE_ARGS+=--enable-vfs-smb --with-configdir=${LOCALBASE}/etc\
		--with-codepagedir=${LOCALBASE}/etc/codepages
.endif

.if defined(WITH_ICONV) || !(defined(WITHOUT_ICONV) || defined(MINIMAL))
USES+=		iconv
PLIST_SUB=	CHARSETS=""
.else
CONFIGURE_ARGS+=--disable-charset
PLIST_SUB=	CHARSETS="@comment "
.endif

.if !defined(WITH_NLS) && (defined(WITHOUT_NLS) || defined(MINIMAL))
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		gettext
PLIST_SUB+=	NLS=""
_MANLANG=	es hu it pl ru sr
.endif

.if !defined(WITH_X11) || (defined(WITHOUT_X11) || defined(MINIMAL))
CONFIGURE_ARGS+=--without-x
.else
USE_XORG=	x11 xext
.endif

.if !defined(WITH_EDIT) && (defined(WITHOUT_EDIT) || defined(MINIMAL))
CONFIGURE_ARGS+=--without-edit
PLIST_SUB+=	EDITOR="@comment "
.else
PLIST_SUB+=	EDITOR=""
.endif

.if !defined(WITH_SLANG) && (defined(WITHOUT_SLANG) || defined(MINIMAL))
CONFIGURE_ARGS+=--with-screen=ncurses
.else
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=--with-screen=slang --with-slang-includes=${LOCALBASE}/include
.endif

.if !defined(WITH_SUBSHELL) && (defined(WITHOUT_SUBSHELL) || defined(MINIMAL))
CONFIGURE_ARGS+=--without-subshell
.endif

MAN1=		mc.1 mcedit.1 mcview.1
_MAN1=		mc.1
.for lang in ${_MANLANG}
_MANPAGES+=	${_MAN1:S%^%${MAN1PREFIX}/man/${lang}/man1/%}
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.6.2
CATEGORIES=	misc shells
MASTER_SITES=	http://www.midnight-commander.org/downloads/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

CONFLICTS=	mc-light-4*

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
.if defined(WITH_GLIB12) || defined(MINIMAL)
USE_GNOME=	glib12
.else
USE_GNOME=	glib20
.endif
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:19 automake:19
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	-c -a

OPTIONS=	UTF8		"Build with UTF8 support" on \
		SLANG		"Build with SLang library" on \
		ICONV		"Build with iconv recoding" on \
		NLS		"Build with NLS support" on \
		EDIT		"Build with internal editor" on \
		X11		"Build with X11 library" off \
		SUBSHELL	"Build with subshell support" on \
		SAMBA		"Build with Samba support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SAMBA) || !(defined(WITHOUT_SAMBA) || defined(MINIMAL))
CONFIGURE_ARGS+=--with-samba --with-configdir=${LOCALBASE}/etc \
		--with-codepagedir=${LOCALBASE}/etc/codepages
.endif

.if defined(WITH_ICONV) || !(defined(WITHOUT_ICONV) || defined(MINIMAL))
CONFIGURE_ARGS+=--enable-charset --with-libiconv-prefix=${LOCALBASE}
PLIST_SUB=	CHARSETS=""
.else
PLIST_SUB=	CHARSETS="@comment "
.endif

.if !defined(WITH_NLS) && (defined(WITHOUT_NLS) || defined(MINIMAL))
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=	NLS=""
_MANLANG=	es hu it pl ru sr
.endif

.if !defined(WITH_X11) || defined(MINIMAL)
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

.if ${ARCH} == "alpha"
#
# something is wrong with slang on alpha: mc enters an infinite loop
# when calling has_colors() during terminal init (colors.c:250)
WITHOUT_SLANG=	yes
.endif

.if defined(WITH_UTF8)
PATCHFILES=	${DISTNAME}-utf8.patch.gz
PATCH_DIST_STRIP=	-p1
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=--with-screen=slang
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
.elif !defined(WITH_SLANG) && (defined(WITHOUT_SLANG) || defined(MINIMAL))
CONFIGURE_ARGS+=--with-screen=ncurses
.else
CONFIGURE_ARGS+=--with-screen=mcslang
.endif

.if !defined(WITH_SUBSHELL) && (defined(WITHOUT_SUBSHELL) || defined(MINIMAL))
CONFIGURE_ARGS+=--without-subshell
.endif

MAN1=		mc.1 mcedit.1 mcview.1
_MAN1=		mc.1
.for lang in ${_MANLANG}
_MANPAGES+=	${_MAN1:S%^%${MAN1PREFIX}/man/${lang}/man1/%}
.endfor

post-patch:
.if !defined(WITH_NLS) && (defined(WITHOUT_NLS) || defined(MINIMAL))
	@${REINPLACE_CMD} -e '/^LIBFILES_ADD +=/,/[^\\]$$/ s/^/#/'\
		${WRKSRC}/lib/Makefile.am
.endif
	@${REINPLACE_CMD} -e 's|/usr/bin/zip|${LOCALBASE}/bin/zip|' \
		-e 's|/usr/bin/unzip|${LOCALBASE}/bin/unzip|' \
		${WRKSRC}/configure

post-install:
	@${LN} -sf mc ${PREFIX}/bin/midc

.include <bsd.port.post.mk>

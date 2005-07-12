# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.6.0
PORTREVISION=	15
CATEGORIES=	misc shells
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

OPTIONS=	SLANG		"Build with SLang library" on \
		ICONV		"Build with iconv recoding" on \
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
CONFIGURE_ARGS+=--enable-charset
USE_ICONV=	yes
PLIST_SUB=	CHARSETS=""
.else
PLIST_SUB=	CHARSETS="@comment "
.endif

.if !defined(WITH_X11) || defined(MINIMAL)
CONFIGURE_ARGS+=--without-x
.else
USE_XLIB=	yes
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

.if !defined(WITH_SLANG) && (defined(WITHOUT_SLANG) || defined(MINIMAL))
CONFIGURE_ARGS+=--with-screen=ncurses
.else
CONFIGURE_ARGS+=--with-screen=slang
CONFIGURE_ENV=	CPPFLAGS="-I ${LOCALBASE}/include" \
		LDFLAGS="-ltermcap -L ${LOCALBASE}/lib"
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif

.if !defined(WITH_SUBSHELL) && (defined(WITHOUT_SUBSHELL) || defined(MINIMAL))
CONFIGURE_ARGS+=--without-subshell
.endif

.if defined(WITH_PERL_MODULES) || !(defined(WITHOUT_PERL_MODULES) || defined(MINIMAL))
.if ${PERL_LEVEL} < 500800
RUN_DEPENDS=    ${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.endif

MAN1=		mc.1 mcedit.1 mcview.1
_MAN1=		mc.1
_MANLANG=	es hu it pl ru.KOI8-R
.for lang in ${_MANLANG}
_MANPAGES+=	${_MAN1:S%^%${MAN1PREFIX}/man/${lang}/man1/%}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/zip|${LOCALBASE}/bin/zip|' \
		-e 's|/usr/bin/unzip|${LOCALBASE}/bin/unzip|' \
		${WRKSRC}/configure

post-install:
	@${LN} -sf mc ${PREFIX}/bin/midc

.include <bsd.port.post.mk>

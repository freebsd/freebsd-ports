# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.6.0
PORTREVISION=	12
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

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SAMBA)
CONFIGURE_ARGS+=--with-samba --with-configdir=${LOCALBASE}/etc \
		--with-codepagedir=${LOCALBASE}/etc/codepages
.endif

.if !defined(WITHOUT_ICONV)
CONFIGURE_ARGS+=--enable-charset
USE_ICONV=	yes
PLIST_SUB=	CHARSETS=""
.else
PLIST_SUB=	CHARSETS="@comment "
.endif

.if !defined(WITH_X11)
CONFIGURE_ARGS+=--without-x
.endif

.if ${ARCH} == "alpha"
#
# something is wrong with slang on alpha: mc enters an infinite loop
# when calling has_colors() during terminal init (colors.c:250)
WITHOUT_SLANG=	yes
.endif

.if defined(WITHOUT_SLANG)
CONFIGURE_ARGS+=--with-screen=ncurses
.else
CONFIGURE_ARGS+=--with-screen=slang
CONFIGURE_ENV=	CPPFLAGS="-I ${LOCALBASE}/include" \
		LDFLAGS="-ltermcap -L ${LOCALBASE}/lib"
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif

.if defined(WITHOUT_SUBSHELL)
CONFIGURE_ARGS+=--without-subshell
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS=    ${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
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

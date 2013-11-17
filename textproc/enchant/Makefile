# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/textproc/enchant/Makefile,v 1.3 2010/07/20 07:48:41 kwm Exp $

PORTNAME=	enchant
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 ltverhack
CONFIGURE_ARGS=	--disable-uspell \
		--disable-voikko

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_MULTI=	SPELL
OPTIONS_MULTI_SPELL=ASPELL HSPELL HUNSPELL ISPELL ZEMBEREK
OPTIONS_DEFAULT=HUNSPELL
HSPELL_DESC=	Spell checking via Hspell
HUNSPELL_DESC=	Spell checking via Hunspell
ZEMBEREK_DESC=	Spell checking via Zemberek

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	libaspell.so:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell \
		--with-aspell-prefix=${LOCALBASE}
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if ${PORT_OPTIONS:MHSPELL}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell
CONFIGURE_ARGS+=--enable-hspell \
		--with-hspell-prefix=${LOCALBASE}
PLIST_SUB+=	HSPELL=""
.else
CONFIGURE_ARGS+=--disable-hspell
PLIST_SUB+=	HSPELL="@comment "
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell
CONFIGURE_ARGS+=--enable-myspell --with-system-myspell=yes \
		--with-myspell-dir=${LOCALBASE}/share/hunspell
PLIST_SUB+=	HUNSPELL=""
.else
CONFIGURE_ARGS+=--disable-myspell
PLIST_SUB+=	HUNSPELL="@comment "
.endif

.if ${PORT_OPTIONS:MISPELL}
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=--enable-ispell \
		--with-ispell-dir=${LOCALBASE}/share/ispell
PLIST_SUB+=	ISPELL=""
.else
CONFIGURE_ARGS+=--disable-ispell
PLIST_SUB+=	ISPELL="@comment "
.endif

.if ${PORT_OPTIONS:MZEMBEREK}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-zemberek
PLIST_SUB+=	ZEMBEREK=""
.else
PLIST_SUB+=	ZEMBEREK="@comment "
CONFIGURE_ARGS+=--disable-zemberek
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MKDIRPROG-mkdir|MKDIRPROG-mkdir -p|g' \
		${WRKSRC}/install-sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libenchant.so.1 \
		      ${STAGEDIR}${PREFIX}/lib/enchant/libenchant_*.so

.include <bsd.port.mk>

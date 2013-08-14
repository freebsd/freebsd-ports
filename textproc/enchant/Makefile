# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/textproc/enchant/Makefile,v 1.3 2010/07/20 07:48:41 kwm Exp $

PORTNAME=	enchant
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20 ltverhack
CONFIGURE_ARGS=	--disable-uspell \
		--disable-voikko

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		enchant.1

OPTIONS_DEFINE=	ASPELL HSPELL HUNSPELL ISPELL ZEMBEREK
OPTIONS_DEFAULT=ASPELL
HSPELL_DESC=	Spell checking via Hspell
HUNSPELL_DESC=	Spell checking via Hunspell
ZEMBEREK_DESC=	Spell checking via Zemberek

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	pspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell \
		--with-aspell-prefix=${LOCALBASE}
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if ${PORT_OPTIONS:MHSPELL}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell
CONFIGURE_ARGS+=--enable-hspell
PLIST_SUB+=	HSPELL=""
.else
CONFIGURE_ARGS+=--disable-hspell
PLIST_SUB+=	HSPELL="@comment "
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell-1.3:${PORTSDIR}/textproc/hunspell
CONFIGURE_ARGS+=--enable-myspell
PLIST_SUB+=	HUNSPELL=""
.else
CONFIGURE_ARGS+=--disable-myspell
PLIST_SUB+=	HUNSPELL="@comment "
.endif

.if ${PORT_OPTIONS:MISPELL}
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=--enable-ispell
PLIST_SUB+=	ISPELL=""
.else
CONFIGURE_ARGS+=--disable-ispell
PLIST_SUB+=	ISPELL="@comment "
.endif

.if ${PORT_OPTIONS:MZEMBEREK}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-zemberek
PLIST_SUB+=	ZEMBEREK=""
.else
PLIST_SUB+=	ZEMBEREK="@comment "
CONFIGURE_ARGS+=--disable-zemberek
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MKDIRPROG-mkdir|MKDIRPROG-mkdir -p|g' \
		${WRKSRC}/install-sh

.include <bsd.port.mk>

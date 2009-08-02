# New ports collection makefile for:	enchant
# Date created:				03 January 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/textproc/enchant/Makefile,v 1.1 2006/03/12 02:08:58 mezz Exp $
#

PORTNAME=	enchant
PORTVERSION=	1.4.2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnometarget glib20 ltverhack
CONFIGURE_ARGS=	--disable-hspell \
		--disable-uspell
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		enchant.1

OPTIONS=	ASPELL "Enable aspell support" on \
		ZEMBEREK "Enable zemberek backend (requires DBUS)" off
		

.include <bsd.port.pre.mk>

# Disable, it needs hspell 0.9 or above.
#.if exists(${LOCALBASE}/bin/hspell)
#WITH_HSPELL=	yes
#.endif
#
#.if defined(WITH_HSPELL)
#BUILD_DEPENDS+=	hspell:${PORTSDIR}/hebrew/hspell
#CONFIGURE_ARGS+=--enable-hspell
#PLIST_SUB+=	HSPELL=""
#.else
#CONFIGURE_ARGS+=--disable-hspell
#PLIST_SUB+=	HSPELL="@comment "
#.endif

.ifndef(WITHOUT_ASPELL)
LIB_DEPENDS+=	pspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell \
		--with-aspell-prefix=${LOCALBASE}
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_ZEMBEREK) && !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=	--enable-zemberek
PLIST_SUB+=	ZEMBEREK=""
.else
PLIST_SUB+=	ZEMBEREK="@comment "
CONFIGURE_ARGS+=	--disable-zemberek
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MKDIRPROG-mkdir|MKDIRPROG-mkdir -p|g' \
		${WRKSRC}/install-sh
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -E -e "s|-Wunsafe-loop-optimizations ||g" \
		-e "s|-Wno-missing-field-initializers ||g" \
		-e "s|-Wno-attributes ||g" \
			${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>

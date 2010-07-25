# New ports collection makefile for:	enchant
# Date created:				03 January 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/textproc/enchant/Makefile,v 1.3 2010/07/20 07:48:41 kwm Exp $
#

PORTNAME=	enchant
PORTVERSION=	1.6.0
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnometarget glib20 ltverhack
CONFIGURE_ARGS=	--disable-uspell \
		--disable-voikko
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		enchant.1

OPTIONS=	ASPELL "Enable Aspell backend" on \
		HSPELL "Enable Hspell backend" off \
		HUNSPELL "Enable Hunspell backend" off \
		ISPELL "Enable Ispell backend" off \
		ZEMBEREK "Enable zemberek backend (requires DBUS)" off

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	pspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell \
		--with-aspell-prefix=${LOCALBASE}
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_HSPELL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell
CONFIGURE_ARGS+=--enable-hspell
PLIST_SUB+=	HSPELL=""
.else
CONFIGURE_ARGS+=--disable-hspell
PLIST_SUB+=	HSPELL="@comment "
.endif

.if defined(WITH_HUNSPELL)
LIB_DEPENDS+=	hunspell-1.2.0:${PORTSDIR}/hungarian/hunspell
CONFIGURE_ARGS+=--enable-myspell
PLIST_SUB+=	HUNSPELL=""
.else
CONFIGURE_ARGS+=--disable-myspell
PLIST_SUB+=	HUNSPELL="@comment "
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=--enable-ispell
PLIST_SUB+=	ISPELL=""
.else
CONFIGURE_ARGS+=--disable-ispell
PLIST_SUB+=	ISPELL="@comment "
.endif

.if defined(WITH_ZEMBEREK) && !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-zemberek
PLIST_SUB+=	ZEMBEREK=""
.else
PLIST_SUB+=	ZEMBEREK="@comment "
CONFIGURE_ARGS+=--disable-zemberek
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

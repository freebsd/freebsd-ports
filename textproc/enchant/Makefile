# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enchant
PORTVERSION=	1.6.0
PORTREVISION=	6
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	glib20
CONFIGURE_ARGS=	--disable-uspell \
		--disable-voikko

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

OPTIONS_MULTI=	SPELL
OPTIONS_MULTI_SPELL=ASPELL HSPELL HUNSPELL ISPELL ZEMBEREK
OPTIONS_DEFAULT=HUNSPELL
OPTIONS_SUB=	yes
HSPELL_DESC=	Spell checking via Hspell
HUNSPELL_DESC=	Spell checking via Hunspell
ZEMBEREK_DESC=	Spell checking via Zemberek

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=	aspell
ASPELL_CONFIGURE_ON=	--with-aspell-prefix=${LOCALBASE}

HSPELL_BUILD_DEPENDS=	${LOCALBASE}/lib/libhspell.a:hebrew/hspell
HSPELL_CONFIGURE_ENABLE=	hspell
HSPELL_CONFIGURE_ON=	--with-hspell-prefix=${LOCALBASE}

HUNSPELL_LIB_DEPENDS=	libhunspell-1.5.so:textproc/hunspell
HUNSPELL_CONFIGURE_ENABLE=	myspell
HUNSPELL_CONFIGURE_ON=	--with-system-myspell=yes \
			--with-myspell-dir=${LOCALBASE}/share/hunspell

ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_CONFIGURE_ENABLE=	ispell

ZEMBEREK_LIb_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
ZEMBEREK_CONFIGURE_ENABLE=	zemberek

post-patch:
	@${REINPLACE_CMD} -e 's|MKDIRPROG-mkdir|MKDIRPROG-mkdir -p|g' \
		${WRKSRC}/install-sh

.include <bsd.port.mk>

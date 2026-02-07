PORTNAME=	enchant
DISTVERSION=	2.8.10
CATEGORIES=	textproc gnome
MASTER_SITES=	https://github.com/rrthomas/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework
WWW=		https://rrthomas.github.io/enchant/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		compiler:c++11-lib gmake gnome libtool localbase pathfix \
		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-applespell \
		--without-voikko

INSTALL_TARGET=	install-strip

OPTIONS_MULTI=	SPELL
OPTIONS_MULTI_SPELL=ASPELL HSPELL HUNSPELL NUSPELL ZEMBEREK
OPTIONS_DEFAULT=HUNSPELL
OPTIONS_SUB=	yes
HSPELL_DESC=	Spell checking via Hspell
HUNSPELL_DESC=	Spell checking via Hunspell
NUSPELL_DESC=	Spell checking via Nuspell
ZEMBEREK_DESC=	Spell checking via Zemberek

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_WITH=	aspell
ASPELL_CONFIGURE_ON=	--with-aspell-dir=${LOCALBASE}/share/aspell

HSPELL_LIB_DEPENDS=	libhspell.so.0:hebrew/hspell
HSPELL_CONFIGURE_WITH=	hspell
HSPELL_CONFIGURE_ON=	--with-hspell-dir=${LOCALBASE}/share/hspell

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CONFIGURE_WITH=	hunspell
HUNSPELL_CONFIGURE_ON=	--with-hunspell-dir=${LOCALBASE}/share/hunspell

NUSPELL_LIB_DEPENDS=	libicuuc.so:devel/icu \
			libnuspell.so:textproc/nuspell
NUSPELL_CONFIGURE_WITH=	nuspell
NUSPELL_CONFIGURE_ON=	--with-nuspell-dir=${LOCALBASE}/share/hunspell

ZEMBEREK_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libdbus-glib-1.so:devel/dbus-glib
ZEMBEREK_CONFIGURE_WITH=	zemberek

PLIST_SUB+=	LIBVERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|groff -mandoc|mandoc -mdoc|' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>

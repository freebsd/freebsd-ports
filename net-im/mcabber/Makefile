# Created by: vsevolod
# $FreeBSD$

PORTNAME=	mcabber
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Small Jabber console client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# it picks libcharset from converters/libiconv installed by glib,
# so provide an explicit dependency
LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth \
		libcharset.so:converters/libiconv

USES=		gettext gnome iconv:wchar_t libtool localbase ncurses pathfix \
		pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hgcset
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		EXAMPLES GPGME OTR IDN
OPTIONS_DEFAULT=	IDN
OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL ENCHANT
OPTIONS_SUB=		yes

ENCHANT_DESC=		Spell checking support via Enchant
GPGME_DESC=		OpenPGP support via GPGME
OTR_DESC=		Off-the-record messaging support

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=aspell

ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
ENCHANT_CONFIGURE_ENABLE=enchant

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_ENABLE=	gpgme

OTR_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libotr.so.5:security/libotr
OTR_CONFIGURE_ENABLE=	otr

IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_OFF=	--without-libidn

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${libdir}|"$${libdir}|' \
		 -e 's|-O2 $$CFLAGS|$$CFLAGS|' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabber.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
		${STAGEDIR}${EXAMPLESDIR}/mcabberrc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

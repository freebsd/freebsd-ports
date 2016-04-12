# Created by: vsevolod
# $FreeBSD$

PORTNAME=	mcabber
PORTVERSION=	1.0.2
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Small Jabber console client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth

USES=		gettext iconv libtool localbase ncurses pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hgcset
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		EXAMPLES GPGME OTR
OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL ENCHANT

ENCHANT_DESC=		Spell checking support via Enchant
GPGME_DESC=		OpenPGP support via GPGME
OTR_DESC=		Off-the-record messaging support

OPTIONS_SUB=		yes

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=aspell

ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
ENCHANT_CONFIGURE_ENABLE=enchant

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_ENABLE=	gpgme

OTR_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libotr.so.5:security/libotr
OTR_CONFIGURE_ENABLE=	otr

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${libdir}|"$${libdir}|' \
		 -e 's|-O2 $$CFLAGS|$$CFLAGS|' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabber.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
		${STAGEDIR}${EXAMPLESDIR}/mcabberrc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

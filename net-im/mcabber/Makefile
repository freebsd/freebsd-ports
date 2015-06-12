# Created by: vsevolod
# $FreeBSD$

PORTNAME=	mcabber
PORTVERSION=	0.10.2
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small Jabber console client

LIB_DEPENDS=	libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sigwinch --libdir=${PREFIX}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		pkgconfig gettext iconv ncurses tar:bzip2 libtool
USE_LDCONFIG=	yes
USE_GNOME=	glib20

OPTIONS_DEFINE=	GPGME OTR
OPTIONS_RADIO=	SPELL
OPTIONS_RADIO_SPELL=	ASPELL ENCHANT
OPTIONS_SUB=	yes

GPGME_DESC=	Use security/gpgme for PGP support
OTR_DESC=	Off-the-record messaging support
ENCHANT_DESC=	Spell checking via enchant

GPGME_LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme
GPGME_CONFIGURE_ENABLE=	gpgme
ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_CONFIGURE_ENABLE=aspell
ENCHANT_LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant
ENCHANT_CONFIGURE_ENABLE=enchant
OTR_LIB_DEPENDS=	libotr.so.2:${PORTSDIR}/security/libotr3 \
			libgcrypt.so:${PORTSDIR}/security/libgcrypt
OTR_CONFIGURE_ENABLE=	otr

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${datadir}"|"$${datadir}"|;s|-O2||'\
		-e 's|$$"$${libdir}|"$${libdir}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.*

post-install:
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/
	@${INSTALL} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${CP} -R ${WRKSRC}/contrib ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${STAGEDIR}${EXAMPLESDIR}/mcabberrc

.include <bsd.port.mk>

# Created by: vsevolod
# $FreeBSD$

PORTNAME=	mcabber
PORTVERSION=	0.10.1
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ CENKES

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Small Jabber console client

LIB_DEPENDS=	loudmouth:${PORTSDIR}/net-im/loudmouth

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sigwinch --libdir=${PREFIX}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		pkgconfig gettext iconv ncurses
USE_LDCONFIG=	yes
USE_GNOME=	glib20

MAN1=		mcabber.1

OPTIONS_DEFINE=	GPGME OTR
OPTIONS_RADIO=	SPELL
OPTIONS_RADIO_SPELL=	ASPELL ENCHANT
GPGME_DESC=	Use security/gpgme for PGP support
OTR_DESC=	Off-the-record messaging support
ENCHANT_DESC=	Spell checking via enchant

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=	libgpgme.so:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell
.else
CONFIGURE_ARGS+=--disable-aspell
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=--enable-enchant
.else
CONFIGURE_ARGS+=--disable-enchant
.endif

.if ${PORT_OPTIONS:MOTR}
LIB_DEPENDS+=	otr.4:${PORTSDIR}/security/libotr3 \
		gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--enable-otr
PLIST_SUB+=	OTR=""
.else
CONFIGURE_ARGS+=--disable-otr
PLIST_SUB+=	OTR="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${datadir}"|"$${datadir}"|;s|-O2||'\
		-e 's|$$"$${libdir}|"$${libdir}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.*

post-install:
	@${INSTALL} -d ${PREFIX}/share/applications/ ${EXAMPLESDIR}/
	@${INSTALL} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@${CP} -R ${WRKSRC}/contrib ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.mk>

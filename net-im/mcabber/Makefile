# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.10.1
PORTREVISION=	2
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
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_NCURSES=	yes
USE_PKGCONFIG=	build
USE_GNOME=	glib20

MAN1=		mcabber.1

OPTIONS=	GPGME "Use security/gpgme for PGP support" off \
		OTR "Off-the-record messaging support" off \
		ASPELL "Use textproc/aspell for spell checking" off \
		ENCHANT "Use texproc/enchant for spell checking" off

.include <bsd.port.pre.mk>

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.19:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif

.if defined(WITH_ASPELL) && !defined(WITH_ENCHANT)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell
.else
CONFIGURE_ARGS+=--disable-aspell
.endif

.if defined(WITH_ENCHANT)
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=--enable-enchant
.else
CONFIGURE_ARGS+=--disable-enchant
.endif

.if defined(WITH_OTR)
LIB_DEPENDS+=	otr.4:${PORTSDIR}/security/libotr \
		gcrypt.18:${PORTSDIR}/security/libgcrypt
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

.include <bsd.port.post.mk>

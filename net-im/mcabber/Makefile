# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ CENKES
#DISTNAME=	${PORTNAME}-${PORTVERSION}-rc3

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Small Jabber console client

LIB_DEPENDS=	loudmouth:${PORTSDIR}/net-im/loudmouth

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sigwinch
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		mcabber.1

OPTIONS=	GPGME "Use security/gpgme for PGP support" off \
		OTR "Off-the-record messaging support" off \
		ASPELL "Use textproc/aspell for spell checking" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.18:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell
.else
CONFIGURE_ARGS+=--disable-aspell
.endif

.if defined(WITH_OTR)
LIB_DEPENDS+=	otr.4:${PORTSDIR}/security/libotr \
		gcrypt.16:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--enable-otr
.else
CONFIGURE_ARGS+=--disable-otr
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${datadir}"|"$${datadir}"|;s|-O2||'\
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.*

post-install:
	@${INSTALL} -d ${PREFIX}/share/applications/ ${EXAMPLESDIR}/
	@${INSTALL} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@${CP} -R ${WRKSRC}/contrib ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.post.mk>

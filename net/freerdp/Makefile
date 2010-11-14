# New ports collection makefile for:	freerdp
# Date created:				04 July 2010
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freerdp
PORTVERSION=	0.8.2
CATEGORIES=	net comms ipv6
MASTER_SITES=	SF/${PORTNAME}/0.8

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A free remote desktop protocol client

OPTIONS=	CUPS		"Enable printer support via CUPS"		on \
		SOUND		"Enable sound support via ALSA"			on \
		SAMPLERATE	"Enable libsamplerate support for sound"	off

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-iconv
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--with-x=no
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	x11 xcursor xextproto
CONFIGURE_ARGS+=--with-x
MAN1=		xfreerdp.1
PLIST_SUB+=	X11=""
.endif

.if !defined(WITHOUT_CUPS)
CONFIGURE_ARGS+=--with-printer=cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
.else
CONFIGURE_ARGS+=--with-printer=no
.endif

.if !defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=--with-sound=alsa
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	SOUND=""
.if !defined(WITHOUT_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=--without-libsamplerate
.endif
.else
CONFIGURE_ARGS+=--with-sound=no
PLIST_SUB+=	SOUND="@comment "
.endif

post-patch:
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's|man_MANS = |man_MANS1 = |g' ${WRKSRC}/doc/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|-ldl -lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/libfreerdpchanman/Makefile.in
	@${REINPLACE_CMD} -e 's|-I$$(top_builddir)|-I$$(top_builddir)/include|' \
		${WRKSRC}/libfreerdp/Makefile.in ${WRKSRC}/libfreerdpgdi/Makefile.in \
		${WRKSRC}/libfreerdpkbd/Makefile.in ${WRKSRC}/X11/Makefile.in

.include <bsd.port.mk>

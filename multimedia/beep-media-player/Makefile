# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$

PORTNAME=	beep-media-player
PORTVERSION=	0.9.7.1
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6
MASTER_SITES=	SF/beepmp/bmp/${PORTVERSION}
DISTNAME=	bmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 multimedia player

LIB_DEPENDS=	id3-3.8:${PORTSDIR}/audio/id3lib

USES=		pkgconfig
USE_GNOME=	gnomehack gtk20 libglade2 desktopfileutils
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++

MAN1=		beep-media-player.1

OPTIONS_MULTI=		OUTPUT
OPTIONS_MULTI_OUTPUT=	ALSA ESOUND OSS
OPTIONS_DEFINE=		NLS GCONF GNOMEVFS2 IPV6 VORBIS
OPTIONS_DEFAULT=	OSS VORBIS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
PATCH_SITES+=	http://ns.ael.ru/ports/distfiles/
PATCHFILES+=	bmp-0.9.7-ipv6-simple.diff
PATCH_DIST_STRIP+=	-p1
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

.if ${PORT_OPTIONS:MGNOMEVFS2}
USE_GNOME+=	gnomevfs2
CONFIGURE_ARGS+=--enable-gnome-vfs
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if ${PORT_OPTIONS:MOSS}
PLIST_SUB+=	OSS=""
.else
CONFIGURE_ARGS+=--disable-oss
PLIST_SUB+=	OSS="@comment "
.endif

.if ${ARCH} == i386
.if ${MACHINE_CPU:M3dnow} || ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=--enable-simd
.endif
.endif

post-patch:
#Fix asm comments and mnemonics for clang
	@${FIND} ${WRKSRC} -name "*.s" -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|\/|#|g' -e 's|fist |fists |g' -e 's|fistp |fistps |g'

post-install:
	@${MKDIR} ${PREFIX}/lib/bmp/General
	@${MKDIR} ${PREFIX}/share/beep/Skins
	-@update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

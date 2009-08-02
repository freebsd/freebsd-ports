# New ports collection makefile for:	beep
# Date created:			Thu Nov  6 19:24:01 CET 2003
# Whom:				Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	beep-media-player
PORTVERSION=	0.9.7.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6
MASTER_SITES=	SF/beepmp
DISTNAME=	bmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 multimedia player

USE_GNOME=	gtk20 libglade2 desktopfileutils
WANT_GNOME=	yes
USE_XORG=	x11
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++" \
		INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
MAN1=		beep-media-player.1

INPUT_PLUGINS=	cdaudio,mpg123,wav
OUTPUT_PLUGINS=	OSS
VISUALIZATION_PLUGINS=	blur_scope

OPTIONS=	VORBIS	"Enable Ogg Vorbis support" on \
		ESOUND	"Enable Esound support"  off \
		3DNOW	"Enable 3DNow! optimized decoding routines" on \
		IPV6	"Enable IPv6 support" off

.include <bsd.port.pre.mk>

# Enable IPv6 support
.if defined(WITH_IPV6)
PATCH_SITES+=	http://izb.knu.ac.kr/~bh/diffs/
PATCHFILES+=	bmp-0.9.7-ipv6-simple.diff
PATCH_DIST_STRIP+=	-p1
.endif

CONFIGURE_ARGS+=	--disable-mikmod
PLIST_SUB+=	MIKMODPLUGIN:="@comment "

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
OUTPUT_PLUGINS+=	esd
PLIST_SUB+=	ESDPLUGIN:=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN:="@comment "
.endif

.if ${ARCH} != "i386"
WITHOUT_3DNOW=	yes
.endif

.if !defined(WITHOUT_3DNOW)
CONFIGURE_ARGS+=	--enable-3dnow
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|{datadir}/locale|{prefix}/share/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

post-install:
	@${MKDIR} ${PREFIX}/lib/bmp/General
	@${MKDIR} ${PREFIX}/share/beep/Skins
	-@update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	beep
# Date created:			Thu Nov  6 19:24:01 CET 2003
# Whom:				Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	beep-media-player
PORTVERSION=	0.9.7.1
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6
MASTER_SITES=	SF/beepmp/bmp/${PORTVERSION}
DISTNAME=	bmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 multimedia player

USE_GNOME=	gtk20 libglade2 desktopfileutils
WANT_GNOME=	yes
USE_XORG=	x11
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lstdc++
MAN1=		beep-media-player.1

INPUT_PLUGINS=	cdaudio,mpg123,wav
OUTPUT_PLUGINS=	OSS
VISUALIZATION_PLUGINS=	blur_scope

OPTIONS_DEFINE=	VORBIS ESOUND 3DNOW IPV6
OTPIONS_DEFAULT=	VORBIS 3DNOW

OPTIONS_EXCLUDE_i386=	3DNOW

3DNOW_DESC=	3DNow! optimized decoding routines

.include <bsd.port.options.mk>

# Enable IPv6 support
.if ${PORT_OPTIONS:MIPV6}
PATCH_SITES+=	http://izb.knu.ac.kr/~bh/diffs/
PATCHFILES+=	bmp-0.9.7-ipv6-simple.diff
PATCH_DIST_STRIP+=	-p1
.endif

CONFIGURE_ARGS+=	--disable-mikmod
PLIST_SUB+=	MIKMODPLUGIN:="@comment "

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
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

.if ${PORT_OPTIONS:M3DNOW}
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

.include <bsd.port.mk>

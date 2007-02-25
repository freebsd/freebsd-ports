# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious-plugins
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://audacious-media-player.org/release/
EXTRACT_SUFX=.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Plugins needed for audacious

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile  \
		curl.4:${PORTSDIR}/ftp/curl \
		tag.5:${PORTSDIR}/audio/taglib

USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-jack --disable-adplug --disable-lirc \
		--disable-alsa --disable-amidiplug --disable-arts --disable-wma

PORTDOCS=	AUTHORS ChangeLog NEWS

OPTIONS=	VORBIS	"Enable Ogg Vorbis input" on \
		MODPLUG	"Enable modplug input" off \
		FLAC	"Enable FLAC input" off \
		SID	"Enable sid input" off \
		MPC	"Enable mpc input" off \
		ESOUND	"Enable Esound output"  off \
		GNOME   "Build with gnomevfs/gconf support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBISPLUGIN=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN="@comment "
.endif

.if !defined(WITHOUT_MODPLUG)
PLIST_SUB+=	MODPLUG=""
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
.else
PLIST_SUB+=	MODPLUG="@comment "
CONFIGURE_ARGS+=	--disable-modplug
.endif

.if defined(WITH_FLAC)
PLIST_SUB+=	FLACPLUGIN=""
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
.else
PLIST_SUB+=	FLACPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !defined(WITHOUT_SID)
PLIST_SUB+=	SIDPLUGIN=""
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
.else
PLIST_SUB+=	SIDPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-sid
.endif

.if !defined(WITHOUT_MPC)
PLIST_SUB+=	MPCPLUGIN=""
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec \
	tag.5:${PORTSDIR}/audio/taglib
.else
PLIST_SUB+=	MPCPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-musepack
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	ESDPLUGIN=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN="@comment "
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomevfs2 gconf2
CONFIGURE_ARGS+=	--enable-gnome-vfs --enable-gconf
.endif

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-nonnull ||g' ${WRKSRC}/src/sexypsf/Makefile
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes\.h|g' \
		${WRKSRC}/src/alac/plugin.c ${WRKSRC}/src/alac/alac.c \
		${WRKSRC}/src/alac/stream.h ${WRKSRC}/src/alac/demux.c \
		${WRKSRC}/src/alac/demux.h ${WRKSRC}/src/alac/stream.c \
		${WRKSRC}/src/aac/mp4ff/mp4ff_int_types.h
.endif

post-install:
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be stored in the gconf database."
	@${ECHO_MSG} ""
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

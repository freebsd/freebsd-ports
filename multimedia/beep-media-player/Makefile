# New ports collection makefile for:	beep
# Date created:			Thu Nov  6 19:24:01 CET 2003
# Whom:				Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	beep-media-player
PORTVERSION=	0.9.6.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	beepmp
DISTNAME=	bmp-${PORTVERSION}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	GTK2 mp3 player

USE_GNOME=	gtk20
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
LIBTOOLFILES=	configure libbeep/configure
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
MAN1=		beep-media-player.1

INPUT_PLUGINS=	cdaudio,mpg123
OUTPUT_PLUGINS=	OSS
VISUALIZATION_PLUGINS=	blur_scope

PLIST_SUB=	DATADIR="share"

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-ipv6

#.if !defined(WITHOUT_MIKMOD)
#LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
#INPUT_PLUGINS+=	mikmod
#PLIST_SUB+=	MIKMODPLUGIN:=""
#.else
CONFIGURE_ARGS+=	--disable-mikmod
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
#.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if ${HAVE_GNOME:Mesound}!=""
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

.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=	--enable-3dnow
.endif

.if defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
post-extract:
	(cd ${WRKSRC}/Input/mpg123 && ${MV} decode_i586.s decode_i586.S && \
	  cd ${WRKSRC}/Visualization/blur_scope && ${MV} blur_8.s blur_8.S);
	${REINPLACE_CMD} -e 's:\.s :\.S :g' ${WRKSRC}/Input/mpg123/Makefile.in
	${REINPLACE_CMD} -e 's:blur_8.s:blur_8.S:g' \
	  ${WRKSRC}/Visualization/blur_scope/Makefile.in
.endif

pre-extract:
.if !defined(WITHOUT_MIKMOD) || !defined(WITHOUT_VORBIS) || ( !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021 ) || ${HAVE_GNOME:Mesound}!=""
	@${ECHO_MSG}
.if !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_MIKMOD."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable 3DNow! optimized decoding routines by defining WITHOUT_3DNOW."
.endif
.if ${HAVE_GNOME:Mesound}!=""
	@${ECHO_MSG} "You can disable support for esound by defining WITHOUT_GNOME=esound."
.endif
	@${ECHO_MSG}
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
	@${MKDIR} ${PREFIX}/share/beep/Skins
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

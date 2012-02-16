# New ports collection makefile for:	aegisub
# Date created:				2nd March 2010
# Whom:					Leinier Cruz Salfran <salfrancl@yahoo.es>
#
# $FreeBSD$
#    $MCom: ports-stable/multimedia/aegisub/Makefile,v 0.14 2010/03/10 17:02:00 salfrancl Exp $
#      $Id: Makefile,v 0.14 2010/03/10 17:02:00 salfrancl Exp $
#

PORTNAME=	aegisub
PORTVERSION=	2.1.8
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/releases/ \
		http://ftp2.aegisub.org/pub/releases/ \
		ftp://ftp.aegisub.org/pub/releases/ \
		ftp://ftp2.aegisub.org/pub/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aegisub Project is a cross-platform subtitle editor

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config \
		intltoolize:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	DEBUG 		"Enable debug" Off \
		PROFILE 	"Enable profiling" Off \
		GCOV		"Enable GCOV (require profiling)" Off \
		EFENCE		"Enable Electric Fence (require profiling)" Off \
		NLS		"Enable Native Language Support" On \
		PORTAUDIO	"Enable PortAudio2 audio provider (only one)" Off \
		PULSE		"Enable PulseAudio audio provider (only one)" On \
		OSS		"Enable OSS audio player (require portaudio)" Off \
		FFMPEG		"Enable FFMPEG video provider" Off \
		HUNSPELL	"Hungarian Spell" On \
		LUA		"LUA Scripting" On \
		PERL		"Perl Scripting" On

USE_ICONV=	yes
USE_WX=	2.8
WX_COMPS=	wx contrib
WX_UNICODE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/lib/wx/include/gtk2-unicode-release-2.8/ \
		-I${LOCALBASE}/include/wx-2.8 \
		-L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug --enable-debug-exceptions
.endif
.if defined(WITH_GCOV)
CONFIGURE_ARGS+=	--enable-gcov
WITH_PROFILE=	yes
.endif
.if defined(WITH_EFENCE)
CONFIGURE_ARGS+=	--enable-efence
WITH_PROFILE=	yes
.endif
.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--without-nls
.else
USE_GETTEXT=	yes
.endif
.if defined(WITH_PORTAUDIO)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/portaudio-2.0.pc:${PORTSDIR}/audio/portaudio2
.endif
.if defined(WITH_PULSE)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libpulse.pc:${PORTSDIR}/audio/pulseaudio
.endif
.if defined(WITH_OSS)
BUILD_DEPENDS+=	ossinfo:${PORTSDIR}/audio/oss
.endif
.if defined(WITH_PULSE)
CONFIGURE_ARGS+=	--with-player-audio=pulseaudio
.else
.if defined(WITH_OSS)
CONFIGURE_ARGS+=	--with-player-audio=portaudio
.endif
.endif
.if !defined(WITHOUT_FFMPEG)
BROKEN=	ffmpeg support is broken
BUILD_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-provider-video=ffmpegsource --with-provider-audio=ffmpegsource
.endif
.if defined(WITH_HUNSPELL)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/hunspell.pc:${PORTSDIR}/textproc/hunspell
.endif
.if defined(WITH_LUA)
USE_LUA=	5.1+
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LDFLAGS="-L${LUA_LIBDIR} -llua"
.endif
.if defined(WITH_PERL)
uSE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
.endif

.include <bsd.port.post.mk>

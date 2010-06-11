# New ports collection makefile for:    gnustep-gui
# Date created:         19 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-gui
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	0.19.0
PORTREVISION=	1
.else
PORTVERSION=	0.17.1
PORTREVISION=	2
.endif
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep GUI library

LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
.if defined(WITH_GNUSTEP_DEVEL)
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
BUILD_DEPENDS+=	${LOCALBASE}/lib/libflite.a:${PORTSDIR}/audio/flite
.else
LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile
.endif

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/lib
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USE_XORG=	x11 xt

EXTRA_PATCHES+=		${FILESDIR}/GNUmakefile.patch
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BREAKS_IF_PEDANTIC=	yes
PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

.if defined(WITH_GNUSTEP_DEVEL)
EXTRA_PATCHES+=	${FILESDIR}/AudioOutputSink.m.patch
.endif

.if defined(WITHOUT_GNUSTEP_FAKEMAIN)
.if !exists(/proc/curproc)
IGNORE=		requires procfs mounted to build or run, for details see procfs(5)
.endif
.endif

.if !defined(WITHOUT_PORTAUDIO2) && !defined(WITHOUT_PORTAUDIO) && !defined(WITH_GNUSTEP_DEVEL)
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio2
CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 ${PTHREAD_CFLAGS}
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 ${PTHREAD_LIBS}
ADDITIONAL_INCLUDE_DIRS+=	-I${LOCALBASE}/include/portaudio2
ADDITIONAL_LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2
PLIST_SUB+=	WITH_PORTAUDIO=""
.else
PLIST_SUB+=	WITH_PORTAUDIO="@comment "
.endif

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
PLIST_SUB+=	WITH_CUPS=""
.else
PLIST_SUB+=	WITH_CUPS="@comment "
.endif

ASPELL_PORT?=	textproc/aspell
.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/${ASPELL_PORT}
PLIST_SUB+=	WITH_ASPELL=""
.else
PLIST_SUB+=	WITH_ASPELL="@comment "
.endif

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	kazehakase
# Date created:		2004-04-06
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	kazehakase
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/11115/

MAINTAINER=	ahze@ahze.net
COMMENT=	Kazehakase is a browser with gecko engine like Epiphany or Galeon

.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
BUILD_DEPENDS=	${X11BASE}/lib/firefox/lib/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${X11BASE}/lib/firefox/lib/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
.else
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
.endif

USE_LIBTOOL_VER=13
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes

.if defined(WITH_MIGEMO)
USE_RUBY=	yes
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	MIGEMO "Enable Migemo (Japanese incremental search)" Off \
		ESTRAIER "Enable a full-text search system" Off \
		IMAGEMAGICK "Enable Thumbnail support (EXPERIMENTAL!)" Off

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

.include <bsd.port.pre.mk>

.if !defined(WITH_MOZILLA)
WITH_MOZILLA=	mozilla
.else
.if ${WITH_MOZILLA}=="mozilla"
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel"
HEADERS_SUFX=	-devel
.else
.if ${WITH_MOZILLA}=="firefox"
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${X11BASE}/lib/firefox/lib/pkgconfig"
.else
HEADERS_SUFX=
.endif
.endif
.endif
.endif

.if exists(${LOCALBASE}/bin/migemo)
.if exists(${RUBY_SITEARCHLIBDIR}/uconv.so)
WITH_MIGEMO=	yes
.endif
.endif

.if exists(${LOCALBASE}/bin/estxview)
WITH_ESTRAIER=	yes
.endif

.if exists(${LOCALBASE}/bin/convert)
WITH_IMAGEMAGICK=yes
.endif

.if defined(WITH_MIGEMO)
.if ${ARCH} == "i386" || ${ARCH} == "sparc64"
RUN_DEPENDS+=	migemo:${PORTSDIR}/japanese/migemo \
		${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv

CONFIUGURE_ARGS+=	--enable-migemo
.endif
.endif

.if defined(WITH_ESTRAIER)
RUN_DEPENDS+=	estxview:${PORTSDIR}/japanese/estraier
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default this port uses www/mozilla for Gecko support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} " firefox "
	@${ECHO_MSG} " mozilla "
	@${ECHO_MSG} " mozilla-devel "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Currently you are using ${WITH_MOZILLA}"

post-patch:
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
	@${REINPLACE_CMD} -e 's|mozilla-|firefox-|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|regex.h|gnuregex.h|' \
		${WRKSRC}/src/prefs_ui/prefs_location_entry.c

post-configure:
	@${REINPLACE_CMD} -e 's|%%FLASHPLAYER%%|${FLASHPLAYER}|; \
		s|%%PREFIX%%|${PREFIX}|; s|%%X11BASE%%|${X11BASE}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/src/kazehakase

post-install:
.if defined(WITH_IMAGEMAGICK)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

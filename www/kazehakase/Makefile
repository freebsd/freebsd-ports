# New ports collection makefile for:	kazehakase
# Date created:		2004-04-06
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	kazehakase
PORTVERSION=	0.1.8.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/10618/

MAINTAINER=	ahze@ahze.net
COMMENT=	Kazehakase is a browser with gecko engine like Epiphany or Galeon

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif

USE_LIBTOOL_VER=13
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	MIGEMO "Enable Migemo (Japanese incremental search)" Off

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

.include <bsd.port.pre.mk>

.if defined(WITH_MIGEMO)
.if ${ARCH} == "i386" || ${ARCH} == "sparc64"
RUN_DEPENDS+=	migemo:${PORTSDIR}/japanese/migemo \
		${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv

CONFIUGURE_ARGS+=	--enable-migemo
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|regex.h|gnuregex.h|' \
		${WRKSRC}/src/prefs_ui/prefs_location_entry.c

post-configure:
	@${REINPLACE_CMD} -e 's|%%FLASHPLAYER%%|${FLASHPLAYER}|; \
		s|%%PREFIX%%|${PREFIX}|; s|%%X11BASE%%|${X11BASE}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|; s|%%MOZILLA%%|${MOZILLA}|' \
			${WRKSRC}/src/kazehakase

.include <bsd.port.post.mk>

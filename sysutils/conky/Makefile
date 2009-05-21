# New ports collection makefile for:	conky
# Date created:				2005-08-27
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conky
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	ntarmos@cs.uoi.gr
COMMENT?=	An advanced, highly configurable system monitor for X

CONFLICTS?=	conky-awesome-[0-9]*
SLAVEDIRS=	sysutils/conky-awesome

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XORG?=	x11 xext xdamage
USE_GNOME?=	pkgconfig
USE_ICONV=	yes
CONFIGURE_ARGS+=	--disable-portmon \
			--disable-config-output  \
			--disable-hddtemp
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAN1=		conky.1

PORTDOCS=	README AUTHORS ChangeLog TODO NEWS \
		docs.html variables.html config_settings.html

.if defined(WITH_AUDACIOUS)
LIB_DEPENDS+=		audclient.2:${PORTSDIR}/multimedia/audacious
CONFIGURE_ARGS+=	--enable-audacious
.else
CONFIGURE_ARGS+=	--disable-audacious
.endif

.if defined(WITH_BMPX)
BUILD_DEPENDS+=		beep-media-player-2:${PORTSDIR}/multimedia/bmpx
RUN_DEPENDS+=		beep-media-player-2:${PORTSDIR}/multimedia/bmpx
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-bmpx
.else
CONFIGURE_ARGS+=	--disable-bmpx
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

#.if !defined(WITHOUT_OWN_WINDOW)
#CONFIGURE_ARGS+=	--enable-own-window
#.else
#CONFIGURE_ARGS+=	--disable-own-window
#.endif

.if defined(WITH_MPD)
CONFIGURE_ARGS+=	--enable-mpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITH_XMMS2)
LIB_DEPENDS+=		xmmsclient.4:${PORTSDIR}/audio/xmms2
CONFIGURE_ARGS+=	--enable-xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if defined(WITHOUT_DOUBLE_BUFFER)
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

.if defined(WITHOUT_SETI)
CONFIGURE_ARGS+=	--disable-seti
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_AUDACIOUS=yes to enable Audacious support"
	@${ECHO_MSG} "WITH_BMPX=yes to enable BMPx support"
	@${ECHO_MSG} "WITH_XFT=yes to enable XFT support"
	@${ECHO_MSG} "WITHOUT_OWN_WINDOW=yes to disable own window support"
	@${ECHO_MSG} "WITH_MPD=yes to enable MPD support"
	@${ECHO_MSG} "WITH_XMMS2=yes to enable XMMS2 support"
	@${ECHO_MSG} "WITHOUT_DOUBLE_BUFFER=yes to disable double buffer support"
	@${ECHO_MSG} " "

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${PREFIX}/man/man1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/data/conky.conf ${EXAMPLESDIR}/conkyrc.sample

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

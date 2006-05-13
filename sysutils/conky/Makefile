# New ports collection makefile for:	conky
# Date created:				2005-08-27
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conky
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An advanced, highly configurable system monitor for X

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--disable-portmon --disable-proc-uptime
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

MAN1=		conky.1

PORTDOCS=	README AUTHORS ChangeLog TODO \
		docs.html variables.html config_settings.html

.if defined(WITH_BMPX)
BUILD_DEPENDS+=		bmpx:${PORTSDIR}/multimedia/bmpx
RUN_DEPENDS+=		bmpx:${PORTSDIR}/multimedia/bmpx
LIB_DEPENDS+=		dbus-1.2:${PORTSDIR}/devel/dbus
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

.if !defined(WITHOUT_OWN_WINDOW)
CONFIGURE_ARGS+=	--enable-own-window
.else
CONFIGURE_ARGS+=	--disable-own-widnow
.endif

.if defined(WITH_MPD)
CONFIGURE_ARGS+=	--enable-mpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITHOUT_DOUBLE_BUFFER)
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_BMPX=yes to enable BMPx support"
	@${ECHO_MSG} "WITH_XFT=yes to enable XFT support"
	@${ECHO_MSG} "WITHOUT_OWN_WINDOW=yes to disable own window support"
	@${ECHO_MSG} "WITH_MPD=yes to enable MPD support"
	@${ECHO_MSG} "WITHOUT_DOUBLE_BUFFER=yes to disable double buffer support"
	@${ECHO_MSG} " "

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${PREFIX}/man/man1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/conkyrc.sample ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Doesn't compile on 4.x"
.endif

.include <bsd.port.post.mk>

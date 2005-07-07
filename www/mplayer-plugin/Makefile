# New ports collection makefile for:	mplayerplug-in
# Date Created:				20 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	2.85
PORTREVISION=	
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mplayerplug-in

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Mozilla plugin for the MPlayer media player

.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
.else
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
.endif
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer

HEADERS_SUFX=

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
PLUGINSFILES=	mplayerplug-in.so mplayerplug-in.xpt
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -DBSD" \
		LDFLAGS="-L${X11BASE}/lib"

.if !defined(WITH_MOZILLA)
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla"
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel"
HEADERS_SUFX=	-devel
.else
HEADERS_SUFX=
.endif
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
.if defined(WITH_MOZILLA)
.if ${WITH_MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default this port uses www/mozilla for Gecko support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} " firefox "
	@${ECHO_MSG} " mozilla-devel "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Makefile.in
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
	@${REINPLACE_CMD} -e 's|mozilla-|firefox-|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|mozilla-plugin|mozilla-plugin${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/Source/plugin-setup.cpp

do-install:
	@${MKDIR} ${PREFIX}/lib/browser_plugins
.for moo in ${PLUGINSFILES}
	@${INSTALL_DATA} ${WRKSRC}/${moo} ${PREFIX}/lib/browser_plugins/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
		${PREFIX}/etc/mplayerplug-in.conf.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
			${PREFIX}/etc/mplayerplug-in.conf ; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
		${PREFIX}/etc/mplayerplug-in.types.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.types ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
			${PREFIX}/etc/mplayerplug-in.types ;\
	fi

.include <bsd.port.post.mk>

# New ports collection makefile for:	mplayerplug-in
# Date Created:				20 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mplayerplug-in

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Mozilla plugin for the MPlayer media player

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Source/mplayerplug-in.c

do-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mplayerplug-in.so \
		${PREFIX}/lib/browser_plugins
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
		${PREFIX}/etc/mplayerplug-in.conf.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
			${PREFIX}/etc/mplayerplug-in.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
		${PREFIX}/etc/mplayerplug-in.types.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.types ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
			${PREFIX}/etc/mplayerplug-in.types ;\
	fi

.include <bsd.port.mk>

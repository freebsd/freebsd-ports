# New ports collection makefile for:	Ogle FOX GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Goggles
PORTVERSION=	0.5.5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.fifthplanet.net/files/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A FOX frontend to the Ogle DVD player

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.10:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	FOX-1.1.25:${PORTSDIR}/x11-toolkits/fox-devel
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-dvdcontrol=${LOCALBASE} \
		--with-fox=${LOCALBASE} \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is /dev/acd0c'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

.include <bsd.port.pre.mk>

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0c
.endif

post-patch:
# point to specific device
	@${REINPLACE_CMD} -E -e \
		's|\"/dev/dvd\"|\"${DEFAULT_DVD_DEVICE}\"|' \
		${WRKSRC}/src/dvdwindow.cpp
# hack to enable correct CPPFLAGS
	@${REINPLACE_CMD} -E -e \
		's|@CPPFLAGS@|${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>

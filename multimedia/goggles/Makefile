# New ports collection makefile for:	Ogle FOX GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Goggles
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.fifthplanet.net/files/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A FOX frontend to the Ogle DVD player

BROKEN=		"Conflicts with x11-toolkits/fox-devel version 1.2.1"

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.11:${PORTSDIR}/multimedia/ogle
LIB_DEPENDS=	FOX-1.2.1:${PORTSDIR}/x11-toolkits/fox-devel
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-dvdcontrol=${LOCALBASE} \
		--with-fox=${LOCALBASE} \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME:S/G/g/}-${PORTVERSION}

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is ${DEFAULT_DVD_DEVICE}'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile on alpha 5.x"
.endif

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

post-patch:
# point to specific device
	@${REINPLACE_CMD} -E -e \
		's|\"/dev/acd0c\"|\"${DEFAULT_DVD_DEVICE}\"|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>

# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.8.7
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		xcb.2:${PORTSDIR}/x11/libxcb

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_GETTEXT=		yes
USE_LDCONFIG=		yes
USE_AUTOTOOLS=		libtool:22
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS} -I${WRKSRC}" CFLAGS="${CFLAGS} -I${WRKSRC}"
DVB_HEADERS=		ca.h dmx.h frontend.h net.h audio.h video.h

.ifdef (WITH_GSTREAMER)
USE_GSTREAMER=		yes
PLIST_SUB+=		NOGSTREAMER=""
.else
PLIST_SUB+=		NOGSTREAMER="@comment "
.endif
.ifdef (WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
PLIST_SUB+=	NOLAME=""
.else
CONFIGURE_ARGS+=	--without-lame
PLIST_SUB+=	NOLAME="@comment "
.endif

.include <bsd.port.pre.mk>

.ifndef (WITH_GSTREAMER)
CONFIGURE_ARGS+=	--without-gstreamer
.endif

post-patch:
	${REINPLACE_CMD} -e "s,xx,," ${WRKSRC}/po/Makefile.in
	${REINPLACE_CMD} "s,#include <endian.h>,," \
		${WRKSRC}/kaffeine/src/input/disc/paranoia.cpp
	${REINPLACE_CMD} "s,#include <linux/types.h>,," \
		${WRKSRC}/kaffeine/src/input/dvb/lib/libdvbapi/dvbvideo.c
	${MKDIR} ${WRKSRC}/linux/dvb
	cd ${FILESDIR}; ${CP} ${DVB_HEADERS} ${WRKSRC}/linux/dvb
	${REINPLACE_CMD} -e "s,^LIBTOOL=,#LIBTOOL=,; \
			s,-0.8.6,," ${WRKSRC}/configure
	${TOUCH} -t 200401230000 ${WRKSRC}/admin/acinclude.m4.in

.include <bsd.port.post.mk>

# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		dvdcss.2:${PORTSDIR}/graphics/libdvdcss \
		dvdread.2:${PORTSDIR}/graphics/libdvdread \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_XLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-liba52=${LOCALBASE}
MAKE_ENV=	SDL_CONFIG=${SDL_CONFIG}
INSTALLS_SHLIB=	yes

MAN1=	ogle.1
MAN5=	oglerc.5

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

post-patch:
.ifdef(WITH_DVD_DEVICE)
	@${PERL} -pi.orig -e \
		"s|(DEFAULT_DVD_DEVICE=\")/dev/acd0c(\")|\1${WITH_DVD_DEVICE}\2|" \
		${WRKSRC}/configure.in
.endif
	@${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|" ${WRKSRC}/scripts/ogle.in
	@${PERL} -pi -e 's|(xmlversion.h>)|libxml/\1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${TOUCH} `find -E ${WRKSRC} -regex ".*Makefile\.(am|in)"`
	@${TOUCH} ${WRKSRC}/configure.in ${WRKSRC}/configure

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
. if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mi486} == "i486")
WITH_OPTIMIZED_BYTESWAP=yes
. endif

. if defined(WITH_OPTIMIZED_BYTESWAP)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-include:ogle_endian.h
. endif
.endif

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is /dev/acd0c'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif
.ifndef(WITH_OPTIMIZED_BYTESWAP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_BYTESWAP to use optimized byteswap'
	@${ECHO_MSG} '===> routines. This works only in the i386 architecture, and'
	@${ECHO_MSG} '===> only with 486 processors and above.'
.endif

.include <bsd.port.post.mk>

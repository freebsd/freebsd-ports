# New ports collection makefile for:	libmpeg2
# Date created:		Tue Oct 16 17:14:20 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg2
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/
DISTNAME=	mpeg2dec-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A free library for decoding mpeg-2 and mpeg-1 video streams

USE_XLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS= --enable-shared \
		--with-x

MAN1=	extract_mpeg2.1 mpeg2dec.1

.ifdef(WITH_MGA)
CONFIGURE_ARGS+=	--enable-mga
.endif

.ifdef(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libvo::configure.incl
SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV+=  SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-warnings
.endif

# We must be able to build EV6 code; actual CPU-type optimizations
# are chosen at runtime.
.if ${MACHINE_ARCH:L} == "alpha"
CFLAGS:=	${CFLAGS:N-mcpu=*}
.endif

pre-everything::
	@${ECHO_MSG} "====>"
.ifndef(WITH_SDL)
	@${ECHO_MSG} "====> You can enable SDL support by defining WITH_SDL"
.endif
.ifndef(WITH_MGA)
	@${ECHO_MSG} "====> You can enable MGA support by defining WITH_MGA"
.endif
	@${ECHO_MSG} "====>"

post-patch:
	@${REINPLACE_CMD} -e 's|<SDL/|<SDL11/|' ${WRKSRC}/libvo/*
	@${REINPLACE_CMD} -e 's|-O3||;s|<termio.h>|<termios.h>|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmpeg2/Makefile.in

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/libvo.txt ${DOCSDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/libvo/libvo.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/include/video_out.h \
		${PREFIX}/include/mpeg2dec

.include <bsd.port.mk>

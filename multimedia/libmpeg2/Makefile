# New ports collection makefile for:	libmpeg2
# Date created:		Tue Oct 16 17:14:20 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg2
PORTVERSION=	0.4.0b
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/
DISTNAME=	mpeg2dec-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A free library for decoding mpeg-2 and mpeg-1 video streams

USE_GNOME=	lthack
USE_XLIB=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--enable-shared \
		--with-x

WRKSRC=		${WRKDIR}/mpeg2dec-0.4.0

MAN1=	extract_mpeg2.1 mpeg2dec.1

PORTDOCS=	libmpeg2.txt

.ifdef(WITH_MGA)
CONFIGURE_ARGS+=	--enable-mga
.endif

.ifdef(WITH_SDL)
USE_SDL=	yes
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libvo::configure.incl
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-warnings
.endif

.include <bsd.port.pre.mk>

# We must be able to build EV6 code; actual CPU-type optimizations
# are chosen at runtime.
.if ${ARCH} == "alpha"
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
	@${REINPLACE_CMD} -e 's|<SDL/|<SDL11/|' \
		${WRKSRC}/src/* \
		${WRKSRC}/libvo/*
	@${REINPLACE_CMD} -e 's|-O3||;s|<termio.h>|<termios.h>|' ${WRKSRC}/configure
# AMD64 prefers position independent code
.if ${ARCH:L} == "amd64"
	@${REINPLACE_CMD} -e 's|-prefer-non-pic||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmpeg2/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmpeg2/convert/Makefile.in
post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/libmpeg2.txt ${DOCSDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/libvo/libvo.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/include/video_out.h \
		${PREFIX}/include/mpeg2dec

.include <bsd.port.post.mk>

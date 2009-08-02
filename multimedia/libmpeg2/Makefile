# New ports collection makefile for:	libmpeg2
# Date created:		Tue Oct 16 17:14:20 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg2
PORTVERSION=	0.5.1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A free library for decoding mpeg-2 and mpeg-1 video streams

USE_GNOME=	gnometarget ltverhack
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--enable-shared \
		--with-x

MAN1=	extract_mpeg2.1 mpeg2dec.1

PORTDOCS=	libmpeg2.txt README

.ifdef(WITH_SDL)
USE_SDL=	yes
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libmpeg2.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/libvo/libvo.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/video_out.h \
		${PREFIX}/include/mpeg2dec

.include <bsd.port.post.mk>

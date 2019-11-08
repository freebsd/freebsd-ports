# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwcview
PORTVERSION=	1.4.1
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.selasky.org/hans_petter/video4bsd/releases/ \
		LOCAL/kwm

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	The Video4Linux PWC webcam viewer

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat
LIB_DEPENDS=	libv4l1.so:multimedia/libv4l

CONFLICTS=	pwcbsd-[0-9]*

USES=		jpeg sdl
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-ljpeg|-ljpeg -lv4l1|g' \
		-e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwcview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pwcsnap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>

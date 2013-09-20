# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwcview
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.selasky.org/hans_petter/video4bsd/releases/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	The Video4Linux PWC webcam viewer

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		v4l1.0:${PORTSDIR}/multimedia/libv4l

CONFLICTS=	pwcbsd-[0-9]*

USE_SDL=	sdl
MAN1=		pwcview.1

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-ljpeg|-ljpeg -lv4l1|g' \
		-e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwcview ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pwcsnap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>

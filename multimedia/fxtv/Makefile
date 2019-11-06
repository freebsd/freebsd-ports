# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	fxtv
PORTVERSION=	1.03
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/sanpei

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based TV display and capture application (for use with bt848 driver)

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libXaw3d.so:x11-toolkits/Xaw3d

USES=		gmake jpeg tar:tgz xorg
MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	ice sm x11 xaw xext xmu xt xpm xxf86vm xxf86dga
MAKE_FLAGS=	-e

OPTIONS_DEFINE=	EXTRA
EXTRA_DESC=	Extra programs required to record/playback/save

# This program does not actually require the programs below unless you
# use audio/video recording and/or playback and save to a non-raw format.
EXTRA_RUN_DEPENDS=	sox:audio/sox \
			mpg123:audio/mpg123 \
			mpeg_encode:multimedia/mpeg_encode \
			mplex:multimedia/mplex

pre-install:
	@${CP} -p ${WRKSRC}/fxtv.1 ${WRKSRC}/fxtv.man

.include <bsd.port.mk>

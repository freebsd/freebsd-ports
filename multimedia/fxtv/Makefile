# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	fxtv
PORTVERSION=	1.03
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sanpei
EXTRACT_SUFX=	.tgz

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	X-based TV Display and Capture Application (for use with bt848 driver)

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	ice sm x11 xaw xext xmu xt xpm xxf86vm xxf86dga
USE_GMAKE=	yes
MAKE_FLAGS=	-e
MAN1=		fxtv.1

ONLY_FOR_ARCHS=	alpha i386 ia64 amd64

OPTIONS_DEFINE=	EXTRA
EXTRA_DESC=	Extra programs required to record/playback/save

NO_STAGE=	yes
.include <bsd.port.options.mk>

# This program does not actually require the programs below unless you
#   use audio/video recording and/or playback and save to a non-raw format.
.if ${PORT_OPTIONS:MEXTRA}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox \
		mpg123:${PORTSDIR}/audio/mpg123 \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		mplex:${PORTSDIR}/multimedia/mplex
.endif

pre-install:
	${CP} ${WRKSRC}/fxtv.1 ${WRKSRC}/fxtv.man

.include <bsd.port.mk>

# New ports collection makefile for:   xawtv
# Date created:        03 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xawtv
PORTVERSION=	3.83
CATEGORIES=	graphics
MASTER_SITES=	http://bytesex.org/xawtv/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lehmann@ans-netz.de

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		aa.1:${PORTSDIR}/graphics/aalib

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAKE_ENV=	verbose=yes

FILES_LIBJPEG=	console/Subdir.mk debug/Subdir.mk x11/Subdir.mk

MAN1=		alevtd.1 dump-mixers.1 fbtv.1 mtt.1 motv.1 ntsc-cc.1 pia.1 \
		propwatch.1 radio.1 record.1 rootv.1 scantv.1 showriff.1 \
		streamer.1 subtitles.1 ttv.1 v4lctl.1 webcam.1 xawtv-remote.1 \
		xawtv.1
MAN5=		xawtvrc.5
MAN8=		v4l-conf.8

.include <bsd.port.pre.mk>

PLIST_SUB+=	X11PREFIX=${X11BASE}

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${X11BASE}|g" \
		-e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure

.for i in ${FILES_LIBJPEG}
	@${REINPLACE_CMD} -e "s|-ljpeg|-L${LOCALBASE}/lib -ljpeg|g" ${WRKSRC}/$i
.endfor

.include <bsd.port.post.mk>

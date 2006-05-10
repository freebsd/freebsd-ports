# New ports collection makefile for:   xawtv
# Date created:        03 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xawtv
PORTVERSION=	3.95
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.bytesex.org/releases/xawtv/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A TV viewing application and a few TV utilities

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		${X11BASE}/lib/X11/fonts/misc/led-iso8859-1.pcf.gz:${PORTSDIR}/x11-fonts/tv-fonts
RUN_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		${X11BASE}/lib/X11/fonts/misc/led-iso8859-1.pcf.gz:${PORTSDIR}/x11-fonts/tv-fonts
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

OPTIONS=	AA		"Enable AA support" on \
		DV		"Enable reading/writing raw dv files" off \
		QUICKTIME	"Enable quicktime support" off \
		ZVBI		"Enable libzvbi support" off \
		MMX		"Enable mmx support (only for i386)" off

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CFLAGS="-I${WRKSRC}/common"
MAKE_ENV=	verbose=yes
INSTALLS_SHLIB=	yes

FILES_LIBJPEG=	console/Subdir.mk debug/Subdir.mk x11/Subdir.mk

MAN1=		alevtd.1 dump-mixers.1 fbtv.1 mtt.1 motv.1 ntsc-cc.1 pia.1 \
		propwatch.1 radio.1 record.1 rootv.1 scantv.1 showriff.1 \
		streamer.1 subtitles.1 ttv.1 v4l-info.1 v4lctl.1 webcam.1 \
		xawtv-remote.1 xawtv.1
MAN5=		xawtvrc.5
MAN8=		v4l-conf.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha amd64 i386
.endif

.if defined(WITHOUT_AA)
CONFIGURE_ARGS+=--disable-aa
PLIST_SUB+=	AA="@comment "
.else
CONFIGURE_ARGS+=--enable-aa
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	AA=""
.endif

.if defined(WITH_ZVBI)
LIB_DEPENDS+=	zvbi.8:${PORTSDIR}/devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
.if ${OSVERSION} > 500000
PLIST_SUB+=	ZVBI="" ZVBI5=""
.else
PLIST_SUB+=	ZVBI="" ZVBI5="@comment "
.endif
.else
CONFIGURE_ARGS+=--enable-zvbi=no
PLIST_SUB+=	ZVBI="@comment " ZVBI5="@comment "
.endif

.if defined(WITH_DV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--enable-dv
PLIST_SUB+=	DV=
.else
CONFIGURE_ARGS+=--enable-dv=no
PLIST_SUB+=	DV="@comment "
.endif

.if defined(WITH_MMX)
.if ${ARCH} == i386
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DMMX=1
.else
BROKEN=		MMX support only works on i386, and you are running ${ARCH}
.endif
.endif

.if defined(WITH_QUICKTIME)
CONFIGURE_ARGS+=--enable-quicktime
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
PLIST_SUB+=	QT=
.else
CONFIGURE_ARGS+=--enable-quicktime=no
PLIST_SUB+=	QT="@comment "
.endif

PLIST_SUB+=	X11PREFIX=${X11BASE}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g; \
		s|/usr/local|${LOCALBASE}|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|-lquicktime|-L${LOCALBASE}/lib &|g' \
		${WRKSRC}/configure

.for i in ${FILES_LIBJPEG}
	@${REINPLACE_CMD} -e "s|-ljpeg|-L${LOCALBASE}/lib -ljpeg|g" ${WRKSRC}/$i
.endfor

.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|FOUND_ZVBI|NOT_WORKING_&|g" \
		${WRKSRC}/vbistuff/Subdir.mk ${WRKSRC}/x11/Subdir.mk
.endif

.include <bsd.port.post.mk>

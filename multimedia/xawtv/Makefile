# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	xawtv
PORTVERSION=	3.103
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/xawtv/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A TV viewing application and a few TV utilities

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		${LOCALBASE}/lib/X11/fonts/misc/led-iso8859-1.pcf.gz:${PORTSDIR}/x11-fonts/tv-fonts
RUN_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		${LOCALBASE}/lib/X11/fonts/misc/led-iso8859-1.pcf.gz:${PORTSDIR}/x11-fonts/tv-fonts
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	AALIB DV QUICKTIME ZVBI
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT=	AALIB
ZVBI_DESC=	Enable libzvbi support

USES=		gmake motif
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_XORG=	x11 xaw
CONFIGURE_ENV=	LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC}/common
MAKE_ENV=	verbose=yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	alpha amd64 i386

FILES_LIBJPEG=	console/Subdir.mk x11/Subdir.mk libng/plugins/Subdir.mk

MAN1=		alevtd.1 dump-mixers.1 fbtv.1 mtt.1 motv.1 ntsc-cc.1 pia.1 \
		propwatch.1 radio.1 record.1 rootv.1 scantv.1 showriff.1 \
		streamer.1 subtitles.1 ttv.1 v4l-info.1 v4lctl.1 webcam.1 \
		xawtv-remote.1 xawtv.1
MAN5=		xawtvrc.5
MAN8=		v4l-conf.8

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAALIB}
CONFIGURE_ARGS+=--enable-aa
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	AA=""
.else
CONFIGURE_ARGS+=--disable-aa
PLIST_SUB+=	AA="@comment "
.endif

.if ${PORT_OPTIONS:MZVBI}
LIB_DEPENDS+=	zvbi.13:${PORTSDIR}/devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
PLIST_SUB+=	ZVBI="" ZVBI5=""
.else
CONFIGURE_ARGS+=--enable-zvbi=no
PLIST_SUB+=	ZVBI="@comment " ZVBI5="@comment "
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--enable-dv
PLIST_SUB+=	DV=
.else
CONFIGURE_ARGS+=--enable-dv=no
PLIST_SUB+=	DV="@comment "
.endif

.if ${PORT_OPTIONS:MMMX}
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DMMX=1
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
CONFIGURE_ARGS+=--enable-quicktime
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
PLIST_SUB+=	QT=
.else
CONFIGURE_ARGS+=--enable-quicktime=no
PLIST_SUB+=	QT="@comment "
.endif

PLIST_SUB+=	X11PREFIX=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g; \
		s|/usr/local|${LOCALBASE}|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|-lquicktime|-L${LOCALBASE}/lib &|g' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/console/Subdir.mk \
		${WRKSRC}/x11/Subdir.mk

.for i in ${FILES_LIBJPEG}
	@${REINPLACE_CMD} -e "s|-ljpeg|-L${LOCALBASE}/lib -ljpeg|g" ${WRKSRC}/$i
.endfor

.include <bsd.port.post.mk>

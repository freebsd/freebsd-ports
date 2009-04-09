# New ports collection makefile for:	moonlight
# Date created:				Feb 13 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonlight
PORTVERSION=	1.0.1
CATEGORIES=	multimedia www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/moon/
DISTNAME=	moon-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	OpenSource Implementation of Silverlight

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

OPTIONS=	FF2 "Install Firefox 2.x support" on
#		FF3 "Install Firefox 3.x support" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-cairo=system \
		--with-debug=yes

WEBPLUGINS_DIR=		${PREFIX}/lib/moon/plugin
WEBPLUGINS_FILES=	libmoonloader.so \
			libmoonplugin.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		does not build: not yet ported to sparc64
.endif

.if !defined(WITHOUT_FF2) || exists(${LOCALBASE}/bin/firefox)
BUILD_DEPENDS+=		${LOCALBASE}/bin/firefox:${PORTSDIR}/www/firefox
RUN_DEPENDS+=		${LOCALBASE}/bin/firefox:${PORTSDIR}/www/firefox

USE_WEBPLUGINS+=	gecko18
WEBPLUGINS_FILES+=	libmoonplugin-ff2bridge.so

PLIST_SUB+=		FF2=""
CONFIGURE_ARGS+=	--with-ff2=yes
.else
PLIST_SUB+=		FF2="@comment "
CONFIGURE_ARGS+=	--with-ff2=no
.endif

#.if !defined(WITHOUT_FF3) || exists(${LOCALBASE}/bin/firefox3)
#BUILD_DEPENDS+=		${LOCALBASE}/bin/firefox3:${PORTSDIR}/www/firefox3
#RUN_DEPENDS+=		${LOCALBASE}/bin/firefox3:${PORTSDIR}/www/firefox3
#
#USE_WEBPLUGINS+=		gecko19
#WEBPLUGINS_FILES+=	libmoonplugin-ff3bridge.so
#
#PLIST_SUB+=		FF3=""
#CONFIGURE_ARGS+=	--with-ff3=yes
#CONFIGURE_ENV+=		FF3_CFLAGS="-I${LOCALBASE}/include/firefox3/unstable -I${LOCALBASE}/include/nspr" \
#			FF3_LIBS="-pthread -L${LOCALBASE}/lib/firefox3"
#.else
PLIST_SUB+=		FF3="@comment "
CONFIGURE_ARGS+=	--with-ff3=no
#.endif

.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

# Building the .xpi doesn't actually require embedded cairo, but it's a safer option
# as there's no way for firefox to detect if cairo is already installed apparently.
.if defined(WITH_XPI_PLUGIN)
CONFIGURE_ARGS+=--enable-user-plugin --with-cairo=embedded
PLIST=		${NONEXISTENT}
PLIST_FILES=	${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<malloc.h>/d' \
			${WRKSRC}/src/animation.cpp \
			${WRKSRC}/src/runtime.cpp \
			${WRKSRC}/src/xaml.cpp \
			${WRKSRC}/src/xap.cpp \
			${WRKSRC}/src/value.cpp
	@${REINPLACE_CMD} -e 's|CODEC_URL|""|' \
			${WRKSRC}/src/pipeline-ui.cpp
	@${REINPLACE_CMD} -e 's|\(^LIBS\) =|\1 = -lexecinfo|' \
		-e 's|/proc/|/compat/linux/proc/| ' \
			${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||' \
			${WRKSRC}/plugin/Makefile.in
#	@${REINPLACE_CMD} -e 's|\(FF3_MODULES\)=.*|\1="libavutil"|1' \
#			${WRKSRC}/configure
#	@${REINPLACE_CMD} -e 's|\(FF3_MODULES\)=.*|\1="firefox-js firefox-plugin"|1' \
#			${WRKSRC}/configure

.if defined(WITH_XPI_PLUGIN)
do-install:
	${INSTALL_DATA} ${WRKSRC}/plugin/install/novell-moonlight.xpi \
		${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

.include <bsd.port.post.mk>

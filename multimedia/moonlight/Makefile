# New ports collection makefile for:	moonlight
# Date created:				Feb 13 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonlight
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	multimedia www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/moon/
DISTNAME=	moon-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	OpenSource Implementation of Silverlight

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_GECKO=	libxul
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-cairo=system \
		--with-debug=yes \
		--with-ff2=no \
		--with-ff3=yes

USE_WEBPLUGINS=		gecko19
WEBPLUGINS_DIR=		${PREFIX}/lib/moon/plugin
WEBPLUGINS_FILES=	libmoonloader.so \
			libmoonplugin.so \
			libmoonplugin-ff3bridge.so

OPTIONS=	PULSEAUDIO "Build with PA (needed for sound support)" on

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${ARCH} == "sparc64"
IGNORE=		does not build: not yet ported to sparc64
.endif

.if ${OSVERSION} < 700000
IGNORE=		does not build: requires posix_memalign(3)
.endif

.if !defined(WITHOUT_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--with-pulseaudio=yes
.else
CONFIGURE_ARGS+=--with-pulseaudio=no
.endif

# Building the .xpi doesn't actually require embedded cairo, but it's a safer option
# as there's no way for firefox to detect if cairo is already installed apparently.
.if defined(WITH_XPI_PLUGIN_ONLY)
CONFIGURE_ARGS+=--enable-user-plugin --with-cairo=embedded
PLIST=		${NONEXISTENT}
PLIST_FILES=	${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

post-patch:
	@${REINPLACE_CMD} -e '/TEST_SUBDIR =/d' \
			${WRKSRC}/Makefile.in
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

.if defined(WITH_XPI_PLUGIN_ONLY)
do-install:
	${INSTALL_DATA} ${WRKSRC}/plugin/install/novell-moonlight.xpi \
		${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

.include <bsd.port.post.mk>

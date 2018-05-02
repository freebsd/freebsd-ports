# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iridium
PORTVERSION=	58.0
PORTREVISION=	16
CATEGORIES=	www
MASTER_SITES=	https://downloads.iridiumbrowser.de/source/
PKGNAMESUFFIX=	-browser
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Iridium browser

LICENSE=	BSD3CLAUSE LGPL21 MPL11
LICENSE_COMB=	multi

BUILD_DEPENDS=	gperf:devel/gperf \
		clang60:devel/llvm60 \
		yasm:devel/yasm \
		ffmpeg>=3.2.2,1:multimedia/ffmpeg \
		bash:shells/bash \
		flock:sysutils/flock \
		node:www/node \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}

LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher \
		libsnappy.so:archivers/snappy \
		libFLAC.so:audio/flac \
		libspeex.so:audio/speex \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libicuuc.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libre2.so:devel/re2 \
		libcairo.so:graphics/cairo \
		libdrm.so:graphics/libdrm \
		libexif.so:graphics/libexif \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libavcodec.so:multimedia/ffmpeg \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libgcrypt.so:security/libgcrypt \
		libgnome-keyring.so:security/libgnome-keyring \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		droid-fonts-ttf>0:x11-fonts/droid-fonts-ttf

ONLY_FOR_ARCHS=	amd64 i386
USES=		bison desktop-file-utils jpeg ninja perl5 \
		pkgconfig python:2.7,build shebangfix tar:xz

USE_PERL5=	build
USE_XORG=	scrnsaverproto x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xproto xrandr xrender xscrnsaver xtst
USE_GNOME=	atk dconf glib20 gtk20 gtk30 libxml2 libxslt
MAKE_ARGS=	-C out/${BUILDTYPE}
ALL_TARGET=	chrome
INSTALLS_ICONS=	yes
BINARY_ALIAS=	python=${PYTHON_CMD}

CC=		clang60
CXX=		clang++60
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clang

# Run "./out/${BUILDTYPE}/gn args out/${BUILDTYPE} --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_use_chrome_plugins=false \
		enable_media_router=true \
		enable_nacl=false \
		enable_one_click_signin=true \
		enable_remoting=false \
		enable_webrtc=false \
		fieldtrial_testing_like_official_build=true \
		is_clang=true \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_allocator="none" \
		use_aura=true \
		use_cups=true \
		use_experimental_allocator_shim=false \
		use_gtk3=true \
		use_lld=true \
		use_sysroot=false \
		use_system_libjpeg=true \
		use_system_sqlite=false   # chrome has additional patches
# TODO: investigate building with these options:
# use_system_harfbuzz use_system_minigbm
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild

SUB_FILES=	iridium-browser.desktop iridium
SUB_LIST+=	COMMENT="${COMMENT}"

OPTIONS_DEFINE=	CODECS DEBUG GCONF KERBEROS
CODECS_DESC=	Compile and enable patented codecs like H.264
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO

OPTIONS_DEFAULT=	ALSA CODECS GCONF KERBEROS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
			alsa-lib>=1.1.1_1:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		GN_ARGS+=ffmpeg_branding="Chrome" \
			GN_ARGS+=proprietary_codecs=true \
			GN_ARGS+=enable_hevc_demuxing=true
CODECS_VARS_OFF=	GN_ARGS+=ffmpeg_branding="Chromium" \
			GN_ARGS+=proprietary_codecs=false \
			GN_ARGS+=enable_hevc_demuxing=false

DEBUG_VARS=		BUILDTYPE=Debug \
			GN_ARGS+=is_debug=true \
			GN_BOOTSTRAP_FLAGS+=--debug \
			WANTSPACE="lots of free diskspace (~ 8.5GB)"
DEBUG_VARS_OFF=		BUILDTYPE=Release \
			GN_ARGS+=is_debug=false \
			GN_ARGS+=symbol_level=0 \
			GN_ARGS+=remove_webcore_debug_symbols=true \
			WANTSPACE="a fair amount of free diskspace (~ 3.7GB)"

GCONF_USE=		GNOME=gconf2
GCONF_VARS=		GN_ARGS+=use_gconf=true
GCONF_VARS_OFF=		GN_ARGS+=use_gconf=false

KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

# With SNDIO=on we exclude audio_manager_linux from the build (see
# media/audio/BUILD.gn) and use audio_manager_openbsd which does not
# support falling back to ALSA.  In theory it supports falling back to
# PulseAudio, but this is untested.
SNDIO_PREVENTS=		ALSA PULSEAUDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

.include <bsd.port.options.mk>

# TODO: -isystem, would be just as ugly as this approach, but more reliably
# build would fail without C_INCLUDE_PATH/CPLUS_INCLUDE_PATH env var set.
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include

# Work around base r261801
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100508
GN_ARGS+=	extra_cxxflags="-D_LIBCPP_TRIVIAL_PAIR_COPY_CTOR=1"
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Iridium, you should have around 2GB of memory"
	@${ECHO_MSG} "and ${WANTSPACE}."
	@${ECHO_MSG}

post-patch-SNDIO-on:
	@${MKDIR} ${WRKSRC}/media/audio/sndio ${WRKSRC}/media/audio/openbsd
	@${CP} ${FILESDIR}/sndio_output.* ${WRKSRC}/media/audio/sndio
	@${CP} ${FILESDIR}/sndio_input.* ${WRKSRC}/media/audio/sndio
	@${CP} ${FILESDIR}/audio_manager_openbsd.* ${WRKSRC}/media/audio/openbsd

pre-configure:
	# We used to remove bundled libraries to be sure that iridium uses
	# system libraries and not shippen ones.
	# cd ${WRKSRC} && ${PYTHON_CMD} \
	#./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		ffmpeg flac harfbuzz-ng libwebp libxml libxslt snappy yasm || ${FALSE}

do-configure:
	# GN generator bootstrapping and generating ninja files
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
		READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./out/${BUILDTYPE}/gn \
		gen --args='${GN_ARGS}' out/${BUILDTYPE}

	# Setup nodejs dependency
	@${MKDIR} ${WRKSRC}/third_party/node/linux/node-linux-x64/bin
	${LN} -sf ${LOCALBASE}/bin/node ${WRKSRC}/third_party/node/linux/node-linux-x64/bin/node

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for m in font_service test_ime_driver ui
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${m}.service \
		${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${STAGEDIR}${MANPREFIX}/man/man1/iridium.1
.for s in 22 24 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/iridium.png
.endfor
.for p in chrome_100_percent chrome_200_percent headless_lib keyboard_resources \
	resources mus_app_resources_100 mus_app_resources_200 mus_app_resources_strings \
	views_mus_resources
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${p}.pak \
		${STAGEDIR}${DATADIR}
.endfor
.for d in icudtl.dat natives_blob.bin snapshot_blob.bin
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${d} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chrome \
		${STAGEDIR}${DATADIR}/iridium
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/iridium-browser.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/iridium ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/mksnapshot \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

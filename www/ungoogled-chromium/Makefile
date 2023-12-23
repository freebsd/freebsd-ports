PORTNAME=	ungoogled-chromium
PORTVERSION=	120.0.6099.129
UGVERSION=	${DISTVERSION}-1
CATEGORIES=	www wayland
MASTER_SITES=	https://commondatastorage.googleapis.com/chromium-browser-official/ \
		https://nerd.hu/distfiles/:external
DISTFILES=	chromium-${DISTVERSION}${EXTRACT_SUFX} \
		ungoogled-chromium-${UGVERSION}.tar.gz:external

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Google web browser based on WebKit sans integration with Google
WWW=		https://github.com/ungoogled-software/ungoogled-chromium

LICENSE=	BSD3CLAUSE LGPL21 MPL11
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 i386

PATCH_DEPENDS=	gpatch:devel/patch \
		${PYTHON_VERSION}:lang/python${PYTHON_SUFFIX}

BUILD_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		gperf:devel/gperf \
		flock:sysutils/flock \
		node:www/node \
		xcb-proto>0:x11/xcb-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${LOCALBASE}/include/va/va.h:multimedia/libva \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri \
		${LOCALBASE}/libdata/pkgconfig/Qt5Core.pc:devel/qt5-core \
		${LOCALBASE}/libdata/pkgconfig/Qt5Widgets.pc:x11-toolkits/qt5-widgets

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libspeechd.so:accessibility/speech-dispatcher \
		libsnappy.so:archivers/snappy \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libspeex.so:audio/speex \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
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
		libdav1d.so:multimedia/dav1d \
		libopenh264.so:multimedia/openh264 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		noto-basic>0:x11-fonts/noto-basic

USES=		bison compiler:c++17-lang cpe desktop-file-utils gl gmake gnome \
		iconv:wchar_t jpeg localbase:ldflags ninja perl5 pkgconfig \
		python:build qt:5 shebangfix tar:xz xorg

CPE_VENDOR=	google
CPE_PRODUCT=	chrome
USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf2 glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xorgproto xrandr xrender xscrnsaver xtst
USE_QT=		buildtools:build
SHEBANG_FILES=	chrome/tools/build/linux/chrome-wrapper buildtools/linux64/clang-format

MAKE_ARGS=	-C out/${BUILDTYPE}
ALL_TARGET=	chrome

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		moc=${PREFIX}/bin/moc-qt5

# TODO bz@ : install libwidevinecdm.so (see third_party/widevine/cdm/BUILD.gn)
#
# Run "./out/${BUILDTYPE}/gn args out/${BUILDTYPE} --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	enable_widevine=true \
		fatal_linker_warnings=false \
		icu_use_data_file=false \
		is_clang=true \
		optimize_webui=true \
		toolkit_views=true \
		use_allocator_shim=false \
		use_aura=true \
		use_custom_libcxx=false \
		use_lld=true \
		use_partition_alloc=true \
		use_partition_alloc_as_malloc=false \
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}" \
		ffmpeg_branding="${FFMPEG_BRAND}"

# sync with flags.gni
GN_ARGS+=	build_with_tflite_lib=false \
		chrome_pgo_phase=0 \
		clang_use_chrome_plugins=false \
		disable_fieldtrial_testing_config=true \
		enable_backup_ref_ptr_support=false \
		enable_hangout_services_extension=false \
		enable_mdns=false \
		enable_nacl=false \
		enable_reading_list=false \
		enable_remoting=false \
		enable_reporting=false \
		enable_rust=false \
		enable_service_discovery=false \
		exclude_unwind_tables=true \
		google_api_key="" \
		google_default_client_id="" \
		google_default_client_secret="" \
		safe_browsing_mode=0 \
		treat_warnings_as_errors=false \
		use_official_google_api_keys=false \
		use_unofficial_version_number=false

# TODO: investigate building with these options:
# use_system_minigbm
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

SUB_FILES=	ungoogled-chromium.desktop ungoogled-chromium
SUB_LIST+=	COMMENT="${COMMENT}"

OPTIONS_DEFINE=		CODECS CUPS DEBUG DRIVER KERBEROS LTO PIPEWIRE TEST WIDEVINE
OPTIONS_DEFAULT=	CODECS CUPS DRIVER KERBEROS PIPEWIRE SNDIO
OPTIONS_EXCLUDE_aarch64=LTO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	HEIMDAL HEIMDAL_BASE MIT
OPTIONS_SUB=		yes
CODECS_DESC=		Compile and enable patented codecs like H.264
DRIVER_DESC=		Install chromedriver
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
MIT_DESC=		MIT Kerberos (security/krb5)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
			alsa-lib>=1.1.1_1:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		GN_ARGS+=proprietary_codecs=true \
			FFMPEG_BRAND="Chrome"
CODECS_VARS_OFF=	GN_ARGS+=proprietary_codecs=false \
			FFMPEG_BRAND="Chromium"

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

DEBUG_BUILD_DEPENDS=	esbuild:devel/esbuild
DEBUG_VARS=		BUILDTYPE=Debug \
			GN_ARGS+=is_debug=true \
			GN_ARGS+=is_component_build=false \
			GN_ARGS+=symbol_level=1 \
			GN_BOOTSTRAP_FLAGS+=--debug \
			WANTSPACE="21 GB"
DEBUG_VARS_OFF=		BUILDTYPE=Release \
			GN_ARGS+=blink_symbol_level=0 \
			GN_ARGS+=is_debug=false \
			GN_ARGS+=is_official_build=true \
			GN_ARGS+=symbol_level=0 \
			WANTSPACE="14 GB"

DRIVER_MAKE_ARGS=	chromedriver

HEIMDAL_LIB_DEPENDS=	libkrb.so.26:security/heimdal
KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

LTO_VARS=		GN_ARGS+=use_thin_lto=true \
			GN_ARGS+=thin_lto_enable_optimizations=true \
			WANTSPACE="14 GB"
LTO_VARS_OFF=		GN_ARGS+=use_thin_lto=false

MIT_LIB_DEPENDS=	libkrb.so.3:security/krb5

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		GN_ARGS+=rtc_use_pipewire=true \
			GN_ARGS+=rtc_link_pipewire=true
PIPEWIRE_VARS_OFF=	GN_ARGS+=rtc_use_pipewire=false \
			GN_ARGS+=rtc_link_pipewire=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

# With SNDIO=on we exclude audio_manager_linux from the build (see
# media/audio/BUILD.gn) and use audio_manager_openbsd which does not
# support falling back to ALSA or PulseAudio.
SNDIO_PREVENTS=		ALSA PULSEAUDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

WIDEVINE_DESC=		Depend on foreign-cdm to enable playback of DRM content
WIDEVINE_RUN_DEPENDS=	foreign-cdm>0:www/foreign-cdm

.include "Makefile.tests"
TEST_DISTFILES=		chromium-${DISTVERSION}-testdata${EXTRACT_SUFX} \
			test_fonts-336e775eec536b2d785cc80eff6ac39051931286.tar.gz:external
TEST_ALL_TARGET=	${TEST_TARGETS}

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk> # for COMPILER_VERSION

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && !exists(/usr/lib/libkrb5.so)
IGNORE=		you have selected HEIMDAL_BASE but do not have Heimdal installed in base
.endif

.if ${COMPILER_VERSION} < 160
LLVM_DEFAULT=		16
BUILD_DEPENDS+=		clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
			cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
			c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
			ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
			nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
			ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
.else
BINARY_ALIAS+=		ar=/usr/bin/llvm-ar \
			nm=/usr/bin/llvm-nm
.endif

# - swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
# - map ffmpeg target to ${ARCH}
.if ${ARCH} == aarch64
PLIST_SUB+=	NOT_AARCH64="@comment "
FFMPEG_TARGET=	arm64
.elif ${ARCH} == amd64
BUILD_DEPENDS+=	nasm:devel/nasm
PLIST_SUB+=	NOT_AARCH64=""
FFMPEG_TARGET=	x64
.elif ${ARCH} == i386
BUILD_DEPENDS+=	nasm:devel/nasm
PLIST_SUB+=	NOT_AARCH64=""
FFMPEG_TARGET=	ia32
.endif

FFMPEG_BDIR=	${WRKSRC}/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

# Allow relocations against read-only segments (override lld default)
LDFLAGS_i386=	-Wl,-znotext

# TODO: -isystem, would be just as ugly as this approach, but more reliably
# build would fail without C_INCLUDE_PATH/CPLUS_INCLUDE_PATH env var set.
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include

WRKSRC=		${WRKDIR}/chromium-${DISTVERSION}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Ungoogled Chromium, you should have around 2GB of memory"
	@${ECHO_MSG} "and around ${WANTSPACE} of free disk space."
	@${ECHO_MSG}

post-extract-TEST-on:
	@${MKDIR} ${WRKSRC}/third_party/test_fonts/test_fonts
	@${MV} ${WRKDIR}/test_fonts ${WRKSRC}/third_party/test_fonts/

pre-patch:
	cd ${WRKDIR}/ungoogled-chromium-${UGVERSION} && ${PYTHON_CMD} \
		utils/prune_binaries.py ${WRKSRC} pruning.list
	cd ${WRKDIR}/ungoogled-chromium-${UGVERSION} && PATCH_BIN=gpatch \
		${PYTHON_CMD} utils/patches.py apply ${WRKSRC} patches
	cd ${WRKDIR}/ungoogled-chromium-${UGVERSION} && ${PYTHON_CMD} \
		utils/domain_substitution.py apply -r domain_regex.list -f \
		domain_substitution.list -c ${WRKSRC}/domsubcache.tar.gz ${WRKSRC}

pre-configure:
	# We used to remove bundled libraries to be sure that chromium uses
	# system libraries and not shipped ones.
	# cd ${WRKSRC} && ${PYTHON_CMD} \
	#./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig freetype harfbuzz-ng icu libdrm libevent libpng \
		libusb libwebp libxml libxslt openh264 opus snappy || ${FALSE}
	# Chromium uses an unreleased version of FFmpeg, so configure it
	cd ${WRKSRC}/third_party/ffmpeg && \
		${PYTHON_CMD} chromium/scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${MKDIR} ${FFMPEG_CDIR}
.for _e in config.h config.asm config_components.h libavcodec libavformat libavutil
	-${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor

do-configure:
	# GN generator bootstrapping and generating ninja files
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
		READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./out/${BUILDTYPE}/gn \
		gen --args='${GN_ARGS}' out/${BUILDTYPE}

	# Setup nodejs dependency
	@${MKDIR} ${WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node ${WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node

	# Setup buildtools/freebsd
	@${MKDIR} ${WRKSRC}/buildtools/freebsd
	${LN} -sf ${WRKSRC}/buildtools/linux64/clang-format ${WRKSRC}/buildtools/freebsd
	${LN} -sf ${WRKSRC}/out/${BUILDTYPE}/gn ${WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${WRKSRC}/buildtools/freebsd/strip

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/chrome/app/resources/manpage.1.in \
		${STAGEDIR}${MANPREFIX}/man/man1/ungoogled-chromium.1
	@${SED} -i "" -e 's,\@\@PACKAGE\@\@,chromium,g;s,\@\@MENUNAME\@\@,Chromium Web Browser,g' \
		${STAGEDIR}${MANPREFIX}/man/man1/ungoogled-chromium.1
	${CP} ${WRKSRC}/chrome/app/theme/chromium/product_logo_22_mono.png ${WRKSRC}/chrome/app/theme/chromium/product_logo_22.png
.for s in 22 24 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/ungoogled-chromium.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*.pak ${STAGEDIR}${DATADIR}
.for d in protoc mksnapshot
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${d} ${STAGEDIR}${DATADIR}
.endfor
.for d in snapshot_blob.bin v8_context_snapshot.bin
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${d} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chrome \
		${STAGEDIR}${DATADIR}/ungoogled-chromium
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/ungoogled-chromium.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/ungoogled-chromium ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/chrome/tools/build/linux/chrome-wrapper \
		${STAGEDIR}${DATADIR}

	# ANGLE, EGL, Vk
.for f in libEGL.so libGLESv2.so libVkICD_mock_icd.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 \
		${STAGEDIR}${DATADIR}/libvulkan.so
.if ${BUILDTYPE} == Debug
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libVkLayer_khronos_validation.so ${STAGEDIR}${DATADIR}
.endif

	# SwiftShader
.if ${ARCH} != aarch64
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvk_swiftshader.so ${STAGEDIR}${DATADIR}
.endif

post-install-DEBUG-on:
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/*.so \
		${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/character_data_generator \
		${STAGEDIR}${DATADIR}

post-install-DRIVER-on:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chromedriver \
		${STAGEDIR}${PREFIX}/bin/ungoogled-chromedriver

do-test-TEST-on:
.for t in ${TEST_TARGETS}
	cd ${WRKSRC}/out/${BUILDTYPE} && ${SETENV} LC_ALL=en_US.UTF-8 \
		./${t} --gtest_filter=-${EXCLUDE_${t}:ts:} || ${TRUE}
.endfor

.include <bsd.port.post.mk>

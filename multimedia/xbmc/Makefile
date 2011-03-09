# New ports collection makefile for:    xbmc
# Date created:				2010-09-16
# Whom: 				Mickael Maillot <mickael.maillot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xbmc
PORTVERSION=	10.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.xbmc.org/releases/source/

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	XBMC is an award winning media center application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	enca:${PORTSDIR}/converters/enca \
		gawk:${PORTSDIR}/lang/gawk \
		gperf:${PORTSDIR}/devel/gperf \
		cmake:${PORTSDIR}/devel/cmake \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib	\
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		cdio.12:${PORTSDIR}/sysutils/libcdio	\
		curl.6:${PORTSDIR}/ftp/curl \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		enca.5:${PORTSDIR}/converters/enca \
		GLEW.1:${PORTSDIR}/graphics/glew \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg	\
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		faad.2:${PORTSDIR}/audio/faad \
		mad:${PORTSDIR}/audio/libmad \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.7:${PORTSDIR}/audio/libogg \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.6:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient	\
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		wavpack.2:${PORTSDIR}/audio/wavpack \
		Xtst:${PORTSDIR}/x11/libXtst

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

FETCH_ARGS=	-Fpr
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xinerama xt xmu xrandr
USE_GL=		glu
USE_SDL=	image mixer sdl
USE_MYSQL=	yes
USE_PYTHON=	2.5-2.7
MAKE_JOBS_SAFE=	yes
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	${PREFIX}/lib/xbmc/system \
		${PREFIX}/lib/xbmc/system/players/dvdplayer \
		${PREFIX}/lib/xbmc/system/players/paplayer

USE_DOS2UNIX=	xbmc/lib/libid3tag/libid3tag/compat.gperf
PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/python//:S/.//g}"

OPTIONS=	AVAHI		"Enable Avahi support"			on \
		LIBBLURAY	"Enable libbluray support"		on \
		FAAC		"Enable FAAC support"			off \
		HAL		"Enable HAL support"			on \
		LIRC		"Enable lirc support"			off \
		MMS		"Enable mms:// & mmsh:// support"	on \
		NONFREE		"Enable non-free components (rar, ccx, ffmpeg)"	off \
		PULSE		"Enable PulseAudio support"		off \
		RTMP		"RTMP support via librtmp"		off \
		VDPAU		"Enable VDPAU support"			off \
		WEBSERVER	"Build Internal Webserver"		off

DESKTOP_ENTRIES="XBMC" \
		"${COMMENT}" \
		"${DATADIR}/media/icon.png" \
		"xbmc" \
		"AudioVideo;Video;" \
		true

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS+=	--enable-external-libraries

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if !defined(WITHOUT_AVAHI)
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=	avahi-common.3:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !defined(WITHOUT_LIBBLURAY)
CONFIGURE_ARGS+=	--enable-libbluray
LIB_DEPENDS+=	bluray.0:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

.if defined(WITH_FAAC)
CONFIGURE_ARGS+=	--enable-faac
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=	--enable-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if defined(WITH_LIRC)
RUN_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
.endif

.if !defined(WITHOUT_MMS)
CONFIGURE_ARGS+=	--enable-libmms
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
.else
CONFIGURE_ARGS+=	--disable-libmms
.endif

.if defined(WITH_NONFREE)
CONFIGURE_ARGS+=	--enable-non-free
NO_CDROM=	Restricted binary distribution
NO_PACKAGE=	${NO_CDROM}
.else
CONFIGURE_ARGS+=	--disable-non-free
.endif

.if defined(WITH_PULSE)
CONFIGURE_ARGS+=	--enable-pulse
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if defined(WITH_RTMP)
CONFIGURE_ARGS+=	--enable-rtmp
LIB_DEPENDS+=	rtmp.0:${PORTSDIR}/multimedia/rtmpdump
.else
CONFIGURE_ARGS+=	--disable-rtmp
.endif

.if defined(WITH_VDPAU)
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if defined(WITH_WEBSERVER)
CONFIGURE_ARGS+=	--enable-webserver
LIB_DEPENDS+=	microhttpd.12:${PORTSDIR}/www/libmicrohttpd
PLIST_SUB+=	HTTPD=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=	HTTPD="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure.in \
		${WRKSRC}/lib/enca/configure \
		${WRKSRC}/lib/freetype/builds/unix/configure \
		${WRKSRC}/lib/fribidi/configure \
		${WRKSRC}/lib/libcdio/configure \
		${WRKSRC}/lib/libcdio/libcdio.pc \
		${WRKSRC}/lib/libcdio/libcdio_cdda.pc \
		${WRKSRC}/lib/libcdio/libiso9660.pc \
		${WRKSRC}/lib/libiconv/Makefile.in \
		${WRKSRC}/lib/libiconv/configure \
		${WRKSRC}/lib/libiconv/lib/Makefile.in \
		${WRKSRC}/lib/libiconv/libcharset/Makefile.in \
		${WRKSRC}/lib/libiconv/libcharset/configure \
		${WRKSRC}/lib/libiconv/libcharset/lib/Makefile.in \
		${WRKSRC}/lib/libiconv/man/Makefile.in \
		${WRKSRC}/lib/libiconv/preload/Makefile.in \
		${WRKSRC}/lib/libiconv/preload/configure \
		${WRKSRC}/lib/libiconv/src/Makefile.in \
		${WRKSRC}/lib/liblame/configure \
		${WRKSRC}/lib/libmicrohttpd/configure \
		${WRKSRC}/lib/libmodplug/configure \
		${WRKSRC}/lib/libmodplug/src/load_pat.cpp \
		${WRKSRC}/lib/pcre/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/ffmpeg/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/liba52/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdts/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/configure.ac \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/configure2 \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/doc/doxy.conf \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdread/configure.ac \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdread/configure2 \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libfaad2/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libmad/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libmpeg2/configure \
		${WRKSRC}/xbmc/cores/dvdplayer/Codecs/libmpeg2/test/compile \
		${WRKSRC}/xbmc/cores/paplayer/FLACCodec/flac-1.2.1/configure \
		${WRKSRC}/xbmc/cores/paplayer/SIDCodec/libsidplay/unix/libsidplay2.pc \
		${WRKSRC}/xbmc/cores/paplayer/asap/Makefile.in \
		${WRKSRC}/xbmc/cores/paplayer/timidity/configure.in \
		${WRKSRC}/xbmc/cores/paplayer/vorbisfile/libvorbis/configure \
		${WRKSRC}/xbmc/cores/paplayer/vorbisfile/ogg/configure \
		${WRKSRC}/xbmc/lib/UnrarXLib/pathfn.cpp \
		${WRKSRC}/xbmc/lib/cximage-6.0/zlib/Makefile.in \
		${WRKSRC}/xbmc/lib/cximage-6.0/zlib/configure \
		${WRKSRC}/xbmc/lib/libPython/Python/configure.in \
		${WRKSRC}/xbmc/lib/libPython/Python/setup.py \
		${WRKSRC}/xbmc/lib/libUPnP/Neptune/ThirdParty/axTLS/config/config.h \
		${WRKSRC}/xbmc/lib/libapetag/configure \
		${WRKSRC}/xbmc/lib/libid3tag/libid3tag/configure \
		${WRKSRC}/xbmc/lib/libid3tag/zlib/Makefile \
		${WRKSRC}/xbmc/lib/libid3tag/zlib/Makefile.in \
		${WRKSRC}/xbmc/lib/libid3tag/zlib/configure \
		${WRKSRC}/xbmc/lib/libmms/glib-2.20.4/glib/gutils.c \
		${WRKSRC}/xbmc/lib/libsamplerate/configure \
		${WRKSRC}/xbmc/lib/libsquish/config \
		${WRKSRC}/xbmc/screensavers/rsxs-0.9/configure \
		${WRKSRC}/xbmc/visualizations/Goom/goom2k4-0/configure \
		${WRKSRC}/xbmc/visualizations/Goom/goom2k4-0/gtk-gui-devel/configure
	@${REINPLACE_CMD} -e "s;python2\.6;${PYTHON_VERSION};" \
		-e "s;HAVE_LIBPYTHON2_6;HAVE_LIB${PYTHON_VERSION:U:S/./_/g};" \
		${WRKSRC}/xbmc/lib/libPython/XBPyThread.cpp \
		${WRKSRC}/xbmc/lib/libPython/XBPyThread.h \
		${WRKSRC}/xbmc/lib/libPython/XBPythonDll.cpp \
		${WRKSRC}/xbmc/lib/libPython/XBPythonDllFuncs.S \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/GUIPythonWindow.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/PythonAddon.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/PythonPlayer.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/action.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/control.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlbutton.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlcheckmark.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlfadelabel.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlgroup.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlimage.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controllabel.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controllist.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlprogress.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlradiobutton.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlslider.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controlspin.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/controltextbox.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/dialog.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/dialog.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/infotagmusic.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/infotagvideo.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/keyboard.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/listitem.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/listitem.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/player.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/pyplaylist.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/pyplaylist.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/pyutil.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/window.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/winxml.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/winxml.h \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/winxmldialog.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/xbmcaddonmodule.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/xbmcguimodule.cpp \
		${WRKSRC}/xbmc/lib/libPython/xbmcmodule/xbmcmodule.cpp

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.post.mk>

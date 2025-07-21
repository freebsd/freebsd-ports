PORTNAME=	mythtv
DISTVERSIONPREFIX=	v
DISTVERSION=	34.0
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	multimedia

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	Homebrew PVR project
WWW=		https://www.mythtv.org/

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment
.endif

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libmp3lame.so:audio/lame \
		libsamplerate.so:audio/libsamplerate \
		libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libva.so:multimedia/libva \
		libbluray.so:multimedia/libbluray \
		libass.so:multimedia/libass \
		libfftw3_threads.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfreetype.so:print/freetype2 \
		libdav1d.so:multimedia/dav1d \
		libaom.so:multimedia/aom \
		libdrm.so:graphics/libdrm \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libSoundTouch.so:audio/soundtouch \
		libasound.so:audio/alsa-lib \
		libsndio.so:audio/sndio \
		libgnutls.so:security/gnutls \
		libzip.so:archivers/libzip \
		libexpat.so:textproc/expat2
BUILD_DEPENDS=	yasm:devel/yasm \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		compiler:c++17-lang gmake gl gnome iconv libtool pkgconfig pathfix \
		perl5 python qmake:no_env qt:5 shebangfix ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
USE_GL=		gl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_QT=		buildtools:build core dbus gui imageformats:run \
		linguist:build multimedia network opengl qmake:build script \
		sql sql-mysql:run widgets xml
USE_PERL5=	run build
USE_XORG=	x11 xv xrandr xxf86vm xinerama xext xcb
SHEBANG_FILES=	programs/scripts/database/*.pl \
		programs/scripts/metadata/Music/mbutils.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" \
		--libxml2-path="${LOCALBASE}/include/libxml2" \
		--disable-audio-alsa \
		--disable-qtwebkit
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${PREFIX}" PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
MAKE_ENV=	QTDIR="${PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"
NOPRECIOUSMAKEVARS=	# don't override ARCH in ffmpeg makefiles
DESTDIRNAME=	INSTALL_ROOT
CFLAGS_powerpc=	-Wno-error=int-conversion
CPPFLAGS+=	${QTCPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS_aarch64=-Wl,-z,notext

REINPLACE_ARGS=	-i ""
WRKSRC_SUBDIR=	${PORTNAME}

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

CONFLICTS_INSTALL=	mythtv-frontend

RUN_DEPENDS+=	tv_check:textproc/p5-xmltv \
		wget:ftp/wget
USE_RC_SUBR=	mythbackend
SHEBANG_FILES=	programs/scripts/database/*.pl \
		programs/scripts/internetcontent/*.py \
		programs/scripts/internetcontent/*.pl \
		programs/scripts/internetcontent/nv_python_libs/*.py \
		programs/scripts/hardwareprofile/*.py \
		programs/scripts/metadata/Movie/tmdb3.py \
		programs/scripts/metadata/Music/mbutils.py

CONFIGURE_ARGS+=--dvb-path="${WRKSRC}/media_tree/include/uapi" \
		--enable-v4l2

USERS=		mythtv
GROUPS=		mythtv

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		BINDINGS HDHOMERUN JACK LIRC MYSQL PULSEAUDIO VDPAU
OPTIONS_DEFAULT=	BINDINGS HDHOMERUN VDPAU
OPTIONS_SUB=		yes

BINDINGS_DESC=		Perl and Python bindings
BINDINGS_BUILD_DEPENDS=	${PY_SETUPTOOLS} \
			${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR} \
			p5-DBI>=0:databases/p5-DBI \
			${DBD_MYSQL} \
			p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
			p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
			p5-XML-Simple>=0:textproc/p5-XML-Simple \
			p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
			p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined
BINDINGS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.2.2:databases/py-mysqlclient@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests-cache>0:www/py-requests-cache@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}simplejson>=3:devel/py-simplejson@${PY_FLAVOR} \
			p5-DBI>=0:databases/p5-DBI \
			${DBD_MYSQL} \
			p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
			p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
			p5-XML-Simple>=0:textproc/p5-XML-Simple \
			p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
			p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined
BINDINGS_CONFIGURE_ON=	--python="${PYTHON_CMD}" --with-bindings=perl,python
BINDINGS_CONFIGURE_OFF=	--without-bindings=perl,python
BINDINGS_USES=		mysql

HDHOMERUN_DESC=		Native support for HDHomeRun network tuners
HDHOMERUN_LIB_DEPENDS=	libhdhomerun.so:multimedia/libhdhomerun
HDHOMERUN_CONFIGURE_OFF=	--disable-hdhomerun

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-audio-jack

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_OFF=	--disable-lirc

MYSQL_DESC=		Install MySQL server in addition to client
MYSQL_USES=		mysql:client,server
MYSQL_USES_OFF=		mysql

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-audio-pulseoutput

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_OFF=	--disable-vdpau

LINUXDVB=	${WRKSRC}/media_tree/include/uapi/linux/dvb

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/libs/libmythtv/libmythtv.pro \
		${WRKSRC}/bindings/perl/MythTV/Recording.pm \
		${WRKSRC}/programs/mythtranscode/external/replex/Makefile.standalone \
		${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
		${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
		${WRKSRC}/programs/mythcommflag/mythcommflag-analyze
	# Header file from:
	# https://git.linuxtv.org/media_tree.git/tree/include/uapi/linux/dvb
	@${MKDIR} ${LINUXDVB}
	@${CP} ${FILESDIR}/audio.h ${LINUXDVB}
	@${CP} ${FILESDIR}/ca.h ${LINUXDVB}
	@${CP} ${FILESDIR}/dmx.h ${LINUXDVB}
	@${CP} ${FILESDIR}/frontend.h ${LINUXDVB}
	@${CP} ${FILESDIR}/net.h ${LINUXDVB}
	@${CP} ${FILESDIR}/osd.h ${LINUXDVB}
	@${CP} ${FILESDIR}/version.h ${LINUXDVB}
	@${CP} ${FILESDIR}/video.h ${LINUXDVB}
	# Linux to BSD from multimedia/libv4l/Makefile
	@${FIND} ${LINUXDVB} -type f -name "*.h" | \
		${XARGS} -n 1 ${REINPLACE_CMD} \
		-e 's|#include <linux/types.h>|#include <sys/types.h>|'\
		-e 's|__inline__|inline|g' \
		-e 's|__u8|uint8_t|g' \
		-e 's|__s8|int8_t|g' \
		-e 's|__le16|uint16_t|g' \
		-e 's|__be16|uint16_t|g' \
		-e 's|__u16|uint16_t|g' \
		-e 's|__s16|int16_t|g' \
		-e 's|__le32|uint32_t|g' \
		-e 's|__be32|uint32_t|g' \
		-e 's|__u32|uint32_t|g' \
		-e 's|__s32|int32_t|g' \
		-e 's|__le64|uint64_t|g' \
		-e 's|__be64|uint64_t|g' \
		-e 's|__u64|uint64_t|g' \
		-e 's|__s64|int64_t|g' \
		-e 's|uint16_t_to_cpu|letoh16|g' \
		-e 's|uint32_t_to_cpu|letoh32|g' \
		-e 's|uint64_t_to_cpu|letoh64|g' \
		-e 's|error_t|int|g' \
		-e 's|"gettext.h"|<stdio.h>|g' \
		-e 's|MSG_MORE|0|g' \
		-e 's|EBADR|EFAULT|g' \
		-e 's|ENONET|EHOSTDOWN|g' \
		-e 's|_IOC_READ|IOC_OUT|g' \
		-e 's|_IOC_WRITE|IOC_IN|g' \
		-e 's|_IOC_NONE|IOC_VOID|g' \
		-e 's|<endian.h>|<sys/endian.h>|g' \
		-e 's|<linux/compiler.h>|<sys/cdefs.h>|g' \
		-e 's|<linux/errno.h>|<errno.h>|g' \
		-e 's|<linux/ioctl.h>|<sys/ioctl.h>|g' \
		-e '/^.*\<linux\/kernel.h\>.*/d' \
		-e 's|<linux/string.h>|<string.h>|g' \
		-e 's|<linux/sysmacros.h>|<sys/types.h>|g' \
		-e 's|<malloc.h>|<stdlib.h>|g' \
		-e 's|<sys/epoll.h>|<libepoll-shim/sys/epoll.h>|g' \
		-e 's|<sys/sysmacros.h>|<sys/types.h>|g' \
		-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		-e 's|__user||g' \
		${LINUXDVB}/frontend.h

pre-install:
	@${REINPLACE_CMD} -e '/^CPPFLAGS=/ s#$$# -I${LOCALBASE}/include#' \
		${WRKSRC}/libs/libmythbase/mythconfig.mak

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mythtv/database
	${INSTALL_DATA} ${WRKSRC}/database/mc.sql ${STAGEDIR}${PREFIX}/share/mythtv/database
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type f -exec ${SH} -c "${FILE} -i '{}' | \
		${GREP} -q 'x-executable; charset=binary'" \; -print | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -name lib\*.so.\* | ${XARGS} ${STRIP_CMD}

# Apply additional substitutions to pkg-plist generated by the 'makeplist' target
create-plist: stage
	@(cd ${.CURDIR} && ${MAKE} makeplist > pkg-plist && \
		${REINPLACE_CMD} -E \
		-e '1d' -e '/etc\/rc.d\/mythbackend/d' -e '/[.]packlist$$/d' \
		-e '/[.]bak$$/d' \
		-e '/[.]gitignore$$/d' \
		-e 's#^bin/mythpython#%%BINDINGS%%bin/mythpython#' \
		-e 's#^bin/mythwikiscripts#%%BINDINGS%%bin/mythwikiscripts#' \
		-e 's#^%%PYTHON_SITELIBDIR%%#%%BINDINGS%%%%PYTHON_SITELIBDIR%%#' \
		-e 's#^%%DATADIR%%hardwareprofile#%%BINDINGS%%hardwareprofile#' \
		-e 's#^%%DATADIR%%internetcontent#%%BINDINGS%%internetcontent#' \
		-e 's#^%%SITE_PERL%%#%%BINDINGS%%%%SITE_PERL%%#' \
		pkg-plist)

.include <bsd.port.mk>

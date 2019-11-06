# Created by: Stacey Son <mythdev@son.org>, Ari Maniatis <ari@ish.com.au>
# $FreeBSD$

PORTNAME=	mythtv
DISTVERSIONPREFIX=	v
DISTVERSION=	30.0
PORTREVISION?=	4
PORTEPOCH=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	aab7d3f065a7.patch:-p2

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	MythTV is a homebrew PVR project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment
.endif

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libmp3lame.so:audio/lame \
		libsamplerate.so:audio/libsamplerate \
		libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libva.so:multimedia/libva \
		libva-glx.so:multimedia/libva-glx \
		libbluray.so:multimedia/libbluray \
		libass.so:multimedia/libass \
		libfftw3_threads.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfreetype.so:print/freetype2 \
		libxml2.so:textproc/libxml2
BUILD_DEPENDS=	yasm:devel/yasm \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		gmake gl iconv libtool pkgconfig pathfix qmake:no_env qt:5 ssl \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core dbus gui imageformats_run \
		linguist_build network opengl qmake_build script sql \
		sql-mysql_run webkit widgets xml
USE_XORG=	x11 xv xrandr xxf86vm xinerama xext xcb

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" \
		--libxml2-path="${LOCALBASE}/include/libxml2" \
		--enable-opengl-video \
		--disable-audio-alsa --disable-indev=alsa \
		--disable-outdev=alsa
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${PREFIX}" PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
MAKE_ENV=	QTDIR="${PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"
NOPRECIOUSMAKEVARS=	# don't override ARCH in ffmpeg makefiles
DESTDIRNAME=	INSTALL_ROOT
CPPFLAGS+=	${QTCPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

REINPLACE_ARGS=	-i ""
WRKSRC_SUBDIR=	${PORTNAME}

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

.if defined(SLAVEPORT) && ${SLAVEPORT} == "frontend"
CONFLICTS_INSTALL=	mythtv

CONFIGURE_ARGS+=--disable-dvb --disable-firewire --disable-hdhomerun \
		--disable-hdpvr --disable-ivtv --disable-v4l2 \
		--without-bindings=perl,python,php

EXTRA_PATCHES=	${FILESDIR}/extrapatch-programs_programs.pro

OPTIONS_EXCLUDE+=	BINDINGS LIRC MYSQL
.else
CONFLICTS_INSTALL=	mythtv-frontend

BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
RUN_DEPENDS+=	tv_check:textproc/p5-xmltv \
		wget:ftp/wget
USES+=		perl5 python:2.7 shebangfix
USE_PERL5=	run build
USE_RC_SUBR=	mythbackend
SHEBANG_FILES=	programs/scripts/database/*.pl \
		programs/scripts/internetcontent/*.py \
		programs/scripts/internetcontent/*.pl \
		programs/scripts/internetcontent/nv_python_libs/*.py \
		programs/scripts/hardwareprofile/*.py \
		programs/scripts/metadata/Television/ttvdb.py \
		programs/scripts/metadata/Movie/tmdb3.py \
		programs/scripts/metadata/Music/mbutils.py

CONFIGURE_ARGS+=--dvb-path="${LOCALBASE}/include" \
		--enable-ivtv --enable-v4l2 --enable-xv

USERS=		mythtv
GROUPS=		mythtv

DATADIR=	${PREFIX}/share/mythtv
SUB_FILES=	pkg-message
.endif

OPTIONS_DEFINE=		BINDINGS HDHOMERUN JACK LIRC MYSQL PULSEAUDIO VDPAU
OPTIONS_DEFAULT=	BINDINGS HDHOMERUN VDPAU
OPTIONS_SUB=		yes

BINDINGS_DESC=		Perl and Python bindings
BINDINGS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:www/py-urlgrabber@${PY_FLAVOR} \
			p5-DBI>=0:databases/p5-DBI \
			p5-DBD-mysql>0:databases/p5-DBD-mysql \
			p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
			p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
			p5-XML-Simple>=0:textproc/p5-XML-Simple \
			p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
			p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined
BINDINGS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
			${PY_FUTURES} \
			${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests-cache>0:www/py-requests-cache@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:www/py-urlgrabber@${PY_FLAVOR} \
			p5-DBI>=0:databases/p5-DBI \
			p5-DBD-mysql>0:databases/p5-DBD-mysql \
			p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
			p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
			p5-XML-Simple>=0:textproc/p5-XML-Simple \
			p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
			p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined
BINDINGS_CONFIGURE_ON=	--python=${PYTHON_CMD}
BINDINGS_CONFIGURE_OFF=	--without-bindings=perl,python

HDHOMERUN_DESC=		Native support for HDHomeRun network tuners
HDHOMERUN_LIB_DEPENDS=	libhdhomerun.so:multimedia/libhdhomerun
HDHOMERUN_CONFIGURE_OFF=	--disable-hdhomerun

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ON=	--enable-audio-jack --enable-indev=jack
JACK_CONFIGURE_OFF=	--disable-audio-jack --disable-indev=jack

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc

MYSQL_DESC=		Install MySQL server in addition to client
MYSQL_USES=		mysql:client,server
MYSQL_USES_OFF=		mysql

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	audio-pulse audio-pulseoutput

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/libs/libmythtv/libmythtv.pro \
		${WRKSRC}/bindings/perl/MythTV/Recording.pm \
		${WRKSRC}/programs/mythtranscode/external/replex/Makefile.standalone \
		${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
		${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
		${WRKSRC}/programs/mythcommflag/mythcommflag-analyze

post-install:
.if !defined(SLAVEPORT)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mythtv/database
	${INSTALL_DATA} ${WRKSRC}/database/mc.sql ${STAGEDIR}${PREFIX}/share/mythtv/database
.endif
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type f -exec ${SH} -c "${FILE} -i '{}' | \
		${GREP} -q 'x-executable; charset=binary'" \; -print | ${XARGS} ${STRIP_CMD}
	@(cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} lib/libmyth*.so lib/mythtv/filters/lib*.so)

# Apply additional substitutions to pkg-plist generated by the 'makeplist' target
create-plist: stage
	@(cd ${.CURDIR} && ${MAKE} makeplist > pkg-plist && \
	${REINPLACE_CMD} -E \
		-e '1d' -e '/etc\/rc.d\/mythbackend/d' -e '/packlist/d' \
		-e '/mythfrontend.desktop/d' \
		-e '/(^%%PYTHON_SITELIBDIR%%|^%%SITE_PERL%%|mythpython|mythwikiscripts)/s|^|%%BINDINGS%%|g' \
		pkg-plist)

.include <bsd.port.mk>

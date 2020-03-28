# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.3-784
DISTVERSIONSUFFIX=	-g981ecfca
PORTREVISION=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libopus.so:audio/opus \
		libqrencode.so:graphics/libqrencode \
		libsodium.so:security/libsodium \
		libsqlcipher.so:databases/sqlcipher \
		libtoxcore.so:net-im/tox \
		libvpx.so:multimedia/libvpx

USES=		cmake compiler:c++11-lib desktop-file-utils gettext openal:soft pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent_build buildtools_build linguisttools_build qmake_build testlib_build
CMAKE_ARGS=	-DGIT_DESCRIBE:STRING=${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
CMAKE_OFF=	USE_CCACHE

OPTIONS_DEFINE=			FILTERAUDIO PLATFORM_EXTENSIONS SPELL_CHECK APPINDICATOR GTK_SYSTRAY STATUSNOTIFIER
OPTIONS_DEFAULT=		FILTERAUDIO PLATFORM_EXTENSIONS SPELL_CHECK GTK_SYSTRAY STATUSNOTIFIER # removing GTK_SYSTRAY, STATUSNOTIFIER doesn't reduce dependencies
PLATFORM_EXTENSIONS_DESC=	Enable platform specific extensions
FILTERAUDIO_DESC=		Enable the echo canceling backend

FILTERAUDIO_CMAKE_BOOL=		USE_FILTERAUDIO
FILTERAUDIO_LIB_DEPENDS=	libfilteraudio.so:audio/libfilteraudio
PLATFORM_EXTENSIONS_CMAKE_BOOL=	PLATFORM_EXTENSIONS
PLATFORM_EXTENSIONS_USES=	xorg
PLATFORM_EXTENSIONS_USE=	XORG=x11,xscrnsaver

SPELL_CHECK_DESC=	Spell checking support
SPELL_CHECK_USES=	kde:5
SPELL_CHECK_USE=	KDE=sonnet
SPELL_CHECK_CMAKE_BOOL=	SPELL_CHECK

APPINDICATOR_CMAKE_BOOL=	ENABLE_APPINDICATOR
APPINDICATOR_BROKEN=	can not find appindicator-0.1

GTK_SYSTRAY_DESC=	Enable GTK systray
GTK_SYSTRAY_CMAKE_BOOL=	ENABLE_GTK_SYSTRAY
GTK_SYSTRAY_USES=	gnome
GTK_SYSTRAY_USE=	GNOME=atk,cairo,gdkpixbuf2,gtk20

STATUSNOTIFIER_DESC=	Enable status notifier
STATUSNOTIFIER_CMAKE_BOOL=	ENABLE_STATUSNOTIFIER
STATUSNOTIFIER_USES=	gnome
STATUSNOTIFIER_USE=	GNOME=atk,cairo,gdkpixbuf2,gtk20

PLIST_FILES=	bin/qtox \
		share/applications/io.github.qtox.qTox.desktop \
		share/icons/hicolor/scalable/apps/qtox.svgz \
		share/metainfo/io.github.qtox.qTox.appdata.xml
.for SZ in 14 16 22 24 32 36 48 64 72 96 128 192 256 512
PLIST_FILES+=	share/icons/hicolor/${SZ}x${SZ}/apps/qtox.png
.endfor

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc" && ${ARCH} == i386 && !${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
CFLAGS+=	-march=i586
.endif

.if !defined(DISTVERSIONSUFFIX)
FULLVERSION=	${PKGVERSION}
.else
FULLVERSION=	"${PKGVERSION} (rev.${DISTVERSIONSUFFIX:S/-g//})"
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: qTox won't build if the option NaCl was selected for Tox!"
	@${ECHO_MSG}

pre-configure:
	@${REINPLACE_CMD} '/Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/io.github.qtox.qTox.desktop

.include <bsd.port.post.mk>

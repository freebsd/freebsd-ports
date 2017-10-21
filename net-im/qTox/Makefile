# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.1
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libtoxcore.so:net-im/tox \
		libopencv_highgui.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libavcodec.so:multimedia/ffmpeg \
		libvpx.so:multimedia/libvpx \
		libfilteraudio.so:audio/libfilteraudio \
		libopus.so:audio/opus \
		libsodium.so:security/libsodium \
		libqrencode.so:graphics/libqrencode \
		libsqlcipher.so:databases/sqlcipher \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

OPTIONS_DEFINE=	PLATFORM_EXTENSIONS
OPTIONS_DEFAULT=PLATFORM_EXTENSIONS
PLATFORM_EXTENSIONS_DESC=	Enable platform specific extensions

USE_GITHUB=	yes
GH_ACCOUNT=	qTox
GH_TAGNAME=	cd8a7ad

USES=		compiler:c++11-lib desktop-file-utils gettext openal:soft pkgconfig cmake
USE_GNOME=	gtk20 cairo
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent_build buildtools_build linguisttools_build testlib_build
# bug#220813: qmake isn't needed, but build fails without qmake_build
USE_QT5+=	qmake_build
CMAKE_ARGS=	-DGIT_DESCRIBE:STRING=${FULLVERSION}
INSTALLS_ICONS=	yes

PLATFORM_EXTENSIONS_CMAKE_OFF=	-DPLATFORM_EXTENSIONS:BOOL=OFF
PLATFORM_EXTENSIONS_USE=	XORG=x11,xscrnsaver

PLIST_FILES=	bin/qtox \
		share/applications/qtox.desktop \
		share/icons/hicolor/scalable/apps/qtox.svgz \
		share/appdata/qTox.appdata.xml
.for SZ in 14 16 22 24 32 36 48 64 72 96 128 192 256 512
PLIST_FILES+=	share/icons/hicolor/${SZ}x${SZ}/apps/qtox.png
.endfor

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc" && ${ARCH} == i386 && !${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
CFLAGS+=	-march=i586
.endif

.if !defined(GH_TAGNAME)
FULLVERSION=	${PKGVERSION}
.else
FULLVERSION=	"${PKGVERSION} (rev.${GH_TAGNAME})"
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: qTox won't build if the option NaCl was selected for Tox!"
	@${ECHO_MSG}

pre-configure:
	@${REINPLACE_CMD} '/Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/qtox.desktop

.include <bsd.port.post.mk>

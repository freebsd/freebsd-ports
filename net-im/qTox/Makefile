# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
PORTVERSION=	1.11.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3

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

USE_GITHUB=	yes
GH_ACCOUNT=	qTox

SUB_FILES=	pkg-message

USES=		compiler:c++11-lib desktop-file-utils gettext openal:soft pkgconfig cmake
USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xscrnsaver
USE_GL=		gl
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg testlib \
		concurrent buildtools_build linguisttools_build
# bug#220813: qmake isn't needed, but the build fails without qmake_build
USE_QT5+=	qmake_build
CMAKE_ARGS=	-DGIT_DESCRIBE:STRING=${FULLVERSION}
INSTALLS_ICONS=	yes
ICON_SIZES=	14x14 16x16 22x22 24x24 32x32 36x36 48x48 64x64 72x72 96x96 128x128 192x192 256x256 512x512

PLIST_FILES=	bin/qtox \
		share/applications/qtox.desktop \
		share/icons/hicolor/scalable/apps/qtox.svgz \
		share/appdata/qTox.appdata.xml
.for SZ in ${ICON_SIZES}
PLIST_FILES+=	share/icons/hicolor/${SZ}/apps/qtox.png
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

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	@${GZIP_CMD} \
		< ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qtox.svg \
		> ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qtox.svgz
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qtox.svg
.for SZ in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/img/icons/${SZ}/qtox.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}/apps/qtox.png
.endfor

.include <bsd.port.post.mk>

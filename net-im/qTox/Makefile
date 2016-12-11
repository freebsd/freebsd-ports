# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libtoxcore.so:net-im/tox \
		libopencv_highgui.so:graphics/opencv2 \
		libopencv_core.so:graphics/opencv2-core \
		libavcodec.so:multimedia/ffmpeg \
		libvpx.so:multimedia/libvpx \
		libfilteraudio.so:audio/libfilteraudio \
		libsodium.so:security/libsodium \
		libqrencode.so:graphics/libqrencode \
		libsqlcipher.so:databases/sqlcipher \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	qTox

SUB_FILES=	pkg-message

USES=		compiler:c++11-lib desktop-file-utils gettext gmake openal:soft pkgconfig qmake
USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xscrnsaver
USE_GL=		gl
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent buildtools_build linguisttools_build
ICON_SIZES=	14x14 16x16 22x22 24x24 32x32 36x36 48x48 64x64 72x72 96x96 128x128 192x192 256x256 512x512
QMAKE_ARGS=	FREEBSD_PKGVERSION=${PKGVERSION}

PLIST_FILES=	bin/qtox \
		share/applications/qTox.desktop \
		share/icons/hicolor/scalable/apps/qtox.svgz
.for SZ in ${ICON_SIZES}
PLIST_FILES+=	share/icons/hicolor/${SZ}/apps/qtox.png
.endfor

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc" && ${ARCH} == i386 && !${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
CFLAGS+=	-march=i586
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: qTox won't build if the option NaCl was selected for Tox!"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$$$$system(git rev-parse HEAD)|"${GH_TAGNAME}"|' \
		${WRKSRC}/qtox.pro
	@${REINPLACE_CMD} -e 's|INCLUDEPATH += "/usr/include|INCLUDEPATH += "${LOCALBASE}/include|' \
		${WRKSRC}/qtox.pro
	@${REINPLACE_CMD} -e 's|INCLUDEPATH += "/usr/lib64|INCLUDEPATH += "${LOCALBASE}/lib|' \
		${WRKSRC}/qtox.pro
	@${REINPLACE_CMD} -e 's|INCLUDEPATH += "/usr/lib|INCLUDEPATH += "${LOCALBASE}/lib|' \
		${WRKSRC}/qtox.pro

pre-configure:
	@${REINPLACE_CMD} '/Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/qTox.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	@${GZIP_CMD} ${GZIP} < ${WRKSRC}/img/icons/qtox.svg > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qtox.svgz
.for SZ in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/img/icons/${SZ}/qtox.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}/apps/qtox.png
.endfor

.include <bsd.port.post.mk>

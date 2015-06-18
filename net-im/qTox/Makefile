# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
PORTVERSION=	0.150614
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libtoxcore.so:${PORTSDIR}/net-im/tox \
		libopencv_highgui.so:${PORTSDIR}/graphics/opencv \
		libopencv_core.so:${PORTSDIR}/graphics/opencv-core \
		libavcodec26.so:${PORTSDIR}/multimedia/ffmpeg26 \
		libvpx.so:${PORTSDIR}/multimedia/libvpx \
		libfilteraudio.so:${PORTSDIR}/audio/libfilteraudio \
		libsodium.so:${PORTSDIR}/security/libsodium \
		libqrencode.so:${PORTSDIR}/graphics/libqrencode

USE_GITHUB=	yes
GH_ACCOUNT=	tux3
GH_TAGNAME=	ce2c830

USES=		compiler:c++11-lib desktop-file-utils openal:soft qmake gmake
USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xscrnsaver
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent buildtools_build linguisttools_build
CXXFLAGS+=	-I${LOCALBASE}/include/ffmpeg26
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg26

PLIST_FILES=	bin/qtox \
		share/applications/qTox.desktop

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
	@${REINPLACE_CMD} -e 's|-lavformat -lavdevice -lavcodec -lavutil -lswscale|-lavformat26 -lavdevice26 -lavcodec26 -lavutil26 -lswscale26|' \
		${WRKSRC}/qtox.pro

pre-configure:
	@${REINPLACE_CMD} '/Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/qTox.desktop

.include <bsd.port.mk>

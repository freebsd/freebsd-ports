# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qTox
PORTVERSION=	0.141118
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	yuri@rawbw.com
COMMENT=	Qt 5 based Tox client

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libopencv_highgui.so:${PORTSDIR}/graphics/opencv \
		libopencv_core.so:${PORTSDIR}/graphics/opencv-core \
		libvpx.so:${PORTSDIR}/multimedia/libvpx \
		libsodium.so:${PORTSDIR}/security/libsodium
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	tux3
GH_COMMIT=	7c499c2
GH_TAGNAME=	${GH_COMMIT}
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets \
		concurrent buildtools_build linguisttools_build
USES=		compiler:c++11-lib desktop-file-utils openal:soft qmake gmake

PLIST_FILES=	bin/qtox \
		share/applications/qTox.desktop \
		share/pixmaps/qtox.png

post-patch:
	${REINPLACE_CMD} -e 's|$$$$system(git rev-parse HEAD)|"${GH_COMMIT}"|' \
		${WRKSRC}/qtox.pro

pre-configure:
	${CP} ${WRKSRC}/img/icon.png ${WRKSRC}/img/qtox.png
	${REINPLACE_CMD} '/Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/qTox.desktop

.include <bsd.port.mk>

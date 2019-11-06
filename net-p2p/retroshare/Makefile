# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	4
CATEGORIES=	net-p2p

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	428b331d8efe.patch:-p1

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libgnome-keyring.so:security/libgnome-keyring \
		libgpgme.so:security/gpgme \
		libopencv_highgui.so:graphics/opencv \
		libopencv_imgproc.so:graphics/opencv-core \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd \
		libminiupnpc.so:net/miniupnpc

USES=		compiler:features desktop-file-utils dos2unix \
		gl gnome pkgconfig qmake qt:5 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	RetroShare
GH_PROJECT=	RetroShare
RS_REVISION=	0e6d27a
USE_GNOME=	libxml2 libxslt
USE_GL=		gl
USE_QT=		core gui multimedia printsupport network widgets xml \
		buildtools_build uitools_build
DOS2UNIX_FILES=	retroshare-nogui/src/retroshare-nogui.pro

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare.pri
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsaccounts.cc
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/retroshare-gui.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/data/retroshare.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/data/retroshare.desktop
	@${REINPLACE_CMD} -e 's|RS_REVISION_NUMBER.*|RS_REVISION_NUMBER   0x${RS_REVISION}|' \
		${WRKSRC}/libretroshare/src/retroshare/rsversion.h

.include <bsd.port.post.mk>

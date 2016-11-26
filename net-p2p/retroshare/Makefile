# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.6.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2

LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libupnp.so:devel/upnp \
		libgnome-keyring.so:security/libgnome-keyring \
		libgpgme.so:security/gpgme \
		libopencv_highgui.so:graphics/opencv2 \
		libopencv_imgproc.so:graphics/opencv2-core \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd

USES=		compiler:features desktop-file-utils dos2unix execinfo pkgconfig qmake ssl
USE_GNOME=	glib20 libxml2 libxslt
USE_GL=		gl
USE_QT5=	buildtools_build uitools_build core gui network xml \
		widgets multimedia printsupport
INSTALLS_ICONS=	yes

DOS2UNIX_FILES=	retroshare-nogui/src/retroshare-nogui.pro
USE_GITHUB=	yes
GH_ACCOUNT=	RetroShare
GH_PROJECT=	RetroShare

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_FEATURES:Mlibc++}
	@${REINPLACE_CMD} -e 's|std::tr1::|std::|' \
		${WRKSRC}/libretroshare/src/dbase/findex.[ch]*
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/retroshare-gui.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/data/retroshare06.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/data/retroshare06.desktop
.if defined(GH_TAGNAME)
	@${REINPLACE_CMD} -e 's|RS_REVISION_NUMBER.*|RS_REVISION_NUMBER   0x${GH_TAGNAME}|' \
		${WRKSRC}/libretroshare/src/retroshare/rsversion.h
.endif

.include <bsd.port.post.mk>

# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ring-gnome
PORTVERSION=	0.160516
PORTREVISION=	7
#DISTVERSIONPREFIX=	v
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Gnome client of the Ring VoIP SIP phone and IM

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libringclient.so:net-im/ring-libclient \
		libqrencode.so:graphics/libqrencode \
		libcogl-pango.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libnotify.so:devel/libnotify \
		libsoup-2.4.so:devel/libsoup \
		libplc4.so:devel/nspr \
		libjson-glib-1.0.so:devel/json-glib \
		libnss3.so:security/nss \
		libsecret-1.so:security/libsecret

USE_GITHUB=	yes
GH_TUPLE+=	savoirfairelinux:ring-client-gnome:07107e9

SUB_FILES=	pkg-message

USES=		cmake compiler:c++14-lang gettext pkgconfig shebangfix sqlite
USE_GNOME=	evolutiondataserver3 glib20 gtk20 cairo gdkpixbuf2 libxml2 gtk30
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xscrnsaver
USE_GL=		gl egl
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent buildtools_build linguisttools_build qmake_build
SHEBANG_FILES=	${WRKSRC}/src/ring.cx
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
NLS_CMAKE_ON=	-DFREEBSD_NLS_ON:BOOL=ON
OPTIONS_SUB=	yes

post-install:
	@${GZIP_CMD} ${GZIP} < ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ring.svg > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ring.svgz
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/ring.svg

.include <bsd.port.mk>

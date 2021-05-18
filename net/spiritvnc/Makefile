# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	spiritvnc
PORTVERSION=	0.4.6
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-view FLTK-based VNC client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libssh2.so:security/libssh2 \
		libvncclient.so:net/libvncserver

USES=		jpeg pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrender

GH_ACCOUNT=	willbprog127
GH_PROJECT=	${PORTNAME}-fltk

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

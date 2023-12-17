PORTNAME=	spiritvnc
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-view FLTK-based VNC client
WWW=		https://www.pismotek.com/brainout/content/spiritvnc.php

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libvncclient.so:net/libvncserver

USES=		gmake jpeg pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrender

GH_ACCOUNT=	willbprog127
GH_PROJECT=	${PORTNAME}-fltk-no-libssh2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

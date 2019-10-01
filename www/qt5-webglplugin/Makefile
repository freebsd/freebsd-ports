# $FreeBSD$

PORTNAME=	webglplugin
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QPA plugin for running an application via a browser using streamed WebGL commands

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gl gnome qmake:norecursive qt-dist:5
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		core dbus declarative gui network webchannel websockets \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>

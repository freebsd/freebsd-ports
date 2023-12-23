PORTNAME=	qgnomeplatform
DISTVERSION=	0.6.1-8
DISTVERSIONSUFFIX=	-g53d7924
PORTREVISION=	3
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 5 Platform Theme designed to fit into GNOME
WWW=		https://github.com/FedoraQt/QGnomePlatform

LICENSE=	LGPL21

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang gl gnome pkgconfig qmake:outsource qt:5 xorg
USE_GL=		gl
USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_QT=		buildtools:build core gui widgets dbus wayland
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	FedoraQt
GH_PROJECT=	QGnomePlatform

.include <bsd.port.mk>

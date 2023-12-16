PORTNAME=	obs-text-pthread
DISTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Rich text source plugin for OBS Studio
WWW=		https://github.com/norihiro/obs-text-pthread

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libobs.so:multimedia/obs-studio \
		libpng16.so:graphics/png

USES=		cmake gettext-runtime gnome localbase:ldflags pkgconfig
USE_GNOME=	cairo glib20 pango

USE_GITHUB=	yes
GH_ACCOUNT=	norihiro

CMAKE_OFF=	LINUX_PORTABLE

CFLAGS+=	-I${WRKDIR}/src

PLIST_FILES=	lib/obs-plugins/obs-text-pthread.so \
		share/obs/obs-plugins/obs-text-pthread/textalpha.effect

.include <bsd.port.mk>

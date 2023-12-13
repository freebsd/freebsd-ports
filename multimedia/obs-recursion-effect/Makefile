PORTNAME=	obs-recursion-effect
DISTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Recursion effect for a source using a filter
WWW=		https://obsproject.com/forum/resources/recursion-effect.1008/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libobs.so:multimedia/obs-studio \
		libpng16.so:graphics/png

USES=		cmake:noninja gettext-runtime gnome localbase:ldflags pkgconfig # with ninja it installs files back into the source directory
USE_GNOME=	cairo glib20 pango

USE_GITHUB=	yes
GH_ACCOUNT=	exeldro

CMAKE_OFF=	LINUX_PORTABLE

PLIST_FILES=	lib/obs-plugins/recursion-effect.so \
		share/obs/obs-plugins/recursion-effect/locale/en-US.ini

.include <bsd.port.mk>

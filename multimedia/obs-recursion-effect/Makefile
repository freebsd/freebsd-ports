PORTNAME=	obs-recursion-effect
DISTVERSION=	0.1.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Recursion effect for a source using a filter
WWW=		https://obsproject.com/forum/resources/recursion-effect.1008/ \
		https://github.com/exeldro/obs-recursion-effect

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		compilation fails with obs-studio-32.0.1, see https://github.com/exeldro/obs-recursion-effect/issues/9

BUILD_DEPENDS=	simde>0:devel/simde
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libobs.so:multimedia/obs-studio \
		libpng16.so:graphics/png

USES=		cmake:noninja gettext-runtime gnome localbase:ldflags pkgconfig # with ninja it installs files back into the source directory
USE_GNOME=	cairo glib20 pango

USE_GITHUB=	yes
GH_ACCOUNT=	exeldro

CMAKE_OFF=	LINUX_PORTABLE

CFLAGS+=	-Wno-deprecated-declarations

PLIST_FILES=	lib/obs-plugins/recursion-effect.so \
		share/obs/obs-plugins/recursion-effect/effects/render.effect \
		share/obs/obs-plugins/recursion-effect/locale/en-US.ini

.include <bsd.port.mk>

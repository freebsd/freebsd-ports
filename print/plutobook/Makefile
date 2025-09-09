PORTNAME=		plutobook
DISTVERSIONPREFIX=	v
DISTVERSION=		0.8.0
CATEGORIES=		print

MAINTAINER=		jbo@FreeBSD.org
COMMENT=		Paged HTML rendering library
WWW=			https://github.com/plutoprint/plutobook

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libcurl.so:ftp/curl \
			libexpat.so:textproc/expat2 \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu \
			libturbojpeg.so:graphics/libjpeg-turbo \
			libwebp.so:graphics/webp

USES=			compiler:c++20-lang gnome meson pkgconfig

USE_LDCONFIG=		yes
USE_GNOME=		cairo

USE_GITHUB=		yes
GH_ACCOUNT=		plutoprint

PLIST_SUB=		SOVERSION="${DISTVERSION}"

OPTIONS_DEFINE=		TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes
TOOLS_DESC=		Build CLI tools to convert HTML to PDF or PNG

TOOLS_MESON_ENABLED=	tools

.include <bsd.port.mk>

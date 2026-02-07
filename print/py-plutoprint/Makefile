PORTNAME=		plutoprint
DISTVERSIONPREFIX=	v
DISTVERSION=		0.15.0
CATEGORIES=		print python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		acm@FreeBSD.org
COMMENT=		A Python Library for Generating PDFs and Images from HTML
WWW=			https://github.com/plutoprint/plutoprint

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}meson-python>=0.12.1:devel/meson-python@${PY_FLAVOR}
LIB_DEPENDS=		libplutobook.so:print/plutobook \
			libcurl.so:ftp/curl \
			libexpat.so:textproc/expat2 \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu \
			libturbojpeg.so:graphics/libjpeg-turbo \
			libwebp.so:graphics/webp

USES=			compiler:c++20-lang gnome ninja pkgconfig python

USE_GNOME=		cairo
USE_PYTHON=		autoplist pep517

USE_GITHUB=		yes
GH_ACCOUNT=		plutoprint

.include <bsd.port.mk>

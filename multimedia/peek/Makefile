PORTNAME=	peek
DISTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple animated GIF screen recorder with an easy to use interface
WWW=		https://github.com/phw/peek

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkeybinder-3.0.so:x11/keybinder-gtk3
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		gettext-tools gnome meson pkgconfig python:build vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	phw
USE_GNOME=	cairo glib20 gtk30 pango

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

GLIB_SCHEMAS=	com.uploadedlobster.peek.gschema.xml

.include <bsd.port.mk>

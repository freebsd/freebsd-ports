# $FreeBSD$

PORTNAME=	peek
DISTVERSION=	1.4.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple animated GIF screen recorder with an easy to use interface

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libkeybinder-3.0.so:x11/keybinder-gtk3
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		gettext-tools gnome meson pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	phw
USE_GNOME=	cairo glib20 gtk30 pango
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

GLIB_SCHEMAS=	com.uploadedlobster.peek.gschema.xml

.include <bsd.port.mk>

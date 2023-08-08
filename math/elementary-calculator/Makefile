PORTNAME=	calculator
DISTVERSION=	2.0.2
CATEGORIES=	math
PKGNAMEPREFIX=	elementary-

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple calculator written in Vala
WWW=		https://github.com/elementary/calculator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite-7.so:x11-toolkits/granite7

USES=		gettext gnome meson pkgconfig python:build vala:build

USE_GITHUB=	yes
GH_ACCOUNT=	elementary

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk40

GLIB_SCHEMAS=	io.elementary.calculator.gschema.xml

.include <bsd.port.mk>

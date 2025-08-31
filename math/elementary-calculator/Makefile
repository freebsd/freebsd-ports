PORTNAME=	calculator
DISTVERSION=	8.0.1
CATEGORIES=	math
PKGNAMEPREFIX=	elementary-

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Simple calculator written in Vala
WWW=		https://github.com/elementary/calculator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite-7.so:x11-toolkits/granite7

USES=		gettext-tools gnome meson pkgconfig python:build vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20 gtk40

GLIB_SCHEMAS=	io.elementary.calculator.gschema.xml

.include <bsd.port.mk>

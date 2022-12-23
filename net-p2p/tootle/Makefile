PORTNAME=	tootle
PORTVERSION=	g20221222
CATEGORIES=	net-p2p

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple Mastodon client for Linux
WWW=		https://gitlab.gnome.org/World/tootle

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgraphene-1.0.so:graphics/graphene \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

USES=		desktop-file-utils gettext gnome meson pkgconfig python:build \
		shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/
GL_ACCOUNT=	World
GL_COMMIT=	b4046da9a7806e11cb77e85b4531c98ff4a33ca5
USE_GNOME=	gdkpixbuf2 gtk40 libadwaita libxml2

SHEBANG_FILES=	meson/post_install.py

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/bin/com.github.bleakgrey.tootle \
		${STAGEDIR}${PREFIX}/bin/tootle

.include <bsd.port.mk>

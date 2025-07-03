PORTNAME=	authenticator
DISTVERSION=	4.4.0
PORTREVISION=	8
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate Two-Factor Codes
WWW=		https://gitlab.gnome.org/World/Authenticator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build in aes crate

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libzbar.so:graphics/zbar

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig sqlite ssl
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita
USE_GSTREAMER=	gl rust zbar
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Authenticator
CARGO_ENV=	ZBAR_INCLUDE_DIRS="${LOCALBASE}/include" ZBAR_LIB_DIRS="${LOCALBASE}/lib"
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	com.belmoussaoui.Authenticator.gschema.xml

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
	@${REINPLACE_CMD} -e '/gstreamer.*bad/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.post.mk>

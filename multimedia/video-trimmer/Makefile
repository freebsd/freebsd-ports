PORTNAME=	video-trimmer
DISTVERSIONPREFIX=	v
DISTVERSION=	25.03
CATEGORIES=	multimedia gnome
DIST_SUBDIR=	gnome

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Trim videos quickly without re-encoding and sacrificing video quality
WWW=		https://gitlab.gnome.org/YaLTeR/video-trimmer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	YaLTeR
USE_GNOME=	gtk40 libadwaita pango
GLIB_SCHEMAS=	org.gnome.gitlab.YaLTeR.VideoTrimmer.gschema.xml
USE_GSTREAMER=	good libav

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>

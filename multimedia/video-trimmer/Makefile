PORTNAME=	video-trimmer
DISTVERSION=	26.03
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gitlab.gnome.org/-/project/11135/uploads/6d29ff2c8ff5ba5ba676a03f2b8a0b64/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	gnome

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Trim videos quickly without re-encoding and sacrificing video quality
WWW=		https://gitlab.gnome.org/YaLTeR/video-trimmer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig tar:xz
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

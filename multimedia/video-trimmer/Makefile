PORTNAME=	video-trimmer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	multimedia

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Trim videos quickly
WWW=		https://gitlab.gnome.org/YaLTeR/video-trimmer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	YaLTeR
USE_GNOME=	gtk40 libadwaita
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

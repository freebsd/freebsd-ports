PORTNAME=	kew
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line music player with the terminal user interface (TUI)
WWW=		https://github.com/ravachol/kew

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails with incompatible pointer, see https://github.com/ravachol/kew/issues/118

LIB_DEPENDS=	libchafa.so:graphics/chafa \
		libcurl.so:ftp/curl \
		libfaad.so:audio/faad \
		libfftw3f.so:math/fftw3-float \
		libnotify.so:devel/libnotify \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile \
		libtag.so:audio/taglib \
		libvorbis.so:audio/libvorbis

USES=		gettext-runtime gmake gnome pkgconfig
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	ravachol

MAKE_ARGS=	CC=${CC} PREFIX=${PREFIX}

PLIST_FILES=	bin/kew \
		share/man/man1/kew.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kew

.include <bsd.port.mk>

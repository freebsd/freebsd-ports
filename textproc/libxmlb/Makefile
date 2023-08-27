PORTNAME=	libxmlb
DISTVERSION=	0.3.14
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/hughsie/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library to help create and query binary XML blobs
WWW=		https://github.com/hughsie/libxmlb

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libstemmer.so:textproc/snowballstemmer \
		libzstd.so:archivers/zstd

USES=		gnome meson pkgconfig localbase:ldflags tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	-Dstemmer=true

.include <bsd.port.mk>

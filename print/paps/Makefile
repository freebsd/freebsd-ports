PORTNAME=	paps
DISTVERSION=	0.8.1
CATEGORIES=	print
MASTER_SITES=	https://github.com/dov/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Text to PostScript, PDF and SVG converter using Pango
WWW=		https://github.com/dov/paps

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpaper.so:print/libpaper
RUN_DEPENDS=	source-highlight>0:textproc/source-highlight

USES=		compiler:c++17-lang gnome meson pkgconfig python:env,run \
		shebangfix tar:xz
USE_GNOME=	cairo pango
SHEBANG_FILES=	${WRKSRC}/scripts/src-to-paps

PLIST_FILES=	bin/paps \
		bin/src-to-paps \
		share/man/man1/paps.1.gz \
		share/paps/pango_markup.outlang

post-patch:
	${REINPLACE_CMD} -e "/^libpaper/s|)|, dirs: ['${LOCALBASE}/lib'], )|" \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} -e '/pango_markup.outlang/s,/usr/local,${PREFIX},' \
		${WRKSRC}/scripts/src-to-paps

.include <bsd.port.mk>

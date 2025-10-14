PORTNAME=	paps
DISTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	https://github.com/dov/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/dov/paps/commit/
PATCHFILES=	e9270aaac5e0b8018a6fad9a562ee48e7b2c3113.patch:-p1 \
		a26a20d7ca3feb08476a8a19fd97c3ececcc1e2e.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 to PostScript converter using Pango
WWW=		https://github.com/dov/paps

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN_i386=	compilation fails, see https://github.com/dov/paps/issues/60

LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		compiler:c++17-lang meson gnome pkgconfig python:env,run shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/src-to-paps
USE_GNOME=	cairo pango

PLIST_FILES=	bin/paps \
		bin/src-to-paps \
		share/man/man1/paps.1.gz \
		share/paps/pango_markup.outlang

.include <bsd.port.mk>

PORTNAME=	paps
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	print

PATCH_SITES=	${WWW}/commit/
PATCHFILES+=	e9270aaac5e0b8018a6fad9a562ee48e7b2c3113.patch:-p1 # https://github.com/dov/paps/pull/71

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 to PostScript converter using Pango
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN_i386=	compilation fails, see https://github.com/dov/paps/issues/60

LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake:indirect compiler:c++17-lang meson gnome pkgconfig python:env shebangfix
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	dov
USE_GNOME=	cairo pango

SHEBANG_FILES=	${WRKSRC}/scripts/src-to-paps

PLIST_FILES=	bin/paps share/man/man1/paps.1.gz

post-install:
	${ECHO_CMD} "bin/src-to-paps" >> ${TMPPLIST}
	${ECHO_CMD} "share/paps/pango_markup.outlang" >> ${TMPPLIST}

.include <bsd.port.mk>

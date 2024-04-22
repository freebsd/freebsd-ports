PORTNAME=	paps
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 to PostScript converter using Pango
WWW=		https://paps.sourceforge.net/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

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

PORTNAME=	bookokrat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.5
PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal EPUB/PDF book reader
WWW=		https://bugzmanov.github.io/bookokrat/index.html

LICENSE=	AGPLv3 APACHE20 BSD0CLAUSE BSD2CLAUSE BSL CC0-1.0 CDDL ISCL MIT \
		MPL20 UNLICENSE ZLIB
LICENSE_COMB=	multi

BROKEN_aarch64=	fails to build with error[E0609]: no field mc_gpregs on type ucontext_t

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo gmake llvm pkgconfig python:env shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	bugzmanov
SHEBANG_GLOB=	*.py

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bookokrat
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

# fix Python interpreter path in other files
post-patch:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -E -e 's|(/usr/bin/)?python3|${PYTHON_CMD}|g' \
		cargo-crates/freetype-sys-0.20.1/freetype2/meson.build \
		cargo-crates/mupdf-sys-0.6.0/mupdf/Makefile \
		cargo-crates/mupdf-sys-0.6.0/mupdf/Makethird \
		cargo-crates/which-4.4.2/src/lib.rs)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bookokrat

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

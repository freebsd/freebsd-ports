# Created by: patrick, trevor

PORTNAME=	lilypond
DISTVERSION=	2.22.1
PORTREVISION=	1
CATEGORIES=	print audio
MASTER_SITES=	http://lilypond.org/download/source/v${DISTVERSION:R}/

MAINTAINER=	m.ne@gmx.net
COMMENT=	GNU music typesetter

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		convert:graphics/ImageMagick7 \
		dblatex:textproc/dblatex \
		fontforge:print/fontforge \
		help2man:misc/help2man \
		pdftexi2dvi:print/texinfo \
		pngtopnm:graphics/netpbm \
		rsync:net/rsync \
		t1ascii:print/t1utils \
		texi2html:textproc/texi2html \
		zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu \
		mftrace:print/mftrace

USES=		bison:build compiler:c++11-lib ghostscript gmake gnome \
		perl5 pkgconfig python:3.5+
USE_CXXSTD=	c++11
USE_GNOME=	pango
USE_PERL5=	build
USE_TEX=	latex texmf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-texgyre-dir=${LOCALBASE}/${TEXMFDISTDIR}/fonts/opentype/public/tex-gyre
CONFIGURE_ENV+=		ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
			FLEX=${FLEX} \
			HOME=${WRKDIR} \
			YACC=${YACC}

MAKEFILE=	GNUmakefile
ALL_TARGET=	all

BINARY_ALIAS=	python=${PYTHON_VERSION}

INFO=		lilypond-changes \
				lilypond-contributor \
				lilypond-essay \
				lilypond-extending \
				lilypond-internals \
				lilypond-learning \
				lilypond-notation \
				lilypond-snippets \
				lilypond-usage \
				music-glossary
PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	GUILE2 NLS URW
OPTIONS_SUB=	yes

GUILE2_DESC=	guile2 instead guile (incurs performance penalty)
URW_DESC=	Use bundled URW fonts

GUILE2_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded \
			libguile-2.2.so:lang/guile2
GUILE2_LIB_DEPENDS_OFF=	libguile.so:lang/guile1

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

URW_BUILD_DEPENDS=	urw-base35-fonts>0:x11-fonts/urw-base35-fonts
URW_RUN_DEPENDS_OFF=	urw-base35-fonts>0:x11-fonts/urw-base35-fonts
URW_CONFIGURE_WITH=	urwotf-dir=${LOCALBASE}/share/fonts/urw-base35-fonts

post-patch:
	@${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
		${WRKSRC}/lily/include/includable-lexer.hh
	@${REINPLACE_CMD} -e 's|$save_CXXFLAGS -Werror=suggest-override|$save_CXXFLAGS|' \
		${WRKSRC}/configure
	@${SED} -e 's|%%FONTDIR%%|${WRKDIR}/fontconfig/cache/|'  \
		${FILESDIR}/fonts.conf > ${WRKDIR}/.fonts.conf

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilypond
	(cd ${STAGEDIR}/${DATADIR} && ${LN} -fs ${DISTVERSION} current)

.include <bsd.port.mk>

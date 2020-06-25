# Created by: patrick, trevor
# $FreeBSD$

PORTNAME=	lilypond
DISTVERSION=	2.21.2
CATEGORIES=	print audio
MASTER_SITES=	http://lilypond.org/download/source/v${DISTVERSION:R}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	m.ne@gmx.net
COMMENT=	GNU music typesetter

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		convert:graphics/ImageMagick6 \
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
		libguile.so:lang/guile1 \
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
CONFIGURE_ARGS+=	--with-texgyre-dir=${LOCALBASE}/${TEXMFDISTDIR}/fonts/opentype/public/tex-gyre \
			--without-urwotf-dir
CONFIGURE_ENV+=		ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
			FLEX=${FLEX} \
			HOME=${WRKDIR} \
			YACC=${YACC}

MAKEFILE=	GNUmakefile
ALL_TARGET=	all

BINARY_ALIAS=	python=${PYTHON_VERSION}

INFO=		internals \
				lilypond-changes \
				lilypond-contributor \
				lilypond-essay \
				lilypond-extending \
				lilypond-internals \
				lilypond-learning \
				lilypond-notation \
				lilypond-snippets \
				lilypond-usage \
				lilypond-web \
				music-glossary
PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
		${SED} -e 's|%%FONTDIR%%|${WRKDIR}/fontconfig/cache/|'  \
			${FILESDIR}/fonts.conf > ${WRKDIR}/.fonts.conf

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilypond
	(cd ${STAGEDIR}/${DATADIR} && ${LN} -fs ${DISTVERSION} current)

.include <bsd.port.mk>

# Created by: patrick, trevor
# $FreeBSD$

PORTNAME=	lilypond
PORTVERSION=	2.18.2
PORTREVISION=	9
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU music typesetter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pdftexi2dvi:print/texinfo \
		t1ascii:print/t1utils \
		bash:shells/bash \
		convert:graphics/ImageMagick6 \
		dblatex:textproc/dblatex \
		fontforge:print/fontforge \
		help2man:misc/help2man \
		pngtopnm:graphics/netpbm \
		rsync:net/rsync \
		zip:archivers/zip \
		texi2html:textproc/texi2html \
		${LOCALBASE}/share/ghostscript/fonts/c059033l.pfb:print/gsfonts
LIB_DEPENDS=	libguile.so:lang/guile \
		libgmp.so:math/gmp \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	mftrace:print/mftrace \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu

USES=		bison:build compiler:c++11-lang gettext ghostscript gmake \
		gnome pkgconfig perl5 python:2.7
USE_TEX=	latex
USE_PERL5=	build
USE_GNOME=	pango
#MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ncsb-dir=${LOCALBASE}/share/ghostscript/fonts \
		--with-python-include=${PYTHON_INCLUDEDIR}
CONFIGURE_ENV+=	ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} YACC=${YACC}

MAKEFILE=	GNUmakefile
GNU_MAKEFILE=	yes

ALL_TARGET=	all
TEST_TARGET=	test  # fails with sig11

NO_CCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

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

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
		${WRKSRC}/lily/include/includable-lexer.hh

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^PO_FILES/s|= |= #|' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilypond
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lilypond/${PORTVERSION}/python/midi.so
	@${LN} -fs ${DATADIR}/${PORTVERSION} ${STAGEDIR}${DATADIR}/current

.include <bsd.port.mk>

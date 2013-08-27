# Created by: patrick, trevor
# $FreeBSD$

PORTNAME=	lilypond
PORTVERSION=	2.17.25
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	pdftexi2dvi:${PORTSDIR}/print/texinfo \
		t1ascii:${PORTSDIR}/print/t1utils \
		bash:${PORTSDIR}/shells/bash \
		fontforge:${PORTSDIR}/print/fontforge \
		${LOCALBASE}/share/ghostscript/fonts/c059033l.pfb:${PORTSDIR}/print/gsfonts

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		gmp:${PORTSDIR}/math/gmp \
		freetype:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	dblatex:${PORTSDIR}/textproc/dblatex \
		mftrace:${PORTSDIR}/print/mftrace \
		pngtopnm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans-Bold.ttf:${PORTSDIR}/x11-fonts/dejavu

MAN1=		lilymidi.1 lilypond-book.1 lilypond-invoke-editor.1 \
		lilypond.1 lilysong.1 convert-ly.1 abc2ly.1 etf2ly.1 \
		midi2ly.1 musicxml2ly.1

INFO=		lilypond-notation \
		lilypond-usage \
		lilypond-internals \
		lilypond-learning \
		lilypond-changes \
		lilypond-contributor \
		lilypond-essay \
		lilypond-extending \
		lilypond-snippets \
		lilypond-web \
		music-glossary \
		internals

USES=		bison gettext
USE_GMAKE=	yes
USE_GHOSTSCRIPT=9
USE_PYTHON=	yes
USE_PERL5_BUILD=yes
USE_TEX=	latex
USE_GNOME=	pango

MAKEFILE=	GNUmakefile
GNU_MAKEFILE=	yes
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ncsb-dir=${LOCALBASE}/share/ghostscript/fonts
CONFIGURE_ENV+=	ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} YACC=${YACC}

ALL_TARGET=	all

NOCCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in
.endif

post-install:
	@${LN} -fs ${DATADIR}/${PORTVERSION} ${DATADIR}/current

.include <bsd.port.mk>

# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.18 2004/05/25 22:16:33 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.16.0
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		pdftexi2dvi:${PORTSDIR}/print/texinfo \
		t1ascii:${PORTSDIR}/print/t1utils \
		bash:${PORTSDIR}/shells/bash \
		fontforge:${PORTSDIR}/print/fontforge \
		${LOCALBASE}/share/ghostscript/fonts/c059033l.pfb:${PORTSDIR}/print/gsfonts

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile \
    		gmp:${PORTSDIR}/math/gmp \
		freetype:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
    		mftrace:${PORTSDIR}/print/mftrace \
		gs:${PORTSDIR}/print/ghostscript9 \
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

USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PERL5_BUILD=yes
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

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '/^PO_FILES/s|= |= #|' ${WRKSRC}/${MAKEFILE}
.endif

post-install:
	@${LN} -fs ${DATADIR}/${PORTVERSION} ${DATADIR}/current

.include <bsd.port.post.mk>

# Created by: patrick, trevor
# $FreeBSD$

PORTNAME=	lilypond
PORTVERSION=	2.19.11
PORTREVISION=	2
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

LICENSE=	GPLv3

BUILD_DEPENDS=	pdftexi2dvi:${PORTSDIR}/print/texinfo \
		t1ascii:${PORTSDIR}/print/t1utils \
		bash:${PORTSDIR}/shells/bash \
		convert:${PORTSDIR}/graphics/ImageMagick \
		dblatex:${PORTSDIR}/textproc/dblatex \
		fontforge:${PORTSDIR}/print/fontforge \
		help2man:${PORTSDIR}/misc/help2man \
		pngtopnm:${PORTSDIR}/graphics/netpbm \
		rsync:${PORTSDIR}/net/rsync \
		texi2html:${PORTSDIR}/textproc/texi2html \
		zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/share/ghostscript/fonts/c059033l.pfb:${PORTSDIR}/print/gsfonts

RUN_DEPENDS=	mftrace:${PORTSDIR}/print/mftrace \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans-Bold.ttf:${PORTSDIR}/x11-fonts/dejavu

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile \
		libgmp.so:${PORTSDIR}/math/gmp \
		libfreetype.so:${PORTSDIR}/print/freetype2

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

USES=		bison:build gettext gmake pkgconfig perl5 compiler:c++11-lib python:-3
USE_CXXSTD=	c++11
USE_GHOSTSCRIPT=9
USE_TEX=	latex
USE_PERL5=	build
USE_GNOME=	pango

MAKEFILE=	GNUmakefile
GNU_MAKEFILE=	yes
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ncsb-dir=${LOCALBASE}/share/ghostscript/fonts \
		--with-python-include=${PYTHON_INCLUDEDIR}
CONFIGURE_ENV+=	ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} YACC=${YACC} HOME=${WRKDIR}

ALL_TARGET=	all

NO_CCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|isinf[ ]*(|::isinf(|g' -e 's|isnan|::isnan|g'
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in
.endif

post-install:
	@${LN} -fs ${DATADIR}/${PORTVERSION} ${STAGEDIR}${DATADIR}/current

.include <bsd.port.mk>

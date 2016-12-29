# Created by: patrick, trevor
# $FreeBSD$

PORTNAME=	lilypond
PORTVERSION=	2.19.51
PORTREVISION=	1
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	m.ne@gmx.net
COMMENT=	GNU music typesetter

LICENSE=	GPLv3

BUILD_DEPENDS=	pdftexi2dvi:print/texinfo \
		t1ascii:print/t1utils \
		bash:shells/bash \
		convert:graphics/ImageMagick \
		dblatex:textproc/dblatex \
		fontforge:print/fontforge \
		help2man:misc/help2man \
		pngtopnm:graphics/netpbm \
		rsync:net/rsync \
		texi2html:textproc/texi2html \
		zip:archivers/zip
RUN_DEPENDS=	mftrace:print/mftrace \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libguile.so:lang/guile \
		libgmp.so:math/gmp \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

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

USES=		bison:build gettext ghostscript gmake pkgconfig perl5 \
		compiler:gcc-c++11-lib python:-3
USE_CXXSTD=	c++11
USE_TEX=	latex texmf
USE_PERL5=	build
USE_GNOME=	pango

MAKEFILE=	GNUmakefile
GNU_MAKEFILE=	yes
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-texgyre-dir=${LOCALBASE}/${TEXMFDISTDIR}/fonts/opentype/public/tex-gyre \
		--with-python-include=${PYTHON_INCLUDEDIR}
CONFIGURE_ENV+=	ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} YACC=${YACC} HOME=${WRKDIR}

ALL_TARGET=	all

NO_CCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000 && ${OSVERSION} < 1002000
BROKEN=		does not build on 10.1 (undefined reference to `__cxa_throw_bad_array_new_length')
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|isinf[ ]*(|::isinf(|g' -e 's|isnan|::isnan|g'
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilypond
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lilypond/${PORTVERSION}/python/midi.so
	(cd ${STAGEDIR}/${DATADIR} && ${LN} -fs ${PORTVERSION} current)

.include <bsd.port.post.mk>

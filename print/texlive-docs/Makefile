PORTNAME=	texlive
PORTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMESUFFIX=	-docs
DISTNAME=	${PORTNAME}-${PORTVERSION}-texmf
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, documentation

USES=		perl5 tar:xz
USE_TEX=	texmf

EXTRACT_AFTER_ARGS=	| ${TAR} xf - \
			${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}
NO_BUILD=	yes

EXCLUDE_FILES=	\*/doc/man texmf-dist/doc/aleph texmf-dist/doc/lualatex \
		texmf-dist/doc/luatex texmf-dist/doc/xelatex \
		texmf-dist/doc/xetex texmf-dist/doc/otherformats/jadetex \
		texmf-dist/doc/otherformats/xmltex texmf-dist/doc/ptex \
		texmf-dist/doc/platex texmf-dist/doc/uptex \
		texmf-dist/doc/uplatex texmf-dist/doc/fonts/japanese-otf \
		texmf-dist/doc/fonts/japanese-otf-uptex \
		texmf-dist/doc/fonts/jfontmaps texmf-dist/doc/dvips \
		texmf-dist/doc/dvipdfmx

NO_ARCH=	yes

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
	    --strip-components 1 --no-same-permission --no-same-owner \
	    ${DISTNAME}/texmf-dist/doc
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/fontforge|${PREFIX}/bin/fontforge|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/aesupp/genfonts.pe \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/berenisadf/ff-ybd.pe \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/report/kernclasses.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/metafont/bulk_eps_import.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl -w|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/aesupp/ggen.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/abs2rel.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/biokey2html1.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/biokey2html2.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/biokey2html3.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/txt2qq.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/ucs/makeunidef.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/support/ctan-o-mat/lib/md2ltx.pl
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl -T|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/ucs/discovermacro.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/ucs/latexout.pl
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/dad/dad-to-utf8.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/dad/utf8-to-dad.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/KerningNumerals.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/test/MES-Conformance/mes-list-expand.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/test/MES-Conformance/CheckConformance.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/phaistos/getglyphs \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/generic/pst-mirror/createEPS/scripts/filtre.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/gridslides/compile.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/latex-web-companion/ch7/sgmlspl.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/ucs/unsupported/u2ps \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/support/gustprog/porzadki.pl
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/hex_range.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/xcharter/altone.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/aramaic-serto/serto.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/scanpages/replicate.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/python|${PYTHO_CMD}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/unicode_joining.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/arabic_test.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/generate_arabic_shaping.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/texlua|${PREFIX}/bin/texlua|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/generic/m-tx/buildmtxdoc.lua
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${PREFIX}/bin/bash|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/fonts/drm/allfonts.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/generic/e-french/bin/linux/makefrindex \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/metapost/featpost/bash/COMPILE.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/metapost/featpost/bash/makehtmlindex.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/metapost/featpost/bash/laproof.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/uspace/uspace-ctanify.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/hvfloat/runAll.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/hvfloat/runEXA.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/hepnames/mkmacrotables \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/bardiag/example/compile.all \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/tlc-article/bin/deploy \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/pdfreview/pdfreview.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/pdfreview/pdfshrink.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/beamerappendixnote/build.sh  \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shipunov/scripts/biokey2html.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/seminar/run.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/biblatex-abnt/test.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/shdoc/shreformat.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/biblatex-software/mkbiblatexstubs.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/latex/ctable/inst \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/cstex/cspsfonts-gen/mkfc \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/cstex/cspsfonts-gen/mkf \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/support/chklref/release.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/support/latexdiff/contrib/latexdiff-wrap
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>

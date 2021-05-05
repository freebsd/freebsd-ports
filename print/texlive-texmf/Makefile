PORTNAME=	texlive
PORTVERSION=	20150523
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tug.org/historic/systems/texlive/2015/:texmf \
		LOCAL/hrs:latex
PKGNAMESUFFIX=	-texmf
DISTFILES=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}${EXTRACT_SUFX}:texmf \
		latex-base-20150101.2${EXTRACT_SUFX}:latex
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	latex-base-20150101.2${EXTRACT_SUFX}

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree

CONFLICTS_INSTALL=	texlive-base-201[234]* \
			texlive-texmf-201[234]*

USES=		python:run shebangfix tar:xz
USE_TEX=	basic:extract base tlmgr:run texhash
TEXHASHDIRS=	${TEXMFDIR} ${TEXMFDISTDIR}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
PKG_CREATE_VERBOSE=	yes

EXCLUDE_FILES=	\*/doc/man \
	texmf-dist/ls-R \
	texmf-dist/bibtex/csf/base \
	texmf-dist/doc \
	texmf-dist/dvipdfm \
	texmf-dist/dvipdfmx \
	texmf-dist/dvips \
	texmf-dist/fonts/cmap/dvipdfmx \
	texmf-dist/fonts/cmap/uptex \
	texmf-dist/fonts/enc/dvips \
	texmf-dist/fonts/map/dvipdfm \
	texmf-dist/fonts/map/dvipdfmx \
	texmf-dist/fonts/map/dvips \
	texmf-dist/fonts/map/luatex \
	texmf-dist/fonts/misc/xetex \
	texmf-dist/fonts/ofm/public/japanese-otf \
	texmf-dist/fonts/ovp/public/japanese-otf-uptex \
	texmf-dist/fonts/source/ptex \
	texmf-dist/fonts/tfm/ptex \
	texmf-dist/fonts/tfm/public/japanese-otf \
	texmf-dist/fonts/tfm/public/japanese-otf-uptex \
	texmf-dist/fonts/tfm/uptex \
	texmf-dist/fonts/type1/ptex \
	texmf-dist/fonts/vf/ptex \
	texmf-dist/fonts/vf/public/japanese-otf \
	texmf-dist/fonts/vf/public/japanese-otf-uptex \
	texmf-dist/fonts/vf/uptex \
	texmf-dist/scripts/xetex \
	texmf-dist/source \
	texmf-dist/tex/generic/config/luatex-unicode-letters.tex \
	texmf-dist/tex/generic/config/luatexiniconfig.tex \
	texmf-dist/tex/generic/context/luatex \
	texmf-dist/tex/generic/dvips \
	texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
	texmf-dist/tex/generic/xetexconfig \
	texmf-dist/tex/jadetex \
	texmf-dist/tex/lambda \
	texmf-dist/tex/latex/base \
	texmf-dist/tex/latex/latexconfig/dvilualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatex-patch-kernel.tex \
	texmf-dist/tex/latex/latexconfig/lualatex-reset-codes.tex \
	texmf-dist/tex/latex/latexconfig/lualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
	texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
	texmf-dist/tex/latex/latexconfig/xelatex.ini \
	texmf-dist/tex/lualatex \
	texmf-dist/tex/luatex \
	texmf-dist/tex/plain/config/aleph.ini \
	texmf-dist/tex/plain/config/dviluatex.ini \
	texmf-dist/tex/plain/config/luatex.ini \
	texmf-dist/tex/plain/config/xetex.ini \
	texmf-dist/tex/platex \
	texmf-dist/tex/ptex \
	texmf-dist/tex/uplatex \
	texmf-dist/tex/uptex \
	texmf-dist/tex/xelatex \
	texmf-dist/tex/xetex \
	texmf-dist/tex/xmltex \
	texmf-dist/web2c/fmtutil-hdr.cnf \
	texmf-dist/web2c/fmtutil.cnf \
	texmf-dist/web2c/texmf.cnf \
	texmf-dist/web2c/updmap-hdr.cfg \
	texmf-dist/web2c/updmap.cfg \
	texmf-dist/xdvi \
	texmf-dist/scripts/a2ping/a2ping.pl \
	texmf-dist/scripts/accfonts/mkt1font \
	texmf-dist/scripts/accfonts/vpl2ovp \
	texmf-dist/scripts/accfonts/vpl2vpl \
	texmf-dist/scripts/adhocfilelist/adhocfilelist.sh \
	texmf-dist/scripts/arara/arara.sh \
	texmf-dist/scripts/authorindex/authorindex \
	texmf-dist/scripts/bibexport/bibexport.sh \
	texmf-dist/scripts/bundledoc/arlatex \
	texmf-dist/scripts/bundledoc/bundledoc \
	texmf-dist/scripts/cachepic/cachepic.tlu \
	texmf-dist/scripts/cjk-gs-integrate/cjk-gs-integrate.pl \
	texmf-dist/scripts/checkcites/checkcites.lua \
	texmf-dist/scripts/context/perl/mptopdf.pl \
	texmf-dist/scripts/context/stubs/unix/context \
	texmf-dist/scripts/context/stubs/unix/contextjit \
	texmf-dist/scripts/context/stubs/unix/luatools \
	texmf-dist/scripts/context/stubs/unix/mtxrun \
	texmf-dist/scripts/context/stubs/unix/mtxrunjit \
	texmf-dist/scripts/context/stubs/unix/texexec \
	texmf-dist/scripts/context/stubs/unix/texmfstart \
	texmf-dist/scripts/context/lua \
	texmf-dist/scripts/convbkmk/convbkmk.rb \
	texmf-dist/scripts/crossrefware/bibdoiadd.pl \
	texmf-dist/scripts/crossrefware/bibzbladd.pl \
	texmf-dist/scripts/crossrefware/ltx2crossrefxml.pl \
	texmf-dist/scripts/ctanify/ctanify \
	texmf-dist/scripts/ctanupload/ctanupload.pl \
	texmf-dist/scripts/de-macro/de-macro \
	texmf-dist/scripts/dosepsbin/dosepsbin.pl \
	texmf-dist/scripts/dtxgen/dtxgen \
	texmf-dist/scripts/dviasm/dviasm.py \
	texmf-dist/scripts/ebong/ebong.py \
	texmf-dist/scripts/epspdf/epspdf.tlu \
	texmf-dist/scripts/epspdf/epspdftk.tcl \
	texmf-dist/scripts/epstopdf/epstopdf.pl \
	texmf-dist/scripts/exceltex/exceltex \
	texmf-dist/scripts/fig4latex/fig4latex \
	texmf-dist/scripts/findhyph/findhyph \
	texmf-dist/scripts/fontools/afm2afm \
	texmf-dist/scripts/fontools/autoinst \
	texmf-dist/scripts/fontools/ot2kpx \
	texmf-dist/scripts/fragmaster/fragmaster.pl \
	texmf-dist/scripts/getmap/getmapdl.lua \
	texmf-dist/scripts/glossaries/makeglossaries \
	texmf-dist/scripts/installfont/installfont-tl \
	texmf-dist/scripts/jfontmaps/kanji-config-updmap-sys.sh \
	texmf-dist/scripts/jfontmaps/kanji-config-updmap.pl \
	texmf-dist/scripts/jfontmaps/kanji-fontmap-creator.pl \
	texmf-dist/scripts/kotex-utils/jamo-normalize.pl \
	texmf-dist/scripts/kotex-utils/komkindex.pl \
	texmf-dist/scripts/kotex-utils/ttf2kotexfont.pl \
	texmf-dist/scripts/latex-git-log/latex-git-log \
	texmf-dist/scripts/latex2man/latex2man \
	texmf-dist/scripts/latexdiff/latexdiff-vc.pl \
	texmf-dist/scripts/latexdiff/latexdiff.pl \
	texmf-dist/scripts/latexdiff/latexrevise.pl \
	texmf-dist/scripts/latexfileversion/latexfileversion \
	texmf-dist/scripts/latexindent/latexindent.pl \
	texmf-dist/scripts/latexmk/latexmk.pl \
	texmf-dist/scripts/latexpand/latexpand \
	texmf-dist/scripts/lilyglyphs/lily-glyph-commands.py \
	texmf-dist/scripts/lilyglyphs/lily-image-commands.py \
	texmf-dist/scripts/lilyglyphs/lily-rebuild-pdfs.py \
	texmf-dist/scripts/listbib/listbib \
	texmf-dist/scripts/listings-ext/listings-ext.sh \
	texmf-dist/scripts/ltxfileinfo/ltxfileinfo \
	texmf-dist/scripts/ltximg/ltximg.pl \
	texmf-dist/scripts/lua2dox/lua2dox_filter \
	texmf-dist/scripts/luaotfload/luaotfload-tool.lua \
	texmf-dist/scripts/m-tx/m-tx.lua \
	texmf-dist/scripts/match_parens/match_parens \
	texmf-dist/scripts/mathspic/mathspic.pl \
	texmf-dist/scripts/mf2pt1/mf2pt1.pl \
	texmf-dist/scripts/mkgrkindex/mkgrkindex \
	texmf-dist/scripts/mkjobtexmf/mkjobtexmf.pl \
	texmf-dist/scripts/mkpic/mkpic \
	texmf-dist/scripts/multibibliography/multibibliography.pl \
	texmf-dist/scripts/musixtex/musixflx.lua \
	texmf-dist/scripts/musixtex/musixtex.lua \
	texmf-dist/scripts/oberdiek/pdfatfi.pl \
	texmf-dist/scripts/pax/pdfannotextractor.pl \
	texmf-dist/scripts/pdfcrop/pdfcrop.pl \
	texmf-dist/scripts/pdfjam/pdf180 \
	texmf-dist/scripts/pdfjam/pdf270 \
	texmf-dist/scripts/pdfjam/pdf90 \
	texmf-dist/scripts/pdfjam/pdfbook \
	texmf-dist/scripts/pdfjam/pdfflip \
	texmf-dist/scripts/pdfjam/pdfjam \
	texmf-dist/scripts/pdfjam/pdfjam-pocketmod \
	texmf-dist/scripts/pdfjam/pdfjam-slides3up \
	texmf-dist/scripts/pdfjam/pdfjam-slides6up \
	texmf-dist/scripts/pdfjam/pdfjoin \
	texmf-dist/scripts/pdfjam/pdfnup \
	texmf-dist/scripts/pdfjam/pdfpun \
	texmf-dist/scripts/pedigree-perl/pedigree.pl \
	texmf-dist/scripts/perltex/perltex.pl \
	texmf-dist/scripts/pfarrei/a5toa4.tlu \
	texmf-dist/scripts/pfarrei/pfarrei.tlu \
	texmf-dist/scripts/pkfix-helper/pkfix-helper \
	texmf-dist/scripts/pkfix/pkfix.pl \
	texmf-dist/scripts/pmx/pmx2pdf.lua \
	texmf-dist/scripts/pmxchords/pmxchords.lua \
	texmf-dist/scripts/ps2eps/ps2eps.pl \
	texmf-dist/scripts/pst-pdf/ps4pdf \
	texmf-dist/scripts/pst2pdf/pst2pdf.pl \
	texmf-dist/scripts/ptex2pdf/ptex2pdf.lua \
	texmf-dist/scripts/purifyeps/purifyeps \
	texmf-dist/scripts/pygmentex/pygmentex.py \
	texmf-dist/scripts/pythontex/depythontex.py \
	texmf-dist/scripts/pythontex/pythontex.py \
	texmf-dist/scripts/rubik/rubikrotation.pl \
	texmf-dist/scripts/simpdftex/simpdftex \
	texmf-dist/scripts/splitindex/splitindex.pl \
	texmf-dist/scripts/sty2dtx/sty2dtx.pl \
	texmf-dist/scripts/svn-multi/svn-multi.pl \
	texmf-dist/scripts/tex4ht/ht.sh \
	texmf-dist/scripts/tex4ht/htcontext.sh \
	texmf-dist/scripts/tex4ht/htlatex.sh \
	texmf-dist/scripts/tex4ht/htmex.sh \
	texmf-dist/scripts/tex4ht/httex.sh \
	texmf-dist/scripts/tex4ht/httexi.sh \
	texmf-dist/scripts/tex4ht/htxelatex.sh \
	texmf-dist/scripts/tex4ht/htxetex.sh \
	texmf-dist/scripts/tex4ht/mk4ht.pl \
	texmf-dist/scripts/texcount/texcount.pl \
	texmf-dist/scripts/texdef/texdef.pl \
	texmf-dist/scripts/texdiff/texdiff \
	texmf-dist/scripts/texdirflatten/texdirflatten \
	texmf-dist/scripts/texdoc/texdoc.tlu \
	texmf-dist/scripts/texdoctk/texdoctk.pl \
	texmf-dist/scripts/texfot/texfot.pl \
	texmf-dist/scripts/texlive/allcm.sh \
	texmf-dist/scripts/texlive/allneeded.sh \
	texmf-dist/scripts/texlive/dvi2fax.sh \
	texmf-dist/scripts/texlive/dvired.sh \
	texmf-dist/scripts/texlive/e2pall.pl \
	texmf-dist/scripts/texlive/fmtutil-sys.sh \
	texmf-dist/scripts/texlive/fmtutil.pl \
	texmf-dist/scripts/texlive/fontinst.sh \
	texmf-dist/scripts/texlive/kpsetool.sh \
	texmf-dist/scripts/texlive/kpsewhere.sh \
	texmf-dist/scripts/texlive/ps2frag.sh \
	texmf-dist/scripts/texlive/pslatex.sh \
	texmf-dist/scripts/texlive/rubibtex.sh \
	texmf-dist/scripts/texlive/rumakeindex.sh \
	texmf-dist/scripts/texlive/rungs.tlu \
	texmf-dist/scripts/texlive/texconfig-dialog.sh \
	texmf-dist/scripts/texlive/texconfig-sys.sh \
	texmf-dist/scripts/texlive/texconfig.sh \
	texmf-dist/scripts/texlive/texlinks.sh \
	texmf-dist/scripts/texlive/tlmgr.pl \
	texmf-dist/scripts/texlive/updmap-sys.sh \
	texmf-dist/scripts/texlive/updmap.pl \
	texmf-dist/scripts/texliveonfly/texliveonfly.py \
	texmf-dist/scripts/texloganalyser/texloganalyser \
	texmf-dist/scripts/thumbpdf/thumbpdf.pl \
	texmf-dist/scripts/typeoutfileinfo/typeoutfileinfo.sh \
	texmf-dist/scripts/ulqda/ulqda.pl \
	texmf-dist/scripts/urlbst/urlbst \
	texmf-dist/scripts/vpe/vpe.pl \
	texmf-dist/scripts/yplan/yplan

EXTRACT_AFTER_ARGS=| ${TAR} xf - ${EXCLUDE_FILES:S,^,--exclude ${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}/,}

post-extract:
	cd ${WRKSRC}/latex-base-20150101.2 && \
	    ${SETENV} TEXMF=. ${LOCALBASE}/bin/tex -ini unpack.ins && \
	    ${RM} README *.log *.aux *.pdf *.dtx *.ins *.txt *.ist *.fdd *.err

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/tex/latex/base
	cd ${WRKSRC}/latex-base-20150101.2 && ${PAX} -rw . \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/tex/latex/base
	${REINPLACE_CMD} -i '' 's/\\def\\magyar@sugg@ie@low#1#2#3/\\def\\magyar@sugg@ie@low\\protect #1#2#3/' ${STAGEDIR}${PREFIX}/share/texmf-dist/tex/generic/babel-hungarian/magyar.ldf
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/doc
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/doc/.keep_me
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/source
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/source/.keep_me

post-install:
	@${REINPLACE_CMD} -i '' -e '1s|/bin/bash|${bash_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/logicpuzzle/createlpsudoku \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/logicpuzzle/lpsmag \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/shipunov/biokey2html.sh
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/perl|${perl_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/mycv/mycv_split_contents.pl
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/env python|${python_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/asymptote/GUI/*.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/*/*.py

.include <bsd.port.mk>

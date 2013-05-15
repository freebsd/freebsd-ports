# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20120701
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tug.org/historic/systems/texlive/2012/
PKGNAMESUFFIX=	-texmf
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree

USE_XZ=		yes
USE_TEX=	texlive base texhash
TEXHASHDIRS=	${TEXMFDIR} ${TEXMFDISTDIR}
NO_BUILD=	yes
NO_WRKSRC=	yes

EXCLUDE_FILES=	\*/doc/man/\* \
	texmf/web2c/mktex.opt \
	texmf/web2c/mktexdir \
	texmf/web2c/mktexdir.opt \
	texmf/web2c/mktexnam \
	texmf/web2c/mktexnam.opt \
	texmf/web2c/mktexupd \
	texmf/web2c/texmf.cnf \
	texmf/web2c/fmtutil.cnf \
	texmf/web2c/updmap-hdr.cnf \
	texmf/web2c/fmtutil-hdr.cnf \
	texmf/scripts/a2ping \
	texmf/scripts/chktex \
	texmf/scripts/ps2eps \
	texmf/scripts/tetex \
	texmf/scripts/simpdftex \
	texmf/scripts/texdoc/texdoc.tlu \
	texmf/scripts/texlive/rungs.tlu \
	texmf/scripts/texlive/tlmgr.pl \
	texmf/xdvi/* \
	texmf-dist/doc/aleph \
	texmf-dist/doc/lualatex \
	texmf-dist/doc/luatex \
	texmf-dist/doc/xelatex \
	texmf-dist/doc/xetex \
	texmf-dist/doc/otherformats/jadetex \
	texmf-dist/doc/otherformats/xmltex \
	texmf-dist/fonts/misc/xetex \
	texmf-dist/scripts/accfonts \
	texmf-dist/scripts/authorindex \
	texmf-dist/scripts/bibexport \
	texmf-dist/scripts/bundledoc \
	texmf-dist/scripts/cachepic/cachepic.tlu \
	texmf-dist/scripts/context/perl/mptopdf.pl \
	texmf-dist/scripts/ctanify \
	texmf-dist/scripts/ctanupload \
	texmf-dist/scripts/de-macro \
	texmf-dist/scripts/dosepsbin \
	texmf-dist/scripts/dviasm \
	texmf-dist/scripts/ebong \
	texmf-dist/scripts/epspdf/epspdf.rb \
	texmf-dist/scripts/epspdf/epspdftk.tcl \
	texmf-dist/scripts/epstopdf \
	texmf-dist/scripts/exceltex \
	texmf-dist/scripts/fig4latex \
	texmf-dist/scripts/findhyph \
	texmf-dist/scripts/fontools \
	texmf-dist/scripts/fragmaster \
	texmf-dist/scripts/glossaries/makeglossaries \
	texmf-dist/scripts/installfont \
	texmf-dist/scripts/jfontmaps \
	texmf-dist/scripts/latex2man \
	texmf-dist/scripts/latexdiff \
	texmf-dist/scripts/latexfileversion \
	texmf-dist/scripts/latexmk \
	texmf-dist/scripts/listbib \
	texmf-dist/scripts/listings-ext \
	texmf-dist/scripts/luaotfload \
	texmf-dist/scripts/m-tx/m-tx.lua \
	texmf-dist/scripts/match_parens \
	texmf-dist/scripts/mathspic \
	texmf-dist/scripts/mf2pt1 \
	texmf-dist/scripts/mkgrkindex \
	texmf-dist/scripts/mkjobtexmf \
	texmf-dist/scripts/musixtex/musixflx.lua \
	texmf-dist/scripts/musixtex/musixtex.lua \
	texmf-dist/scripts/oberdiek/pdfatfi.pl \
	texmf-dist/scripts/pax/pdfannotextractor.pl \
	texmf-dist/scripts/pdfcrop \
	texmf-dist/scripts/pdfjam \
	texmf-dist/scripts/pedigree-perl/pedigree.pl \
	texmf-dist/scripts/perltex \
	texmf-dist/scripts/pkfix-helper \
	texmf-dist/scripts/pkfix \
	texmf-dist/scripts/pmx/pmx2pdf.lua \
	texmf-dist/scripts/pst-pdf/ps4pdf \
	texmf-dist/scripts/pst2pdf \
	texmf-dist/scripts/purifyeps \
	texmf-dist/scripts/splitindex \
	texmf-dist/scripts/sty2dtx \
	texmf-dist/scripts/svn-multi \
	texmf-dist/scripts/tex4ht \
	texmf-dist/scripts/texcount \
	texmf-dist/scripts/texdef \
	texmf-dist/scripts/texdiff \
	texmf-dist/scripts/texdirflatten \
	texmf-dist/scripts/texliveonfly \
	texmf-dist/scripts/texloganalyser \
	texmf-dist/scripts/thumbpdf \
	texmf-dist/scripts/typeoutfileinfo \
	texmf-dist/scripts/ulqda \
	texmf-dist/scripts/uptex \
	texmf-dist/scripts/urlbst \
	texmf-dist/scripts/vpe \
	texmf-dist/scripts/xetex \
	texmf-dist/source/jadetex \
	texmf-dist/source/lambda \
	texmf-dist/source/luatex \
	texmf-dist/source/lualatex \
	texmf-dist/source/xelatex \
	texmf-dist/source/xmltex \
	texmf-dist/tex/generic/xetexconfig \
	texmf-dist/tex/jadetex \
	texmf-dist/tex/lambda \
	texmf-dist/tex/lualatex \
	texmf-dist/tex/luatex \
	texmf-dist/tex/latex/latexconfig/dvilualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatex-patch-kernel.tex \
	texmf-dist/tex/latex/latexconfig/lualatex-reset-codes.tex \
	texmf-dist/tex/latex/latexconfig/lualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
	texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
	texmf-dist/tex/latex/latexconfig/xelatex.ini \
	texmf-dist/tex/plain/config/aleph.ini \
	texmf-dist/tex/plain/config/dviluatex.ini \
	texmf-dist/tex/plain/config/luatex.ini \
	texmf-dist/tex/plain/config/xetex.ini \
	texmf-dist/tex/xelatex \
	texmf-dist/tex/xetex \
	texmf-dist/tex/xmltex \
	texmf/tex/generic/config/luatex-unicode-letters.tex \
	texmf/tex/generic/config/luatexiniconfig.tex \
	texmf-dist/doc/ptex \
	texmf-dist/doc/platex \
	texmf-dist/doc/uptex \
	texmf-dist/doc/uplatex \
	texmf-dist/doc/fonts/japanese-otf \
	texmf-dist/doc/fonts/japanese-otf-uptex \
	texmf-dist/doc/fonts/jfontmaps \
	texmf-dist/fonts/source/ptex \
	texmf-dist/fonts/ovp/public/japanese-otf-uptex \
	texmf-dist/fonts/vf/ptex \
	texmf-dist/fonts/vf/uptex \
	texmf-dist/fonts/vf/public/japanese-otf \
	texmf-dist/fonts/vf/public/japanese-otf-uptex \
	texmf-dist/fonts/type1/ptex \
	texmf-dist/fonts/tfm/ptex \
	texmf-dist/fonts/tfm/uptex \
	texmf-dist/fonts/tfm/public/japanese-otf-uptex \
	texmf-dist/fonts/tfm/public/japanese-otf \
	texmf-dist/fonts/ofm/public/japanese-otf \
	texmf-dist/source/fonts/uptex \
	texmf-dist/source/fonts/japanese-otf-uptex \
	texmf-dist/source/fonts/japanese-otf \
	texmf-dist/source/platex \
	texmf-dist/tex/ptex \
	texmf-dist/tex/uptex \
	texmf-dist/tex/platex \
	texmf-dist/tex/uplatex \
	texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
	texmf-dist/fonts/map/dvipdfmx/ptex \
	texmf-dist/fonts/map/dvipdfmx/uptex \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf-uptex \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf \
	texmf-dist/fonts/map/dvipdfmx/jfontmaps \
	texmf/fonts/map/dvipdfmx/updmap/kanjix.map \
	texmf-dist/fonts/cmap/uptex

EXTRACT_AFTER_ARGS=| ${TAR} xf - ${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20140525
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}-${DISTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, base binaries

RUN_DEPENDS=	psbook:${PORTSDIR}/print/psutils
LIB_DEPENDS=	libicuio.so:${PORTSDIR}/devel/icu \
		libt1.so:${PORTSDIR}/devel/t1lib \
		libTECkit.so:${PORTSDIR}/textproc/teckit \
		libgraphite.so:${PORTSDIR}/graphics/silgraphite \
		libgd.so:${PORTSDIR}/graphics/gd \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libttf.so:${PORTSDIR}/print/freetype \
		libpng15.so:${PORTSDIR}/graphics/png \
		libzzip.so:${PORTSDIR}/devel/zziplib \
		libpoppler.so:${PORTSDIR}/graphics/poppler
# XXX
#		libpotrace.so:${PORTSDIR}/graphics/potrace

CONFLICTS_INSTALL=	texlive-texmf-201[23]*

USE_TEX=	web2c kpathsea ptexenc texhash-bootstrap
USES=		gmake pkgconfig perl5 shebangfix tar:xz
USE_AUTOTOOLS=	autoconf
USE_GHOSTSCRIPT=yes
USE_PERL5=	run
USE_LDCONFIG=	yes
# during build phase gnu configure is run a lot
MAKE_ENV+=	CONFIG_SITE=${CONFIG_SITE}
USE_XORG=	x11 xmu xaw pixman
EXCLUDE_FILES=	${DISTNAME}/texk/web2c \
		${DISTNAME}/texk/kpathsea \
		${DISTNAME}/texk/ptexenc \
		${DISTNAME}/texk/xdvik \
		${DISTNAME}/texk/dvipdfm-x \
		${DISTNAME}/texk/dvipsk \
		${DISTNAME}/libs/freetype2 \
		${DISTNAME}/libs/gd \
		${DISTNAME}/libs/graphite \
		${DISTNAME}/libs/icu \
		${DISTNAME}/libs/liblua52 \
		${DISTNAME}/libs/libluajit \
		${DISTNAME}/libs/libpaper \
		${DISTNAME}/libs/libpng \
		${DISTNAME}/libs/pixman \
		${DISTNAME}/libs/poppler \
		${DISTNAME}/libs/teckit \
		${DISTNAME}/libs/xpdf \
		${DISTNAME}/libs/zlib \
		${DISTNAME}/libs/zziplib \
		${DISTNAME}/utils/biber \
		${DISTNAME}/utils/t1utils
# XXX
#		${DISTNAME}/libs/potrace
EXTRACT_AFTER_ARGS=	${EXCLUDE_FILES:S,^,--exclude ,}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-native-texlive-build \
		--disable-web-progs \
		--disable-psutils \
		--enable-shared \
		--disable-t1utils \
		--disable-dvipdfmx \
		--disable-dvipdfm-x \
		--disable-xdvipdfmx \
		--enable-build-in-source-tree \
		--datarootdir=${LOCALBASE}/share \
		--with-system-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-cairo \
		--with-system-gd \
		--with-system-graphite \
		--with-system-icu \
		--with-icu-include=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-include=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libgs \
		--with-libgs-includes=${LOCALBASE}/include \
		--with-libgs-libdir=${LOCALBASE}/lib \
		--with-system-libpaper \
		--with-libpaper-includes=${LOCALBASE}/include \
		--with-libpaper-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-pixman \
		--with-system-poppler \
		--with-system-ptexenc \
		--with-ptexenc-include=${LOCALBASE}/include/ptexenc \
		--with-ptexenc-libdir=${LOCALBASE}/lib \
		--with-system-t1lib \
		--with-system-teckit \
		--with-xpdf-includes=${LOCALBASE}/include/poppler \
		--with-xpdf-libdir=${LOCALBASE}/lib \
		--with-system-xpdf \
		--with-system-zziplib \
		--with-system-zlib
# XXX
# --with-system-potrace

CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/kpathsea \
		-I${LOCALBASE}/include/ptexenc
PLIST_SUB=	INSTALL_DATA="${INSTALL_DATA}"

SHEBANG_FILES=	texk/texlive/linked_scripts/a2ping/a2ping.pl \
		texk/texlive/linked_scripts/accfonts/mkt1font \
		texk/texlive/linked_scripts/accfonts/vpl2ovp \
		texk/texlive/linked_scripts/accfonts/vpl2vpl \
		texk/texlive/linked_scripts/adhocfilelist/adhocfilelist.sh \
		texk/texlive/linked_scripts/arara/arara.sh \
		texk/texlive/linked_scripts/authorindex/authorindex \
		texk/texlive/linked_scripts/bibexport/bibexport.sh \
		texk/texlive/linked_scripts/bundledoc/arlatex \
		texk/texlive/linked_scripts/bundledoc/bundledoc \
		texk/texlive/linked_scripts/cachepic/cachepic.tlu \
		texk/texlive/linked_scripts/checkcites/checkcites.lua \
		texk/texlive/linked_scripts/context/perl/mptopdf.pl \
		texk/texlive/linked_scripts/context/stubs/unix/context \
		texk/texlive/linked_scripts/context/stubs/unix/contextjit \
		texk/texlive/linked_scripts/context/stubs/unix/ctxtools \
		texk/texlive/linked_scripts/context/stubs/unix/luatools \
		texk/texlive/linked_scripts/context/stubs/unix/mtxrun \
		texk/texlive/linked_scripts/context/stubs/unix/mtxrunjit \
		texk/texlive/linked_scripts/context/stubs/unix/pstopdf \
		texk/texlive/linked_scripts/context/stubs/unix/texexec \
		texk/texlive/linked_scripts/context/stubs/unix/texmfstart \
		texk/texlive/linked_scripts/convbkmk/convbkmk.rb \
		texk/texlive/linked_scripts/ctanify/ctanify \
		texk/texlive/linked_scripts/ctanupload/ctanupload.pl \
		texk/texlive/linked_scripts/de-macro/de-macro \
		texk/texlive/linked_scripts/dosepsbin/dosepsbin.pl \
		texk/texlive/linked_scripts/dtxgen/dtxgen \
		texk/texlive/linked_scripts/dviasm/dviasm.py \
		texk/texlive/linked_scripts/ebong/ebong.py \
		texk/texlive/linked_scripts/epspdf/epspdf.tlu \
		texk/texlive/linked_scripts/epspdf/epspdftk.tcl \
		texk/texlive/linked_scripts/epstopdf/epstopdf.pl \
		texk/texlive/linked_scripts/exceltex/exceltex \
		texk/texlive/linked_scripts/fig4latex/fig4latex \
		texk/texlive/linked_scripts/findhyph/findhyph \
		texk/texlive/linked_scripts/fontools/afm2afm \
		texk/texlive/linked_scripts/fontools/autoinst \
		texk/texlive/linked_scripts/fontools/ot2kpx \
		texk/texlive/linked_scripts/fragmaster/fragmaster.pl \
		texk/texlive/linked_scripts/glossaries/makeglossaries \
		texk/texlive/linked_scripts/installfont/installfont-tl \
		texk/texlive/linked_scripts/jfontmaps/kanji-config-updmap-sys.sh \
		texk/texlive/linked_scripts/jfontmaps/kanji-config-updmap.pl \
		texk/texlive/linked_scripts/jfontmaps/kanji-fontmap-creator.pl \
		texk/texlive/linked_scripts/kotex-utils/jamo-normalize.pl \
		texk/texlive/linked_scripts/kotex-utils/komkindex.pl \
		texk/texlive/linked_scripts/kotex-utils/ttf2kotexfont.pl \
		texk/texlive/linked_scripts/latex-git-log/latex-git-log \
		texk/texlive/linked_scripts/latex2man/latex2man \
		texk/texlive/linked_scripts/latexdiff/latexdiff-vc.pl \
		texk/texlive/linked_scripts/latexdiff/latexdiff.pl \
		texk/texlive/linked_scripts/latexdiff/latexrevise.pl \
		texk/texlive/linked_scripts/latexfileversion/latexfileversion \
		texk/texlive/linked_scripts/latexindent/latexindent.pl \
		texk/texlive/linked_scripts/latexmk/latexmk.pl \
		texk/texlive/linked_scripts/latexpand/latexpand \
		texk/texlive/linked_scripts/lilyglyphs/lily-glyph-commands.py \
		texk/texlive/linked_scripts/lilyglyphs/lily-image-commands.py \
		texk/texlive/linked_scripts/lilyglyphs/lily-rebuild-pdfs.py \
		texk/texlive/linked_scripts/listbib/listbib \
		texk/texlive/linked_scripts/listings-ext/listings-ext.sh \
		texk/texlive/linked_scripts/ltxfileinfo/ltxfileinfo \
		texk/texlive/linked_scripts/ltximg/ltximg.pl \
		texk/texlive/linked_scripts/lua2dox/lua2dox_filter \
		texk/texlive/linked_scripts/luaotfload/luaotfload-tool.lua \
		texk/texlive/linked_scripts/m-tx/m-tx.lua \
		texk/texlive/linked_scripts/match_parens/match_parens \
		texk/texlive/linked_scripts/mathspic/mathspic.pl \
		texk/texlive/linked_scripts/mf2pt1/mf2pt1.pl \
		texk/texlive/linked_scripts/mkgrkindex/mkgrkindex \
		texk/texlive/linked_scripts/mkjobtexmf/mkjobtexmf.pl \
		texk/texlive/linked_scripts/mkpic/mkpic \
		texk/texlive/linked_scripts/multibibliography/multibibliography.pl \
		texk/texlive/linked_scripts/musixtex/musixflx.lua \
		texk/texlive/linked_scripts/musixtex/musixtex.lua \
		texk/texlive/linked_scripts/oberdiek/pdfatfi.pl \
		texk/texlive/linked_scripts/pax/pdfannotextractor.pl \
		texk/texlive/linked_scripts/pdfcrop/pdfcrop.pl \
		texk/texlive/linked_scripts/pdfjam/pdf180 \
		texk/texlive/linked_scripts/pdfjam/pdf270 \
		texk/texlive/linked_scripts/pdfjam/pdf90 \
		texk/texlive/linked_scripts/pdfjam/pdfbook \
		texk/texlive/linked_scripts/pdfjam/pdfflip \
		texk/texlive/linked_scripts/pdfjam/pdfjam \
		texk/texlive/linked_scripts/pdfjam/pdfjam-pocketmod \
		texk/texlive/linked_scripts/pdfjam/pdfjam-slides3up \
		texk/texlive/linked_scripts/pdfjam/pdfjam-slides6up \
		texk/texlive/linked_scripts/pdfjam/pdfjoin \
		texk/texlive/linked_scripts/pdfjam/pdfnup \
		texk/texlive/linked_scripts/pdfjam/pdfpun \
		texk/texlive/linked_scripts/pedigree-perl/pedigree.pl \
		texk/texlive/linked_scripts/perltex/perltex.pl \
		texk/texlive/linked_scripts/pfarrei/a5toa4.tlu \
		texk/texlive/linked_scripts/pfarrei/pfarrei.tlu \
		texk/texlive/linked_scripts/pkfix-helper/pkfix-helper \
		texk/texlive/linked_scripts/pkfix/pkfix.pl \
		texk/texlive/linked_scripts/pmx/pmx2pdf.lua \
		texk/texlive/linked_scripts/pmxchords/pmxchords.lua \
		texk/texlive/linked_scripts/pst-pdf/ps4pdf \
		texk/texlive/linked_scripts/pst2pdf/pst2pdf.pl \
		texk/texlive/linked_scripts/ptex2pdf/ptex2pdf.lua \
		texk/texlive/linked_scripts/purifyeps/purifyeps \
		texk/texlive/linked_scripts/pythontex/depythontex.py \
		texk/texlive/linked_scripts/pythontex/pythontex.py \
		texk/texlive/linked_scripts/rubik/rubikrotation.pl \
		texk/texlive/linked_scripts/scripts.lst \
		texk/texlive/linked_scripts/simpdftex/simpdftex \
		texk/texlive/linked_scripts/splitindex/splitindex.pl \
		texk/texlive/linked_scripts/sty2dtx/sty2dtx.pl \
		texk/texlive/linked_scripts/svn-multi/svn-multi.pl \
		texk/texlive/linked_scripts/texcount/texcount.pl \
		texk/texlive/linked_scripts/texdef/texdef.pl \
		texk/texlive/linked_scripts/texdiff/texdiff \
		texk/texlive/linked_scripts/texdirflatten/texdirflatten \
		texk/texlive/linked_scripts/texdoc/texdoc.tlu \
		texk/texlive/linked_scripts/texfot/texfot.pl \
		texk/texlive/linked_scripts/texlive/rungs.tlu \
		texk/texlive/linked_scripts/texlive/tlmgr.pl \
		texk/texlive/linked_scripts/texlive/updmap.pl \
		texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
		texk/texlive/linked_scripts/texloganalyser/texloganalyser \
		texk/texlive/linked_scripts/thumbpdf/thumbpdf.pl \
		texk/texlive/linked_scripts/typeoutfileinfo/typeoutfileinfo.sh \
		texk/texlive/linked_scripts/ulqda/ulqda.pl \
		texk/texlive/linked_scripts/urlbst/urlbst \
		texk/texlive/linked_scripts/vpe/vpe.pl
INFO=	dvipng tlbuild

post-patch:
	cd ${WRKSRC}/texk/texlive/tl_scripts && \
	    ${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
	    fmtutil-sys.sh texconfig-sys.sh updmap-sys.sh

post-install-fmtutil:
	for D in ${TEXHASHDIRS}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/$$D; \
		${TOUCH} ${STAGEDIR}${PREFIX}/$$D/.keep_me; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c/.keep_me
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/fmtutil.cnf \
		${STAGEDIR}${PREFIX}/${FMTUTIL_CNF}

post-install: post-install-fmtutil
.ORDER: post-install-fmtutil do-texhash

.include <bsd.port.mk>

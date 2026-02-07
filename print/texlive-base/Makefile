PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, base binaries
WWW=		https://tug.org/texlive/

LIB_DEPENDS=	libicuio.so:devel/icu \
		libt1.so:devel/t1lib \
		libTECkit.so:textproc/teckit \
		libgd.so:graphics/gd \
		libgraphite2.so:graphics/graphite2 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libpng.so:graphics/png \
		libzzip.so:devel/zziplib \
		libpoppler.so:graphics/poppler \
		libpotrace.so:graphics/libpotrace
RUN_DEPENDS=	p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		psbook:print/psutils

USES=		compiler:c++11-lib cpe ghostscript gnome localbase pkgconfig perl5 \
		python:run shebangfix tar:xz tex xorg
CPE_VENDOR=	tug
USE_CXXSTD=	gnu++11
USE_GNOME=	cairo
USE_PERL5=	run
USE_TEX=	web2c kpathsea ptexenc tlmgr texhash-bootstrap
USE_XORG=x11
SHEBANG_FILES=	texk/texlive/linked_scripts/accfonts/mkt1font \
	texk/texlive/linked_scripts/accfonts/vpl2ovp \
	texk/texlive/linked_scripts/accfonts/vpl2vpl \
	texk/texlive/linked_scripts/aomart/aom-fullref.pl \
	texk/texlive/linked_scripts/arara/arara.sh \
	texk/texlive/linked_scripts/bibcop/bibcop.pl \
	texk/texlive/linked_scripts/bibexport/bibexport.sh \
	texk/texlive/linked_scripts/convbkmk/convbkmk.rb \
	texk/texlive/linked_scripts/ctanupload/ctanupload.pl \
	texk/texlive/linked_scripts/ebong/*.py \
	texk/texlive/linked_scripts/dtxgen/dtxgen \
	texk/texlive/linked_scripts/dviasm/*.py \
	texk/texlive/linked_scripts/exceltex/exceltex \
	texk/texlive/linked_scripts/findhyph/findhyph \
	texk/texlive/linked_scripts/fragmaster/fragmaster.pl \
	texk/texlive/linked_scripts/git-latexdiff/git-latexdiff \
	texk/texlive/linked_scripts/installfont/installfont-tl \
	texk/texlive/linked_scripts/kotex-utils/jamo-normalize.pl \
	texk/texlive/linked_scripts/latexpand/latexpand \
	texk/texlive/linked_scripts/lilyglyphs/*.py \
	texk/texlive/linked_scripts/ltxfileinfo/ltxfileinfo \
	texk/texlive/linked_scripts/mathspic/mathspic.pl \
	texk/texlive/linked_scripts/mf2pt1/mf2pt1.pl \
	texk/texlive/linked_scripts/minted/latexminted.py \
	texk/texlive/linked_scripts/multibibliography/multibibliography.pl \
	texk/texlive/linked_scripts/optexcount/optexcount \
	texk/texlive/linked_scripts/pygmentex/*.py \
	texk/texlive/linked_scripts/pythontex/*.py \
	texk/texlive/linked_scripts/rubik/rubikrotation.pl \
	texk/texlive/linked_scripts/spix/spix.py \
	texk/texlive/linked_scripts/splitindex/splitindex.pl \
	texk/texlive/linked_scripts/svn-multi/svn-multi.pl \
	texk/texlive/linked_scripts/texdirflatten/texdirflatten \
	texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
	texk/texlive/linked_scripts/ulqda/ulqda.pl \
	texk/texlive/linked_scripts/urlbst/urlbst \
	texk/texlive/linked_scripts/yplan/yplan \
	texk/texlive/linked_scripts/webquiz/webquiz.py \
	texk/texlive/linked_scripts/petri-nets/pn2pdf \
	texk/texlive/linked_scripts/pdflatexpicscale/pdflatexpicscale.pl \
	texk/texlive/linked_scripts/pdfxup/pdfxup \
	texk/texlive/linked_scripts/tlcockpit/tlcockpit.sh \
	texk/texlive/linked_scripts/ctan-o-mat/ctan-o-mat.pl \
	texk/texlive/linked_scripts/pdftex-quiet/pdftex-quiet \
	texk/texlive/linked_scripts/clojure-pamphlet/pamphletangler \
	texk/texlive/linked_scripts/latex-papersize/latex-papersize.py \
	texk/texlive/linked_scripts/makedtx/makedtx.pl \
	texk/texlive/linked_scripts/pdfbook2/pdfbook2

# during build phase gnu configure is run a lot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-native-texlive-build \
		--disable-web-progs \
		--disable-psutils \
		--enable-shared \
		--disable-t1utils \
		--disable-dvipdfmx \
		--disable-dvipdfm-x \
		--disable-xdvipdfmx \
		--enable-build-in-source-tree \
		--datarootdir=${LOCALBASE}/share \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-gd \
		--with-system-cairo \
		--with-system-harfbuzz \
		--with-system-graphite2 \
		--with-system-pixman \
		--with-system-t1lib \
		--without-system-xpdf \
		--with-system-zziplib \
		--with-system-zlib
.for L in gmp icu kpathsea libgs libpng libpaper mpfr ptexenc potrace teckit
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
MAKE_ENV=	CONFIG_SITE=${CONFIG_SITE}
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	detex dvi2tty ps2eps

BINARY_ALIAS=	freetype-config=true
EXTRACT_AFTER_ARGS=	${EXCLUDE_FILES:S,^,--exclude ,}

INFO=	dvipng tlbuild
PLIST_SUB=	INSTALL_DATA="${INSTALL_DATA}"

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=	TEX=xpdfopen:run

EXCLUDE_FILES=	${DISTNAME}/texk/web2c \
		${DISTNAME}/texk/kpathsea \
		${DISTNAME}/texk/ptexenc \
		${DISTNAME}/texk/xdvik \
		${DISTNAME}/texk/dvipdfm-x \
		${DISTNAME}/texk/dvipsk \
		${DISTNAME}/utils/t1utils \
		${DISTNAME}/utils/xpdfopen \
		${DISTNAME}/texk/texlive/linked_scripts/eolang/eolang.pl \
		${DISTNAME}/texk/texlive/linked_scripts/memoize/memoize-clean.pl \
		${DISTNAME}/texk/texlive/linked_scripts/memoize/memoize-clean.py \
		${DISTNAME}/texk/texlive/linked_scripts/memoize/memoize-extract.py \
		${DISTNAME}/texk/texlive/linked_scripts/runtexshebang/runtexshebang.lua

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python -O|${python_CMD}|' \
		${WRKSRC}/texk/texlive/linked_scripts/de-macro/de-macro
	${REINPLACE_CMD} -e 's|exec texconfig|exec ${PREFIX}/bin/texconfig|' \
		${WRKSRC}/texk/texlive/linked_scripts/texlive-extra/texconfig-sys.sh
	${REINPLACE_CMD} -e 's|exec fmtutil|exec ${PREFIX}/bin/fmtutil|' \
		${WRKSRC}/texk/texlive/linked_scripts/texlive/fmtutil-sys.sh
	${REINPLACE_CMD} -e 's|exec updmap|exec ${PREFIX}/bin/updmap|' \
		${WRKSRC}/texk/texlive/linked_scripts/texlive/updmap-sys.sh

post-install-fmtutil:
	for D in ${TEXHASHDIRS}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/$$D; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/fmtutil.cnf \
	    ${STAGEDIR}${PREFIX}/${FMTUTIL_CNF}

post-install: post-install-fmtutil
.ORDER: post-install-fmtutil do-texhash

.include <bsd.port.mk>

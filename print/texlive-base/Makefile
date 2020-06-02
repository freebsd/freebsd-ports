# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20150521
PORTREVISION=	52
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}-${DISTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, base binaries

RUN_DEPENDS=	psbook:print/psutils
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

CONFLICTS_INSTALL=	texlive-texmf-201[234]*

USE_TEX=	web2c kpathsea ptexenc tlmgr texhash-bootstrap
USES=		compiler:c++11-lib ghostscript pkgconfig perl5 \
		python:run shebangfix tar:xz
USE_CXXSTD=	gnu++11
USE_PERL5=	run
# during build phase gnu configure is run a lot
MAKE_ENV+=	CONFIG_SITE=${CONFIG_SITE}
EXCLUDE_FILES=	${DISTNAME}/texk/web2c \
		${DISTNAME}/texk/kpathsea \
		${DISTNAME}/texk/ptexenc \
		${DISTNAME}/texk/xdvik \
		${DISTNAME}/texk/dvipdfm-x \
		${DISTNAME}/texk/dvipsk \
		${DISTNAME}/libs \
		${DISTNAME}/utils/t1utils \
		${DISTNAME}/utils/xpdfopen
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
		--disable-xpdfopen \
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
		--with-system-poppler \
		--with-system-t1lib \
		--with-xpdf-includes=${LOCALBASE}/include/poppler \
		--with-xpdf-libdir=${LOCALBASE}/lib \
		--with-system-xpdf \
		--with-system-zziplib \
		--with-system-zlib
.for L in gmp icu kpathsea libgs libpng libpaper mpfr ptexenc potrace teckit
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor

CFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB=	INSTALL_DATA="${INSTALL_DATA}"
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	texk/texlive/linked_scripts/accfonts/mkt1font \
	texk/texlive/linked_scripts/accfonts/vpl2ovp \
	texk/texlive/linked_scripts/accfonts/vpl2vpl \
	texk/texlive/linked_scripts/arara/arara.sh \
	texk/texlive/linked_scripts/bibexport/bibexport.sh \
	texk/texlive/linked_scripts/convbkmk/convbkmk.rb \
	texk/texlive/linked_scripts/ctanupload/ctanupload.pl \
	texk/texlive/linked_scripts/ebong/*.py \
	texk/texlive/linked_scripts/dtxgen/dtxgen \
	texk/texlive/linked_scripts/dviasm/*.py \
	texk/texlive/linked_scripts/exceltex/exceltex \
	texk/texlive/linked_scripts/findhyph/findhyph \
	texk/texlive/linked_scripts/fragmaster/fragmaster.pl \
	texk/texlive/linked_scripts/installfont/installfont-tl \
	texk/texlive/linked_scripts/kotex-utils/jamo-normalize.pl \
	texk/texlive/linked_scripts/latexpand/latexpand \
	texk/texlive/linked_scripts/lilyglyphs/*.py \
	texk/texlive/linked_scripts/ltxfileinfo/ltxfileinfo \
	texk/texlive/linked_scripts/lua2dox/lua2dox_filter \
	texk/texlive/linked_scripts/mathspic/mathspic.pl \
	texk/texlive/linked_scripts/mf2pt1/mf2pt1.pl \
	texk/texlive/linked_scripts/multibibliography/multibibliography.pl \
	texk/texlive/linked_scripts/pygmentex/*.py \
	texk/texlive/linked_scripts/pythontex/*.py \
	texk/texlive/linked_scripts/rubik/rubikrotation.pl \
	texk/texlive/linked_scripts/splitindex/splitindex.pl \
	texk/texlive/linked_scripts/svn-multi/svn-multi.pl \
	texk/texlive/linked_scripts/texdirflatten/texdirflatten \
	texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
	texk/texlive/linked_scripts/ulqda/ulqda.pl \
	texk/texlive/linked_scripts/urlbst/urlbst \
	texk/texlive/linked_scripts/yplan/yplan

INFO=	dvipng tlbuild

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=	TEX=xpdfopen:run

post-patch:
	cd ${WRKSRC}/texk/texlive && \
	    ${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
	    linked_scripts/texlive/fmtutil-sys.sh \
	    tl_scripts/texconfig-sys.sh \
	    linked_scripts/texlive/updmap-sys.sh
	${REINPLACE_CMD} -e 's|/usr/bin/python -O|${python_CMD}|' \
		${WRKSRC}/texk/texlive/linked_scripts/de-macro/de-macro \

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

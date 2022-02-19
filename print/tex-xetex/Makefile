PORTNAME=	xetex
PORTVERSION=	0.99993
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${TEXLIVE_VERSION}-source${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX System with Unicode and Modern Font Technologies

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libicuio.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libpng.so:graphics/png \
		libTECkit.so:textproc/teckit

USES=		compiler:c++11-lib gnome perl5 pkgconfig python:build tar:xz xorg
USE_CXXSTD=	gnu++11
USE_GNOME=	cairo
USE_PERL5=	build
USE_TEX=	kpathsea web2c texmf formats fmtutil dvipdfmx
USE_XORG=	pixman

TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/pplib \
		libs/xpdf \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTNAME_TEXMF=	texlive-${TEXLIVE_VERSION}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/xelatex \
	texmf-dist/doc/xetex \
	texmf-dist/fonts/misc/xetex \
	texmf-dist/source/xelatex \
	texmf-dist/tex/xelatex \
	texmf-dist/tex/xetex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph etex pdftex luatex luajittex mf mf-nowin \
		mflua mfluajit luahbtex luajithbtex ptex eptex uptex euptex \
		otangle mp pmp upmp web2c web-progs tex synctex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-xetex \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-graphite2 \
		--with-graphite2-includes=${LOCALBASE}/include/graphite2 \
		--with-graphite2-libdir=${LOCALBASE}/lib \
		--with-system-harfbuzz \
		--with-system-teckit \
		--with-teckit-includes=${LOCALBASE}/include/teckit \
		--with-teckit-libdir=${LOCALBASE}/lib \
		--with-system-zziplib \
		--with-system-zlib
.for L in cairo gmp kpathsea libpng mpfr pixman ptexenc icu
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CONFIGURE_ARGS+=CC="${CC}" \
		CXX="${CXX}"
CPPFLAGS+=	-I${LOCALBASE}/include/harfbuzz -I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	xetex

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-configure:
	for D in libs/xpdf libs/pplib; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		    ${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
			${CONFIGURE_ARGS}; \
	done
	cd ${WRKDIR}/${DISTNAME}/libs/pplib && \
		${MAKE}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

post-stage:
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/xelatex/xepersian/dkun-0.3.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/xelatex/xepersian/dkun-0.4.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/xelatex/xepersian/undk-0.6.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/xelatex/xepersian/unldk-0.2.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/xelatex/arabxetex/makemaps.pl
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>

PORTNAME=	luatex
DISTVERSION=	${TEXLIVE_VERSION}
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Extended version of pdfTeX using Lua

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libmpfr.so:math/mpfr \
		libpng.so:graphics/png \
		libTECkit.so:textproc/teckit \
		libzzip.so:devel/zziplib

USES=		gmake gnome libtool localbase pkgconfig python:env tar:xz tex xorg
USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_TEX=	fmtutil formats kpathsea texlua texluajit web2c
USE_XORG=	pixman

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	${EXCLUDE_ENGINES:S/^/--disable-/} \
			--enable-luajittex \
			--enable-luatex \
			--enable-luahbtex \
			--enable-luajithbtex \
			--with-system-zlib \
			--with-system-zziplib
CONFIGURE_ENV+=		${MAKE_ENV}

.for L in cairo freetype2 gmp graphite2 harfbuzz kpathsea libpng mpfr pixman ptexenc teckit
CONFIGURE_ARGS+=	--with-$L-include=${LOCALBASE}/include \
			--with-$L-libdir=${LOCALBASE}/lib \
			--with-system-$L
.endfor

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=			build-aux libs/xpdf libs/lua53 libs/luajit \
				libs/pplib texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
				--strip-components 1 --no-same-permission \
				--no-same-owner \
				${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
EXTRACT_FILES_TEXMF=		texmf-dist/doc/lualatex texmf-dist/doc/luatex \
				texmf-dist/scripts/context/lua \
				texmf-dist/source/luatex \
				texmf-dist/source/lualatex \
				texmf-dist/fonts/map/luatex \
				texmf-dist/tex/luatex \
				texmf-dist/tex/generic/config/luatex-unicode-letters.tex \
				texmf-dist/tex/generic/context/luatex \
				texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
				texmf-dist/tex/lualatex
WRKSRC=				${WRKDIR}/${DISTNAME}/texk/web2c
EXCLUDE_ENGINES=		aleph etex pdftex mf mf-nowin ptex eptex uptex \
				euptex otangle mp pmp upmp web2c web-progs \
				xetex tex synctex mflua mfluajit texprof hitex
TEX_FORMATS=			luatex

TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}

# buildenv and dumpenv in Makefile uses hard-coded TEXMFCNF.
post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	cd ${WRKSRC}/.. && \
	    ${LN} -s -f ${LOCALBASE}/${TEXMFDISTDIR}/web2c kpathsea

post-patch:
	${REINPLACE_CMD} -E 's|gcc|${CC}|' \
		${WRKSRC}/../../libs/luajit/LuaJIT-src/src/Makefile

pre-configure:
	for D in libs/xpdf libs/pplib; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}; \
	done
	cd ${WRKDIR}/${DISTNAME}/libs/pplib && \
		${MAKE}
	cd ${WRKDIR}/${DISTNAME}/libs/luajit/LuaJIT-src/src && \
		${GMAKE} luajit.h

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_TEXMF}
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${PREFIX}/bin/bash|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/lualatex/wallcalendar/doc/examples/diff-cal.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/luatex/opbible/examples/make-all
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/python3|${PYTHON_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/luatex/opbible/txs-gen/maketxs.py

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}
	${ECHO_CMD} "share/texmf-var/web2c/luatex/lollipop.log" >> ${TMPPLIST}
	${ECHO_CMD} "share/texmf-var/web2c/luatex/lollipop.fmt" >> ${TMPPLIST}

.include <bsd.port.mk>

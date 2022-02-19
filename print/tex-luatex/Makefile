PORTNAME=	luatex
PORTVERSION=	1.12.0
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Extended version of pdfTeX using Lua

LIB_DEPENDS=	libpng.so:graphics/png \
		libmpfr.so:math/mpfr \
		libzzip.so:devel/zziplib

USES=		gnome libtool pkgconfig shebangfix tar:xz xorg
USE_TEX=	kpathsea web2c texmf formats texlua texluajit fmtutil
USE_XORG=	pixman
USE_GNOME=	cairo
USE_LDCONFIG=	yes
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		libs/lua53 \
		libs/luajit \
		libs/pplib \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTNAME_TEXMF=	texlive-${TEXLIVE_VERSION}-texmf
EXTRACT_FILES_TEXMF=	\
	texmf-dist/doc/lualatex \
	texmf-dist/doc/luatex \
	texmf-dist/scripts/context/lua \
	texmf-dist/source/luatex \
	texmf-dist/source/lualatex \
	texmf-dist/fonts/map/luatex \
	texmf-dist/tex/luatex \
	texmf-dist/tex/generic/config/luatex-unicode-letters.tex \
	texmf-dist/tex/generic/config/luatexiniconfig.tex \
	texmf-dist/tex/generic/context/luatex \
	texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
	texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
	texmf-dist/tex/lualatex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph etex pdftex mf mf-nowin \
		ptex eptex uptex euptex \
		otangle mp pmp upmp web2c web-progs xetex tex synctex \
		mflua mfluajit luahbtex luajithbtex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-luatex \
		--enable-luajittex \
		--with-system-zlib \
		--with-system-zziplib
.for L in cairo gmp kpathsea libpng mpfr pixman ptexenc
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CONFIGURE_ARGS+=CC="${CC}" \
		CXX="${CXX}"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	luatex

# buildenv and dumpenv in Makefile uses hard-coded TEXMFCNF.
post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	cd ${WRKSRC}/.. && \
	    ${LN} -s -f ${LOCALBASE}/${TEXMFDISTDIR}/web2c kpathsea

pre-configure:
	for D in libs/xpdf libs/pplib; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}; \
	done
	cd ${WRKDIR}/${DISTNAME}/libs/pplib && \
		${MAKE}

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_TEXMF}
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${PREFIX}/bin/bash|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/doc/lualatex/wallcalendar/doc/examples/diff-cal.sh

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}
	${ECHO_CMD} "share/texmf-var/web2c/luatex/lollipop.log" >> ${TMPPLIST}
	${ECHO_CMD} "share/texmf-var/web2c/luatex/lollipop.fmt" >> ${TMPPLIST} 

.include <bsd.port.mk>

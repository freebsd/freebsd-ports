# $FreeBSD$

PORTNAME=	xetex
PORTVERSION=	0.99992
PORTREVISION=	15
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX System with Unicode and Modern Font Technologies

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libicuio.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libTECkit.so:textproc/teckit

USES=		compiler:c++11-lib pkgconfig tar:xz
USE_CXXSTD=	gnu++11
USE_TEX=	kpathsea web2c texmf formats fmtutil dvipdfmx
USE_XORG=	pixman
USE_GNOME=	cairo
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE_SOURCE=20150521
DISTVERSION_TEXLIVE_TEXMF=20150523
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/xelatex \
	texmf-dist/doc/xetex \
	texmf-dist/fonts/misc/xetex \
	texmf-dist/scripts/xetex \
	texmf-dist/source/xelatex \
	texmf-dist/tex/latex/latexconfig/xelatex.ini \
	texmf-dist/tex/plain/config/xetex.ini \
	texmf-dist/tex/xelatex \
	texmf-dist/tex/xetex \
	texmf-dist/tex/generic/xetexconfig/unicode-letters.tex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph etex pdftex luatex luajittex mf mf-nowin \
		ptex eptex uptex euptex \
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
		--with-system-poppler \
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
CPPFLAGS+=	-I${LOCALBASE}/include/harfbuzz -I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	xetex

pre-configure:
	for D in libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		    ${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
			${CONFIGURE_ARGS}; \
	done

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

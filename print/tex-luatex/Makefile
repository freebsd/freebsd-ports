# $FreeBSD$

PORTNAME=	luatex
PORTVERSION=	0.80.0
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Extended version of pdfTeX using Lua

LIB_DEPENDS=	libpng.so:graphics/png \
		libmpfr.so:math/mpfr \
		libzzip.so:devel/zziplib

USES=		pkgconfig tar:xz libtool
USE_TEX=	kpathsea web2c texmf formats texlua texluajit fmtutil
USE_XORG=	pixman
USE_GNOME=	cairo
USE_LDCONFIG=	yes
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		libs/lua52 \
		libs/luajit \
		libs/poppler \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE_SOURCE=	20150521
DISTVERSION_TEXLIVE_TEXMF=	20150523
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf
EXTRACT_FILES_TEXMF=	\
	texmf-dist/doc/lualatex \
	texmf-dist/doc/luatex \
	texmf-dist/scripts/context/lua \
	texmf-dist/source/luatex \
	texmf-dist/source/lualatex \
	texmf-dist/fonts/map/luatex \
	texmf-dist/tex/plain/config/dviluatex.ini \
	texmf-dist/tex/luatex \
	texmf-dist/tex/plain/config/luatex.ini \
	texmf-dist/tex/generic/config/luatex-unicode-letters.tex \
	texmf-dist/tex/generic/config/luatexiniconfig.tex \
	texmf-dist/tex/generic/context/luatex \
	texmf-dist/tex/latex/latexconfig/dvilualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatex-reset-codes.tex \
	texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
	texmf-dist/tex/latex/latexconfig/lualatex-patch-kernel.tex \
	texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
	texmf-dist/tex/latex/latexconfig/lualatex.ini \
	texmf-dist/tex/lualatex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph etex pdftex mf mf-nowin \
		ptex eptex uptex euptex \
		otangle mp pmp upmp web2c web-progs xetex tex synctex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-luatex \
		--enable-luajittex \
		--without-system-poppler \
		--with-system-zlib \
		--with-system-zziplib
.for L in cairo gmp kpathsea libpng mpfr pixman ptexenc
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	luatex

# buildenv and dumpenv in Makefile uses hard-coded TEXMFCNF.
post-extract:
	cd ${WRKSRC}/.. && \
	    ${LN} -s -f ${LOCALBASE}/${TEXMFDISTDIR}/web2c kpathsea

pre-configure:
	for D in libs/xpdf libs/poppler; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}; \
	done

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

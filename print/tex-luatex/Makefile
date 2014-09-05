# $FreeBSD$

PORTNAME=	luatex
PORTVERSION=	0.79.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXMF}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXMF}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Extended version of pdfTeX using Lua

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgraphite.so:${PORTSDIR}/graphics/silgraphite \
		libicuio.so:${PORTSDIR}/devel/icu \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpoppler.so:${PORTSDIR}/graphics/poppler \
		libTECkit.so:${PORTSDIR}/textproc/teckit \
		libzzip.so:${PORTSDIR}/devel/zziplib

USE_TEX=	kpathsea web2c texmf formats fmtutil
USE_XORG=	pixman
USES=		pkgconfig tar:xz gmake
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	\
	build-aux \
	libs/xpdf \
	libs/cairo \
	libs/pixman \
	libs/lua52 \
	libs/luajit \
	texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXMF=20140525
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
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
EXCLUDE_ENGINES=aleph etex pdftex mf mf-nowin mp ptex eptex uptex euptex \
		xetex tex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-luatex \
		--enable-luajittex \
		--enable-web2c \
		--disable-web-progs \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-gd \
		--with-system-icu \
		--with-icu-includes=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-libpng-includes=${LOCALBASE}/include \
		--with-libpng-libdir=${LOCALBASE}/lib \
		--with-system-poppler \
		--with-system-t1lib \
		--with-system-teckit \
		--with-teckit-includes=${LOCALBASE}/include/teckit \
		--with-teckit-libdir=${LOCALBASE}/lib \
		--with-system-pixman \
		--with-system-zziplib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	luatex

pre-configure:
	for D in libs/xpdf libs/cairo libs/lua52 libs/luajit; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

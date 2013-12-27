# $FreeBSD$

PORTNAME=	luatex
PORTVERSION=	0.70.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXMF}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXMF}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Extended version of pdfTeX using Lua

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		graphite:${PORTSDIR}/graphics/silgraphite \
		icuio:${PORTSDIR}/devel/icu \
		png15:${PORTSDIR}/graphics/png \
		libpoppler.so:${PORTSDIR}/graphics/poppler \
		TECkit:${PORTSDIR}/textproc/teckit \
		zzip:${PORTSDIR}/devel/zziplib

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	texlive kpathsea web2c texmf formats fmtutil
USES=		pkgconfig
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	\
	build-aux \
	libs/obsdcompat \
	libs/xpdf \
	texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXMF=20120701
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/tex/latex/latexconfig/dvilualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatex-patch-kernel.tex \
	texmf-dist/tex/latex/latexconfig/lualatex-reset-codes.tex \
	texmf-dist/tex/latex/latexconfig/lualatex.ini \
	texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
	texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
	texmf-dist/tex/lualatex \
	texmf-dist/tex/luatex \
	texmf-dist/tex/plain/config/dviluatex.ini \
	texmf-dist/tex/plain/config/luatex.ini \
	texmf/tex/generic/config/luatex-unicode-letters.tex \
	texmf/tex/generic/config/luatexiniconfig.tex \
	texmf-dist/doc/lualatex \
	texmf-dist/doc/luatex \
	texmf-dist/source/luatex \
	texmf-dist/source/lualatex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OBSDCOMPAT_INCLUDES=-I${WRKSRC}/../../libs/obsdcompat
EXCLUDE_ENGINES= aleph etex pdftex mf mf-nowin ptex eptex uptex euptex xetex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-luatex \
		--enable-mp \
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
		--with-system-zziplib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	luatex

NO_STAGE=	yes
pre-configure:
	for D in libs/obsdcompat libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

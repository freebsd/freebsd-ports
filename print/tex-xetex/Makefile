# $FreeBSD$

PORTNAME=	xetex
PORTVERSION=	0.9999
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://people.allbsd.org/~hrs/FreeBSD/:web2c \
		ftp://tug.org/historic/systems/texlive/2012/:texmf
PKGNAMEPREFIX=	tex-
DISTNAME=	web2c-29235
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:web2c \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}:texmf
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX System with Unicode and Modern Font Technologies

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgraphite2.so:${PORTSDIR}/graphics/graphite2 \
		libicuio.so:${PORTSDIR}/devel/icu \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpoppler.so:${PORTSDIR}/graphics/poppler \
		libTECkit.so:${PORTSDIR}/textproc/teckit

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	texlive kpathsea web2c texmf formats fmtutil
USES=		pkgconfig
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	build-aux \
	libs/xpdf \
	libs/harfbuzz \
	texk/web2c
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTNAME_TEXMF=	texlive-20120701-texmf
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
EXCLUDE_ENGINES= aleph etex pdftex luatex mf mf-nowin mp ptex eptex uptex euptex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-xetex \
		--enable-web2c \
		--disable-web-progs \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-graphite2 \
		--with-graphite2-includes=${LOCALBASE}/include/graphite2 \
		--with-graphite2-libdir=${LOCALBASE}/lib \
		--with-system-icu \
		--with-icu-include=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-libpng-includes=${LOCALBASE}/include \
		--with-libpng-libdir=${LOCALBASE}/lib \
		--with-system-poppler \
		--with-system-teckit \
		--with-teckit-includes=${LOCALBASE}/include/teckit \
		--with-teckit-libdir=${LOCALBASE}/lib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	xetex

NO_STAGE=	yes
pre-configure:
	for D in libs/harfbuzz libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-20120701-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	aleph
PORTVERSION=	1.15.2.1.r.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Engine including Omega and e-TeX features

USES=		gmake tar:xz pkgconfig
USE_TEX=	kpathsea web2c texmf formats fmtutil
USE_XORG=	pixman
USE_GNOME=	cairo
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE_SOURCE=	20150521
DISTVERSION_TEXLIVE_TEXMF=	20150523
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/tex/plain/config/aleph.ini \
	texmf-dist/doc/aleph \
	texmf-dist/source/lambda \
	texmf-dist/tex/lambda
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=etex luatex luajittex pdftex mf mf-nowin ptex eptex uptex \
		euptex xetex tex synctex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-aleph \
		--enable-otangle \
		--disable-mp \
		--enable-web2c \
		--disable-web-progs \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-poppler \
		--with-system-t1lib \
		--with-system-zziplib \
		--with-system-zlib
.for L in cairo gmp kpathsea libpng mpfr pixman ptexenc
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	aleph

OPTIONS_DEFINE=	SOURCE
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSOURCE)
EXTRACT_FILES_TEXMF:=	${EXTRACT_FILES_TEXMF:Ntexmf-dist/source/*}
.endif

# buildenv and dumpenv in Makefile uses hard-coded TEXMFCNF.
post-extract:
	cd ${WRKSRC}/.. && \
	    ${LN} -s -f ${LOCALBASE}/${TEXMFDISTDIR}/web2c kpathsea

pre-configure:
	for D in libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}; \
	done

pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

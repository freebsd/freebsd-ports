# $FreeBSD$

PORTNAME=	aleph
PORTVERSION=	0.0.r.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXLIVE}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Engine including Omega and e-TeX features

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	texlive kpathsea web2c texmf formats fmtutil
TEXHASHDIRS=	${TEXMFDISTDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	\
	build-aux \
	libs/obsdcompat \
	libs/xpdf \
	texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=| ${TAR} -xf - -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE=	20120701
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/tex/plain/config/aleph.ini \
	texmf-dist/doc/aleph \
	texmf-dist/source/lambda \
	texmf-dist/tex/lambda
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OBSDCOMPAT_INCLUDES=-I${WRKSRC}/../../libs/obsdcompat
EXCLUDE_ENGINES= etex luatex pdftex mf mf-nowin ptex eptex uptex euptex xetex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-aleph \
		--enable-otangle \
		--disable-mp \
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
TEX_FORMATS=	aleph

MAN1=	ofm2opl.1 opl2ofm.1 ovf2ovp.1 ovp2ovf.1 aleph.1 otp2ocp.1 \
	outocp.1 mkocp.1 mkofm.1
MLINKS=	aleph.1 lamed.1 \
	dvicopy.1 odvicopy.1 \
	dvitype.1 odvitype.1 \
	tangle.1 otangle.1

NO_STAGE=	yes
pre-configure:
	for D in libs/obsdcompat libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>

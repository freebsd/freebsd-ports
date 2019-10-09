# $FreeBSD$

PORTNAME=	jadetex
PORTVERSION=	3.13
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150523-texmf
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX backend for Jade, DSSSL processor for SGML/XML documents

USES=		tar:xz
USE_TEX=	texmf pdftex xmltex fmtutil
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	texmf-dist/doc/otherformats/jadetex \
	texmf-dist/source/jadetex/base \
	texmf-dist/tex/jadetex/base
NO_BUILD=	yes
TEX_FORMATS=	jadetex

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>

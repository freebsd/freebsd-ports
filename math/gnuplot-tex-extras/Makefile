# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	5.2.6
CATEGORIES=	math graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	-tex-extras

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Extra files for Gnuplot TeX support

RUN_DEPENDS=	gnuplot:math/gnuplot

USE_TEX=	texmf
NO_BUILD=	yes
PLIST_FILES=	${TEX_FILES:S,^,${TEX_DIR}/,}

TEX_DIR=	${LOCALBASE}/${TEXMFDIR}/tex/latex/gnuplot
TEX_FILES=	gnuplot-lua-tikz.sty \
		gnuplot-lua-tikz-common.tex \
		gnuplot-lua-tikz.tex \
		t-gnuplot-lua-tikz.tex \
		gnuplot.cfg

do-install:
	@${MKDIR} ${STAGEDIR}${TEX_DIR}
	cd ${WRKSRC}/share/LaTeX && ${INSTALL_DATA} ${TEX_FILES} \
	    ${STAGEDIR}${TEX_DIR}

.include <bsd.port.mk>

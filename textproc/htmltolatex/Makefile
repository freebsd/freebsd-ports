# ex:ts=8
# New ports collection makefile for:	htmltolatex
# Date created:			Jan 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	htmltolatex
PORTVERSION=	1
PORTREVISION=	13
CATEGORIES=	textproc
MASTER_SITES=	http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to LaTeX to PDF Converter

LIB_DEPENDS=	GraphicsMagick++:${PORTSDIR}/graphics/GraphicsMagick

USE_BISON=	build
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu` CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -DUNIX \
		    `GraphicsMagick++-config --cppflags`"

post-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g'	\
	    -e 's,-lMagick,-lGraphicsMagick,g'	\
	    -e 's,-lstdc++,,'	\
	    -e 's,{quote},{tightquote},' ${WRKSRC}/QA/test1*_baseline*.tex \
		${WRKSRC}/${MAKEFILE}

post-build test:
	@if ! cd ${WRKSRC}/QA && ./run_tests;	\
	then	\
		${CAT} ${WRKSRC}/QA/*.diff;	\
		exit 1;	\
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/h2l ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/nmr.tex ${DATADIR}

.include <bsd.port.mk>

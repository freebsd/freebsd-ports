# Created by: ijliao
# $FreeBSD$

PORTNAME=	htmltolatex
PORTVERSION=	1
PORTREVISION=	17
CATEGORIES=	textproc
MASTER_SITES=	http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	HTML to LaTeX to PDF Converter

LIB_DEPENDS=	GraphicsMagick++:${PORTSDIR}/graphics/GraphicsMagick

USES=		bison
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	CXX="${CXX}" \
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
	${INSTALL_PROGRAM} ${WRKSRC}/h2l ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/nmr.tex ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	isaac
PORTVERSION=	4.2
PORTREVISION=	9
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}-cfd/${PORTNAME}-cfd/ISAAC%20Version%20${PORTVERSION}
DISTFILES=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}
DIST_SUBDIR=	isaac-cfd
EXTRACT_ONLY=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated Solution Algorithm for Arbitrary Configuration

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CPPFLAGS=-I.
USES=		fortran gmake

PLIST_FILES=	bin/isaac
PORTDOCS=	man.4_2.ps.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES OPTIMIZED_FFLAGS
OPTIMIZED_FFLAGS_DESC=	Use extra compiler (fortran) optimizations

DOCS_DISTFILES=	man.4_2.ps.gz
EXAMPLES_DISTFILES=	example_cases${EXTRACT_SUFX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_FFLAGS}
FFLAGS+=	-O2 -ffast-math
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+;' \
	${WRKSRC}/makefile
	${FIND} ${WRKSRC} -name "*.mk" -exec	\
		${REINPLACE_CMD} -e 's|SRC= $$(HOME)/ISAAC/src|SRC= ${WRKSRC}|; \
			s|$$(FFLAGS)|${FFLAGS} -I.|' {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isaac ${STAGEDIR}${PREFIX}/bin/isaac
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/example_cases${EXTRACT_SUFX} \
		-C ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

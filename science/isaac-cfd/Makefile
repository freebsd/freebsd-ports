# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	isaac
PORTVERSION=	4.2
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}-cfd/${PORTNAME}-cfd/ISAAC%20Version%20${PORTVERSION}
DISTFILES=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}
DIST_SUBDIR=	isaac-cfd
EXTRACT_ONLY=	${PORTNAME}src.4_2${EXTRACT_SUFX} ${PORTNAME}mk.4_2${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated Solution Algorithm for Arbitrary Configuration

NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_FLAGS+=	CPPFLAGS=-I.
USE_FORTRAN=	yes

PLIST_FILES+=	bin/isaac
PORTDOCS=	man.4_2.ps.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES OPTIMIZED_FFLAGS
OPTIMIZED_FFLAGS_DESC=	Use extra compiler (fortran) optimizations

DOCS_DISTFILES+=	man.4_2.ps.gz
EXAMPLES_DISTFILES+=	example_cases${EXTRACT_SUFX}

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+;' \
	${WRKSRC}/makefile
	${FIND} ${WRKSRC} -name "*.mk" -exec	\
		${REINPLACE_CMD} -e 's|SRC= $$(HOME)/ISAAC/src|SRC= ${WRKSRC}|; \
			s|$$(FFLAGS)|${FFLAGS} -I.|' {} \;

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_FFLAGS}
FFLAGS+=	-O2 -ffast-math
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isaac ${PREFIX}/bin/isaac
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/example_cases${EXTRACT_SUFX} \
		-C ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>

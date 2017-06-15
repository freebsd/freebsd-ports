# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	fasthenry
DISTVERSION=	3.0wr-021113
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/ LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multipole-accelerated inductance analysis program

BROKEN_aarch64=	Fails to link: missing sbrk

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
WRKSRC=		${WRKDIR}/fasthenry-3.0wr

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -Ee '/CFLAGS =/{s/=/+=/;s/-O[[:digit:]]*//;}' \
		${WRKSRC}/src/fasthenry/Makefile.default \
		${WRKSRC}/src/fasthenry/sparse/Makefile \
		${WRKSRC}/src/zbuf/Makefile.default
#minimal changes to fix the clang build (there should be a more thorough
#clean-up, to correct types of functions, remove implicit declarations, fix
#formatting, add missing returns, etc.)
	@${REINPLACE_CMD} -e 's,return;,return 0;,' \
		${WRKSRC}/src/fasthenry/barnoldi.c \
		${WRKSRC}/src/fasthenry/contact.c \
		${WRKSRC}/src/fasthenry/findpaths.c \
		${WRKSRC}/src/fasthenry/fillM.c \
		${WRKSRC}/src/fasthenry/hole.c \
		${WRKSRC}/src/fasthenry/induct.c \
		${WRKSRC}/src/fasthenry/joelself.c \
		${WRKSRC}/src/fasthenry/mulSetup.c \
		${WRKSRC}/src/fasthenry/read_tree.c
	@${REINPLACE_CMD} -Ee \
	'/^(AllocateBlockOfAllocationList|InitializeElementBlocks|RecordAllocation)/,/^\}/s/return;/return 0;/' \
		${WRKSRC}/src/fasthenry/sparse/spAllocate.c
	@${REINPLACE_CMD} -Ee \
	'/^(EnlargeMatrix|ExpandTranslationArrays|spcLinkRows)/,/^\}/s/return;/return 0;/' \
		${WRKSRC}/src/fasthenry/sparse/spBuild.c
	@${REINPLACE_CMD} -Ee \
	'/^(ComplexRowColElimination|CountMarkowitz|CreateInternalVectors|ExchangeColElements|ExchangeRowElements|ExchangeRowsAndCols|MarkowitzProducts|RealRowColElimination|UpdateMarkowitzNumbers|spcColExchange|spcRowExchange)/,/^\}/s/return;/return 0;/' \
		${WRKSRC}/src/fasthenry/sparse/spFactor.c
	@${REINPLACE_CMD} -Ee 's,^mul(Up|Down),void &,' \
		${WRKSRC}/src/fasthenry/mulDo.c
	@${REINPLACE_CMD} -e 's,^mulMatUp,void &,' \
		${WRKSRC}/src/fasthenry/mulMats.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fasthenry ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/zbuf ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${STAGEDIR}${DOCSDIR}/readme
	${CAT} ${WRKSRC}/doc/manual_*.ps > ${STAGEDIR}${DOCSDIR}/manual.ps
	${CAT} ${WRKSRC}/doc/nonuniform_manual_*.ps > ${STAGEDIR}${DOCSDIR}/nonuniform_manual.ps
	${INSTALL_DATA} ${WRKSRC}/doc/ms_thesis.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

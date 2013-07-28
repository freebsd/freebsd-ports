# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	fastcap
DISTVERSION=	2.0wr-011109
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Three-dimensional capacitance extraction program

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
WRKSRC =	${WRKDIR}/fastcap-2.0wr

BINFILES=	busgen capgen cubegen fastcap pipedgen pyragen

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,TYPE=other,TYPE=4,' \
		${WRKSRC}/config
	@${REINPLACE_CMD} -Ee '/CFLAGS =/{s/=/+=/;s/-O[[:digit:]]*//;}' \
		${WRKSRC}/src/Makefile.4
# Minimal changes to fix the Clang build (there should be a more thorough
# clean-up, to correct types of functions, remove implicit declarations, fix
# formatting, add missing returns, etc.)
	@${REINPLACE_CMD} -E -e 's,^mul(Up|Down),void &,' \
		${WRKSRC}/src/mulDo.c
	@${REINPLACE_CMD} -e 's,^mulMatUp,void &,' \
		${WRKSRC}/src/mulMats.c
	@${REINPLACE_CMD} -e 's,^static getnbrs,static void getnbrs,' \
		${WRKSRC}/src/mulSetup.c
# Change "cd foo ; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
	@${REINPLACE_CMD} -E 's,cd (.+) ; (\$$\(MAKE\)),\2 -C \1,' \
		${WRKSRC}/Makefile
# Avoid clashing of generated temporary files, crucial for parallel builds
	@${REINPLACE_CMD} -e 's,temp\.out,$$@.&,' ${WRKSRC}/src/Makefile*

do-install:
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/bin/,} ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${DOCSDIR}/readme
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*
.endif

.include <bsd.port.mk>

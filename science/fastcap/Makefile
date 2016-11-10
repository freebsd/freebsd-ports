# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	fastcap
DISTVERSION=	2.0wr-011109
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/ LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three-dimensional capacitance extraction program

LICENSE=	FASTCAP
LICENSE_NAME=	fastcap license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

BROKEN_aarch64=	Fails to link: missing sbrk

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
WRKSRC=		${WRKDIR}/fastcap-2.0wr

BINFILES=	busgen capgen cubegen fastcap pipedgen pyragen

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${HEAD} -32 ${WRKSRC}/src/direct.c | ${TAIL} +2 > ${WRKSRC}/LICENSE

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
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/bin/,} ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${STAGEDIR}${DOCSDIR}/readme
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*

.include <bsd.port.mk>

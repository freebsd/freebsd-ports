PORTNAME=	fastcap
DISTVERSION=	2.0wr-010524
PORTEPOCH=	1
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three-dimensional capacitance extraction program
WWW=		https://www.rle.mit.edu/cpg/research_codes.htm

LICENSE=	FASTCAP
LICENSE_NAME=	fastcap license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

USES=		gmake
USE_GCC=	yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	config

# Fix build with clang11
CFLAGS+=	-fcommon
# Use malloc
CFLAGS+=	-DNO_SBRK

BINARY_ALIAS=	gcc=gcc${GCC_DEFAULT} make=gmake

WRKSRC=		${WRKDIR}/fastcap-2.0wr

BINFILES=	busgen capgen cubegen fastcap pipedgen pyragen

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${HEAD} -32 ${WRKSRC}/src/direct.c | ${TAIL} +2 > ${WRKSRC}/LICENSE

post-patch:
	@${REINPLACE_CMD} -e 's,TYPE=other,TYPE=4,' ${WRKSRC}/config
# Change "cd foo ; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
	@${REINPLACE_CMD} -E 's,cd (.+) ; (\$$\(MAKE\)),\2 -C \1,' \
		${WRKSRC}/Makefile
# Avoid clashing of generated temporary files, crucial for parallel builds
	@${REINPLACE_CMD} -e 's,temp\.out,$$@.&,' ${WRKSRC}/src/Makefile*

do-install:
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/bin/,} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${STAGEDIR}${DOCSDIR}/readme
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

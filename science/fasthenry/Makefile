PORTNAME=	fasthenry
DISTVERSION=	3.0wr-031424
PORTREVISION=	1
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multipole-accelerated inductance analysis program
WWW=		https://www.rle.mit.edu/cpg/research_codes.htm

LICENSE=	MIT

USES=		gmake

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		freebsd

# Fix build with clang11
CFLAGS+=	-fcommon
# Use malloc
CFLAGS+=	-DNO_SBRK

BINARY_ALIAS=	make=gmake

WRKSRC=		${WRKDIR}/fasthenry-3.0wr

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -Ee '/CFLAGS =/{s/=/+=/;}' \
	${WRKSRC}/src/sparse/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fasthenry ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/zbuf ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${STAGEDIR}${DOCSDIR}/readme
	${INSTALL_DATA} ${WRKSRC}/doc/nonuniform_manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fasthenry_manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ms_thesis.pdf ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	prng
DISTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://statistik.wu-wien.ac.at/software/prng/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable, high-performance ANSI-C pseudorandom number generators

LICENSE=	GPLv2

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
INFO=		prng
PLIST_FILES=	include/prng.h lib/libprng.a
PORTDOCS=	prng.dvi prng.pdf prng.ps prng.txt
PORTEXAMPLES=	Makefile pairs.c tuples.c

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} \
		${STAGEDIR}${EXAMPLESDIR}

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>

PORTNAME=	otter
PORTVERSION=	3.3f
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www-unix.mcs.anl.gov/AR/otter/dist33/

MAINTAINER=	wollman@FreeBSD.org
COMMENT=	Theorem prover and finite model searcher

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/Legal

USES=		shebangfix
SHEBANG_FILES=	examples-mace2/Perl-examples/commute4_filter

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PROGRAMS=	anldp mace2 otter
PORTDOCS=	README anldp.pdf mace2.pdf otter33.pdf

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_JOBS_UNSAFE=	yes

post-patch:
# Change "cd foo && $(MAKE)" into "$(MAKE) -C foo"
	@${REINPLACE_CMD} -E 's,cd (.+) && (\$$\(MAKE\)),\2 -C \1, ; \
		s,CC=gcc,,' ${WRKSRC}/Makefile
# Add missing depedencies for install targets
	@${REINPLACE_CMD} -e 's,^install:,& otter,' \
		${WRKSRC}/source/Makefile
	@${REINPLACE_CMD} -e 's,^install:,& mace2 anldp,' \
		${WRKSRC}/mace2/Makefile

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/bin/,} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/documents/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${PREFIX}/share/examples/mace2
	(cd ${WRKSRC}/examples; ${PAX} -rw . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/examples-mace2; ${PAX} -rw . ${STAGEDIR}${PREFIX}/share/examples/mace2)

.include <bsd.port.mk>

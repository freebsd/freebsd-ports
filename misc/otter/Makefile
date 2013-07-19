# Created by: Garrett Wollman <wollman@FreeBSD.org>
# $FreeBSD$

PORTNAME=	otter
PORTVERSION=	3.3f
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www-unix.mcs.anl.gov/AR/otter/dist33/

MAINTAINER=	wollman@FreeBSD.org
COMMENT=	Theorem prover and finite model searcher

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PROGRAMS=	anldp mace2 otter
PORTDOCS=	README anldp.pdf mace2.pdf otter33.pdf

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

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
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/bin/,} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/documents/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR} ${PREFIX}/share/examples/mace2
	(cd ${WRKSRC}/examples; ${PAX} -rw . ${EXAMPLESDIR})
	(cd ${WRKSRC}/examples-mace2; ${PAX} -rw . ${PREFIX}/share/examples/mace2)
.endif

.include <bsd.port.mk>

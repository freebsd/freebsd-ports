# New ports collection makefile for:	otter
# Date created:         2006-02-04
# Whom:                 wollman
#
# $FreeBSD$
#

PORTNAME=	otter
PORTVERSION=	3.3f
CATEGORIES=	misc
MASTER_SITES=	http://www-unix.mcs.anl.gov/AR/otter/dist33/

MAINTAINER=	wollman@FreeBSD.org
COMMENT=	A theorem prover and finite model searcher

PROGRAMS=	anldp mace2 otter
PORTDOCS=	README anldp.pdf mace2.pdf otter33.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=$$(CC) CFLAGS="$$(CFLAGS)"|g' \
		${WRKSRC}/Makefile

do-install:
.for prog in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${PREFIX}/bin
.endfor
.if !defined{NOPORTDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/documents/${doc} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${PREFIX}/share/examples/mace2
	(cd ${WRKSRC}/examples; ${PAX} -rw . ${EXAMPLESDIR})
	(cd ${WRKSRC}/examples-mace2; ${PAX} -rw . ${PREFIX}/share/examples/mace2)

.include <bsd.port.mk>

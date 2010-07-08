# New ports collection makefile for:	prng
# Date created:		16 Feb. 2010
# Whom:			bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prng
DISTVERSION=	3.0.2
CATEGORIES=	math
MASTER_SITES=	http://statistik.wu-wien.ac.at/software/prng/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Portable, high-performance ANSI-C pseudorandom number generators

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
INFO=	prng
PLIST_FILES=	include/prng.h lib/libprng.a
PORTDOCS=	prng.dvi prng.pdf prng.ps prng.txt
PORTEXAMPLES=	Makefile pairs.c tuples.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _d in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${_d} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for _e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${_e} ${EXAMPLESDIR}
.endfor
.endif

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

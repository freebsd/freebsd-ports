# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prng
DISTVERSION=	3.0.2
CATEGORIES=	math
MASTER_SITES=	http://statistik.wu-wien.ac.at/software/prng/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable, high-performance ANSI-C pseudorandom number generators

LICENSE=	GPLv2

CFLAGS+=	-fgnu89-inline
GNU_CONFIGURE=	yes
INFO=		prng
PLIST_FILES=	include/prng.h lib/libprng.a
PORTDOCS=	prng.dvi prng.pdf prng.ps prng.txt
PORTEXAMPLES=	Makefile pairs.c tuples.c

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for _d in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${_d} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for _e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${_e} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>

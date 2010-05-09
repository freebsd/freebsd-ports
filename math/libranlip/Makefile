# New ports collection makefile for:	libranlip
# Date created:		6 Feb 2010
# Whom:			bf <bf1783@gmail.com>
# $FreeBSD$

PORTNAME=	libranlip
DISTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://www.deakin.edu.au/~gleb/

MAINTAINER=	bf1783@gmail.com
COMMENT=	A random variate generator for Lipschitz-continuous densities

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=	ranlip
PLIST_FILES=	include/ranlip.h include/ranlipdist.h include/ranlipproc.h lib/libranlip.so.${PORTVERSION} \
		lib/libranlip.so.${PORTVERSION:R} lib/libranlip.la lib/libranlip.a
PORTDOCS=	ranlip.ps
PORTEXAMPLES=	makefile ranliptest.cpp ranliptestproc.cpp
TESTPROGS=	static_example static_example2 static_example3 shared_example

.include <bsd.port.pre.mk>

post-install:
	${LN} -s ${PREFIX}/lib/libranlip.so.${PORTVERSION} ${PREFIX}/lib/libranlip.so.${PORTVERSION:R}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/ranlip.ps ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for _file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${_file} ${EXAMPLESDIR}
.endfor
.endif

test: build
	@(cd ${WRKSRC}/examples; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} all)
.for _prog in ${TESTPROGS}
	@(cd ${WRKSRC}/examples && ./${_prog})
.endfor

.if ${OSVERSION} < 700000
BROKEN=		fails to build
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	FastHenry
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fasthenry
DISTVERSION=	3.0wr-011109
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A multipole-accelerated inductance analysis program

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
WRKSRC =	${WRKDIR}/fasthenry-3.0wr

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =, CFLAGS +=,' \
		${WRKSRC}/src/fasthenry/Makefile.default \
		${WRKSRC}/src/zbuf/Makefile.default

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/fasthenry ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/zbuf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${DOCSDIR}/readme
	${CAT} ${WRKSRC}/doc/manual_*.ps > ${DOCSDIR}/manual.ps
	${CAT} ${WRKSRC}/doc/nonuniform_manual_*.ps > ${DOCSDIR}/nonuniform_manual.ps
	${INSTALL_DATA} ${WRKSRC}/doc/ms_thesis.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

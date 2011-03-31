# New ports collection makefile for:	FastCap
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fastcap
DISTVERSION=	2.0wr-011109
CATEGORIES=	science cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A three-dimensional capacitance extraction program

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config
WRKSRC =	${WRKDIR}/fastcap-2.0wr

BINFILES=	busgen capgen cubegen fastcap pipedgen pyragen

post-patch:
	@${REINPLACE_CMD} -e 's,TYPE=other,TYPE=4,' \
		${WRKSRC}/config
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=,' \
		${WRKSRC}/src/Makefile.4

do-install:
.for b in ${BINFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${b} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${DOCSDIR}/readme
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*
.endif

.include <bsd.port.mk>

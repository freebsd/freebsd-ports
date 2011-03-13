# New ports collection makefile for:	FastCap
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fastcap
DISTVERSION=	${P_VERSION}wr
CATEGORIES=	science cad
MASTER_SITES=	ftp://ftp.srware.com/pub/	\
		http://www.wrcad.com/ftp/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A three-dimensional capacitance extraction program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

P_VERSION=	2.0

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config

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
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CAT} ${WRKSRC}/README ${WRKSRC}/README.mit > ${DOCSDIR}/readme
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*
.endif

.include <bsd.port.mk>

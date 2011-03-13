# New ports collection makefile for:	FastHenry
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fasthenry
DISTVERSION=	${P_VERSION}wr
CATEGORIES=	science cad
MASTER_SITES=	ftp://ftp.srware.com/pub/	\
		http://www.wrcad.com/ftp/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multipole-accelerated inductance analysis program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

P_VERSION=	3.0

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config

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
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

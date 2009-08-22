# New ports collection makefile for:	dbacl
# Date created:		2003-10-30
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	dbacl
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Digramic Bayesian classifier

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes

PROGRAMS=	bayesol dbacl mailinspect hmine hypex
SCRIPTS=	mailcross mailtoe mailfoot
MAN1=		bayesol.1 dbacl.1 mailcross.1 mailinspect.1 mailtoe.1 mailfoot.1
DOCS=		AUTHORS ChangeLog README doc/dbacl.ps \
		doc/email.html doc/tutorial.html doc/costs.ps
EXAMPLES=	sample*.txt japanese.txt example*.risk toy.risk prop.pl

pre-install:
	@cd ${WRKSRC}/src && \
	${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' \
		${SCRIPTS}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	cd ${WRKSRC}/man && \
		${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1 && \
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbacl
PORTVERSION=	1.14.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Digramic Bayesian classifier

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

PROGRAMS=	bayesol dbacl mailinspect hmine hypex
SCRIPTS=	mailcross mailtoe mailfoot
MAN=		bayesol.1 dbacl.1 mailcross.1 mailinspect.1 mailtoe.1 mailfoot.1
PLIST_FILES=	${PROGRAMS:S,^,bin/,} ${SCRIPTS:S,^,bin/,} ${MAN:S,^,man/man1/,:S,$,.gz,}
DOCS=		AUTHORS ChangeLog README doc/dbacl.ps \
		doc/email.html doc/tutorial.html doc/costs.ps
PORTDOCS=	${DOCS:T}
PORTEXAMPLES=	sample*.txt japanese.txt example*.risk toy.risk prop.pl

pre-install:
	@cd ${WRKSRC}/src && \
	${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' \
		${SCRIPTS}

do-install:
	cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && \
		${INSTALL_MAN} ${MAN} ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

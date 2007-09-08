# New ports collection makefile for:	qmHandle
# Date created:				17 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	qmhandle
PORTVERSION=	1.3.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

USE_QMAIL_RUN=	yes

NO_BUILD=	yes
USE_PERL5=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/qmHandle
PORTDOCS=	HISTORY README

post-patch:
	@${PERL} -pi -e 's,^#!/usr/bin/perl,#!${PERL},; \
		s,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/qmHandle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

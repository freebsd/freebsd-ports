# New ports collection makefile for:	qmHandle
# Date created:				17 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	qmHandle
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qmhandle
DISTNAME=	qmhandle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

USE_QMAIL_RUN=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=         requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

post-patch:
	@${PERL} -pi -e 's,^#!/usr/bin/perl,#!${PERL},; \
		s,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/qmHandle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in HISTORY README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

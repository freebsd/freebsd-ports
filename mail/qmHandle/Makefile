# New ports collection makefile for:	qmHandle
# Date created:				17 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	qmHandle
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qmhandle
DISTNAME=	qmhandle-${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-qstat:${PORTSDIR}/mail/qmail

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

.if exists(${LOCALBASE}/qmail/bin/qmail-qstat)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=         Port requires perl 5.6.1 or later. Install lang/perl5 then try again
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

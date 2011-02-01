# New ports collection makefile for:	formication
# Date created:		2004-01-25
# Whom:			Michael Ranner <mranner@inode.at>
#
# $FreeBSD$
#

PORTNAME=	formication
PORTVERSION=	1.0.b1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.ranner.eu/stuff/ \
		http://home.bluelife.at/ports/distfiles/

MAINTAINER=	michael@ranner.eu
COMMENT=	Formular processing tool written in perl

USE_APACHE=	1.3+
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	BLURB COPYING feedback.fcn feedback.html formication.txt
PLIST_FILES=	www/cgi-bin/formication.pl
SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 13
PLIST_DIRSTRY=	www/cgi-bin
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/local/bin/perl,#!${PERL},g" \
		-e "s,authorized_uid = 1031;,authorized_uid = ${WWWOWN};,g" \
		${WRKSRC}/formication.pl

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/formication.pl ${PREFIX}/www/cgi-bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.	for i in ${PORTDOCS}
	  @${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.	endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

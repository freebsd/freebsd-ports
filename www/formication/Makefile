# New ports collection makefile for:	formication
# Date created:		2004-01-25
# Whom:			Michael Ranner <mranner@inode.at>
#
# $FreeBSD$
#

PORTNAME=	formication
PORTVERSION=	1.0.b1
CATEGORIES=	www
MASTER_SITES=	http://www.villainy.com/downloads/ \
		http://www.ranner.jawa.at/stuff/
DISTNAME=	${PORTNAME}

MAINTAINER=	michael@ranner.eu
COMMENT=	Formular processing tool written in perl

CGI_UID?=	www

PKGMESSAGE=	${WRKDIR}/pkg-message
USE_APACHE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	BLURB COPYING feedback.fcn feedback.html formication.txt
PLIST_FILES=	www/cgi-bin/formication.pl

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/local/bin/perl,#!${PERL},g" \
		-e "s,authorized_uid = 1031;,authorized_uid = ${CGI_UID};,g" \
		${WRKSRC}/formication.pl

do-install:
	@${INSTALL_DATA} ${WRKSRC}/formication.pl ${PREFIX}/www/cgi-bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.	for i in ${PORTDOCS}
	  @${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif

pre-install:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|g' <${.CURDIR}/pkg-message >${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

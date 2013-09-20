# Created by: Michael Ranner <mranner@inode.at>
# $FreeBSD$

PORTNAME=	formication
PORTVERSION=	1.0.b1
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.ranner.eu/stuff/ \
		http://home.bluelife.at/ports/distfiles/

MAINTAINER=	michael@ranner.eu
COMMENT=	Formular processing tool written in perl

USES=		perl5
USE_APACHE_RUN=	22+
USE_PERL5=	run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	BLURB COPYING feedback.fcn feedback.html formication.txt
PLIST_FILES=	www/cgi-bin/formication.pl
SUB_FILES+=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PLIST_DIRSTRY=	www/cgi-bin

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

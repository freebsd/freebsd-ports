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

USES=		apache:run,2.2+ perl5
USE_PERL5=	run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	BLURB COPYING feedback.fcn feedback.html formication.txt
PLIST_FILES=	www/cgi-bin/formication.pl
SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/usr/local/bin/perl,#!${PERL},g" \
		-e "s,authorized_uid = 1031;,authorized_uid = ${WWWOWN};,g" \
		${WRKSRC}/formication.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/formication.pl ${STAGEDIR}${PREFIX}/www/cgi-bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
.	for i in ${PORTDOCS}
	  @${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.	endfor

.include <bsd.port.mk>

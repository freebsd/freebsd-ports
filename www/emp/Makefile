# New ports collection makefile for:    emp
# Date created:                         Oct 20, 2003
# Whom:                                 Allan Bowhill <abowhill@blarg.net>
#
# $FreeBSD$
#

PORTNAME=	emp
PORTVERSION=	0.94
CATEGORIES=	www
MASTER_SITES=	http://home.blarg.net/~abowhill/ \
		ftp://userftp.blarg.net/users/abowhill/

MAINTAINER=	allanb@u.washington.edu
COMMENT=	CGI program to deliver hierarchy of web links

HAS_CONFIGURE=	yes

CGI_BIN=	${PREFIX}/www/cgi-bin

do-install:
	${MKDIR} ${CGI_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/emp ${CGI_BIN}/emp.cgi
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Samples/links.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Samples/emp.cfg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

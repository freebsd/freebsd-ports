# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	2.1.6
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/

MAINTAINER=	petef@FreeBSD.org

USE_PYTHON=	yes

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's!/usr/lib/getmail!${DATADIR}!; \
		s!`which python`!${PYTHON_CMD}!' ${WRKSRC}/getmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@${MKDIR} ${PREFIX}/share/examples/getmail
	${INSTALL_DATA} ${WRKSRC}/getmailrc-example \
		${PREFIX}/share/examples/getmail
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG docs.txt faq.txt getmail.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
